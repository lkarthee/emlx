ifndef MIX_APP_PATH
	MIX_APP_PATH=$(shell pwd)
endif

PRIV_DIR = $(MIX_APP_PATH)/priv
NIF_SO = $(PRIV_DIR)/mlx_nif.so
NIF_SO_REL = $(NIF_SO:$(shell pwd)/%=%)
THIRD_PARTY_DIR = $(shell pwd)/3rd_party
MLX_SRC = $(THIRD_PARTY_DIR)/mlx-c
UNAME_S = $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	MLX_COMMON_LIB = $(PRIV_DIR)/lib/libmlx.dylib
endif

C_SRC = $(shell pwd)/c_src
C_SRC_REL = c_src
ifdef CC_PRECOMPILER_CURRENT_TARGET
	ifdef ($(findstring darwin, $(CC_PRECOMPILER_CURRENT_TARGET)), darwin)
		ifeq ($(findstring aarch64, $(CC_PRECOMPILER_CURRENT_TARGET)), aarch64)
			CMAKE_CONFIGURE_FLAGS=-D CMAKE_OSX_ARCHITECTURES=arm64
		else
			CMAKE_CONFIGURE_FLAGS=-D CMAKE_OSX_ARCHITECTURES=x86_64
		endif
	endif
endif

ifdef CMAKE_TOOLCHAIN_FILE
	CMAKE_CONFIGURE_FLAGS=-D CMAKE_TOOLCHAIN_FILE="$(CMAKE_TOOLCHAIN_FILE)"
endif

CMAKE_BUILD_TYPE ?= Release
DEFAULT_JOBS ?= 1
CMAKE_MLX_BUILD_DIR = $(MIX_APP_PATH)/cmake_mlx
CMAKE_MLX_OPTIONS ?= ""
CMAKE_MLX_NIF_BUILD_DIR = $(MIX_APP_PATH)/cmake_mlx_nif
CMAKE_MLX_NIF_OPTIONS ?= ""
MAKE_BUILD_FLAGS ?= -j$(DEFAULT_JOBS)

.DEFAULT_GLOBAL := build

build: $(NIF_SO_REL)
	@echo > /dev/null

clean: 
	@rm -rf "$(PRIV_DIR)"

priv_dir:
	@ if [ ! -e "$(PRIV_DIR)" ]; then \
		mkdir -p "$(PRIV_DIR)" ; \
	fi

mlx: priv_dir
	@ if [ ! -f "$(MLX_COMMON_LIB)" ]; then \
		mkdir -p "$(CMAKE_MLX_BUILD_DIR)" && \
		cd "$(CMAKE_MLX_BUILD_DIR)" && \
		cmake --no-warn-unused-cli \
		-DCMAKE_BUILD_TYPE="$(CMAKE_BUILD_TYPE)" \
		-DCMAKE_INSTALL_PREFIX="$(PRIV_DIR)" \
		$(CMAKE_CONFIGURE_FLAGS) $(CMAKE_MLX_OPTIONS) "$(MLX_SRC)" && \
		cmake --build . --target install -j ; \
	fi

# $(C_SRC_REL)/mlx_nif_resource.hpp 

$(NIF_SO_REL): priv_dir mlx $(C_SRC_REL)/mlx_nif.cpp $(C_SRC_REL)/nif_utils.cpp
	@ mkdir -p "$(CMAKE_MLX_NIF_BUILD_DIR)" && \
	cd "$(CMAKE_MLX_NIF_BUILD_DIR)" && \
	cmake --no-warn-unused-cli \
		-D CMAKE_BUILD_TYPE="$(CMAKE_BULID_TYPE)" \
		-D C_SRC="$(C_SRC)" \
		-D MLX_SRC="$(MLX_SRC)" \
		-D MIX_APP_PATH="$(MIX_APP_PATH)" \
		-D PRIV_DIR="$(PRIV_DIR)" \
		-D ERTS_INCLUDE_DIR="$(ERTS_INCLUDE_DIR)" \
		$(CMAKE_CONFIGURE_FLAGS) $(CMAKE_MLX_NIF_OPTIONS) "$(shell pwd)" && \
	make "$(MAKE_BUILD_FLAGS)" && \
	cp "$(CMAKE_MLX_NIF_BUILD_DIR)/mlx_nif.so" "$(NIF_SO)"
