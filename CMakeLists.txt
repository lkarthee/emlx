cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(mlx_nif C CXX)

if(NOT DEFINED PRIV_DIR)
    if(DEFINED MIX_APP_PATH AND NOT "${MIX_APP_PATH}" STREQUAL "")
      set(PRIV_DIR "${MIX_APP_PATH}/priv")
    else()
        set(PRIV_DIR "${CMAKE_CURRENT_SOURCE_DIR}/priv")
    endif()
endif()
message(STATUS "Using PRIV_DIR: ${PRIV_DIR}")

if(DEFINED ERTS_INCLUDE_DIR AND NOT "${ERTS_INCLUDE_DIR}" STREQUAL "")
    set(ERTS_INCLUDE_DIR "${ERTS_INCLUDE_DIR}")
else()
    set(ERTS_INCLUDE_DIR_ONE_LINER "erl -noshell -eval \"io:format('~ts/erts-~ts/include/', [code:root_dir(), erlang:system_info(version)]), halt().\"")
    execute_process(COMMAND bash -c "${ERTS_INCLUDE_DIR_ONE_LINER}" OUTPUT_VARIABLE ERTS_INCLUDE_DIR)
    set(ERTS_INCLUDE_DIR "${ERTS_INCLUDE_DIR}")
endif()
message(STATUS "Using ERTS_INCLUDE_DIR: ${ERTS_INCLUDE_DIR}")

if(UNIX AND APPLE)
    set(CMAKE_SHARED_LINKER_FLAGS "-flat_namespace -undefined dynamic_lookup")
endif()

set(CMAKE_CXX_STANDARD 17)

message(STATUS "CMAKE_TOOLCHAIN_FILE: ${CMAKE_TOOLCHAIN_FILE}")

find_package(mlx REQUIRED PATHS "${PRIV_DIR}/" NO_DEFAULT_PATH)
find_package(mlxc REQUIRED PATHS "${PRIV_DIR}/" NO_DEFAULT_PATH)
include_directories("${PRIV_DIR}/include")

set(SOURCE_FILES
    "${C_SRC}/nif_utils.cpp"
    "${C_SRC}/mlx_nif.cpp"
)

include_directories("${ERTS_INCLUDE_DIR}")
include_directories("${MLX_SRC}")

add_library(mlx_nif SHARED
    ${SOURCE_FILES}
)
target_link_libraries(mlx_nif PUBLIC mlxc)
install(
    TARGETS mlx_nif
    RUNTIME DESTINATION "${PRIV_DIR}"
)

set_target_properties(mlx_nif PROPERTIES PREFIX "")
if(NOT WIN32)
    set_target_properties(mlx_nif PROPERTIES SUFFIX ".so")
endif()
set_target_properties(mlx_nif PROPERTIES
    INSTALL_RPATH_USE_LINK_PATH TRUE
    BUILD_WITH_INSTALL_RPATH TRUE
)

if(UNIX AND APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-reorder-ctor")
    set(CMAKE_SHARED_LINKER_FLAGS "-flat_namespace -undefined dynamic_lookup")
    set_target_properties(mlx_nif PROPERTIES INSTALL_RPATH "@loader_path/lib")
endif()

if(NOT WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g3")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
    endif()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-function -Wno-sign-compare -Wno-unused-parameter -Wno-missing-field-initializers -Wno-deprecated-declarations")
endif()