#include <erl_nif.h>
#include "nif_utils.hpp"
#include "mlx_nif_resource.hpp"

#include "mlx/c/mlx.h"

template<> ErlNifResourceType * NifRes<mlx_device>::type = nullptr;
template<> ErlNifResourceType * NifRes<mlx_stream>::type = nullptr;
template<> ErlNifResourceType * NifRes<mlx_array>::type = nullptr;

static ERL_NIF_TERM hello(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  return erlang::nif::make_binary(env, "Hello world!");
  //enif_make_string(env, "Hello world!", ERL_NIF_LATIN1);
}

// array

static ERL_NIF_TERM array_from_bool(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  using res_type = NifRes<mlx_array>;

  bool value;
  if (!erlang::nif::get(env, argv[0], &value)) {
      return enif_make_badarg(env);
  }

  ERL_NIF_TERM error{};
  auto array = res_type::allocate_resource(env, error);
  array->val = mlx_array_from_bool(value);
  ERL_NIF_TERM ret = array->make_resource(env);
  return erlang::nif::ok(env, ret);
}

static ERL_NIF_TERM array_itemsize(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  using res_type = NifRes<mlx_array>;

  ERL_NIF_TERM error{};
  res_type * array = nullptr;
  if ((array = res_type::get_resource(env, argv[0], error)) == nullptr) {
    return error;
  }
  auto size = static_cast<uint64_t>(mlx_array_itemsize(array->val));
  return erlang::nif::make(env, size);
}

static ERL_NIF_TERM array_nbytes(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  using res_type = NifRes<mlx_array>;

  ERL_NIF_TERM error{};
  res_type * array = nullptr;
  if ((array = res_type::get_resource(env, argv[0], error)) == nullptr) {
    return error;
  }
  auto size = static_cast<uint64_t>(mlx_array_nbytes(array->val));
  return erlang::nif::make(env, size);
}

static ERL_NIF_TERM array_ndim(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  using res_type = NifRes<mlx_array>;

  ERL_NIF_TERM error{};
  res_type * array = nullptr;
  if ((array = res_type::get_resource(env, argv[0], error)) == nullptr) {
    return error;
  }
  auto size = static_cast<uint64_t>(mlx_array_ndim(array->val));
  return erlang::nif::make(env, size);
}

static ERL_NIF_TERM array_shape(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  using res_type = NifRes<mlx_array>;

  ERL_NIF_TERM error{};
  res_type * array = nullptr;
  if ((array = res_type::get_resource(env, argv[0], error)) == nullptr) {
    return error;
  }
  auto ndim = mlx_array_ndim(array->val);
  auto data = mlx_array_shape(array->val);
  ERL_NIF_TERM out{};
  erlang::nif::make_i64_list_from_c_array(env, ndim, data, out);
  return out;
}

static ERL_NIF_TERM array_size(ErlNifEnv* env, int argc, const  ERL_NIF_TERM argv[])
{
  using res_type = NifRes<mlx_array>;

  ERL_NIF_TERM error{};
  res_type * array = nullptr;
  if ((array = res_type::get_resource(env, argv[0], error)) == nullptr) {
    return error;
  }
  auto size = static_cast<uint64_t>(mlx_array_size(array->val));
  return erlang::nif::make(env, size);
}

// random

static ERL_NIF_TERM random_key(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  uint64_t seed;
  if (!erlang::nif::get(env, argv[0], &seed)) {
      return enif_make_badarg(env);
  }
  mlx_random_key(seed);

  return erlang::nif::atom(env, "nil");
}

static ERL_NIF_TERM random_seed(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  uint64_t seed;
  if (!erlang::nif::get(env, argv[0], &seed)) {
      return enif_make_badarg(env);
  }
  mlx_random_seed(seed);

  return erlang::nif::atom(env, "nil");
}

// device

static ERL_NIF_TERM device_new(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  using res_type = NifRes<mlx_device>;
  std::string type;
  if (!erlang::nif::get(env, argv[0], type)) {
      return enif_make_badarg(env);
  }
  int index;
  if (!erlang::nif::get(env, argv[1], &index)) {
      return enif_make_badarg(env);
  }
  ERL_NIF_TERM error{};
  auto device = res_type::allocate_resource(env, error);
  device->val = mlx_device_new(type == "cpu" ? MLX_CPU : MLX_GPU, index);
  ERL_NIF_TERM ret = device->make_resource(env);
  return erlang::nif::ok(env, ret);
}


static ERL_NIF_TERM set_default_device(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  return erlang::nif::atom(env, "nil");
}

static ERL_NIF_TERM device_get_type(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  using res_type = NifRes<mlx_device>;

  ERL_NIF_TERM error{};
  res_type * device = nullptr;
  if ((device = res_type::get_resource(env, argv[0], error)) == nullptr) {
    return error;
  }
  auto data = mlx_device_get_type(device->val);
  if(data == MLX_CPU)
  {
    return erlang::nif::atom(env, "cpu");  
  }
  return erlang::nif::atom(env, "gpu");
}

static ERL_NIF_TERM default_device(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  using res_type = NifRes<mlx_device>;
  ERL_NIF_TERM error{};
  auto device = res_type::allocate_resource(env, error);
  device->val = mlx_default_device();
  ERL_NIF_TERM ret = device->make_resource(env);
  return erlang::nif::ok(env, ret);
}

// metal

static ERL_NIF_TERM metal_get_active_memory(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  return erlang::nif::make(env, static_cast<uint64_t>( mlx_metal_get_active_memory() ));
}

static ERL_NIF_TERM metal_get_cache_memory(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  return erlang::nif::make(env, static_cast<uint64_t>( mlx_metal_get_cache_memory() ));
}

static ERL_NIF_TERM metal_get_peak_memory(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  return erlang::nif::make(env, static_cast<uint64_t>( mlx_metal_get_peak_memory() ));
}

static ERL_NIF_TERM metal_is_available(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  return erlang::nif::make(env, mlx_metal_is_available());
}

static ERL_NIF_TERM metal_set_cache_limit(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{

  unsigned long limit;
  if (!erlang::nif::get(env, argv[0], &limit)) {
      return enif_make_badarg(env);
  }

  size_t result = mlx_metal_set_cache_limit(limit);
  
  return erlang::nif::make(env, static_cast<uint64_t>(result));
}

static ERL_NIF_TERM metal_set_memory_limit(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  unsigned long limit;
  if (!erlang::nif::get(env, argv[0], &limit)) {
      return enif_make_badarg(env);
  }
  bool relaxed;
  if (!erlang::nif::get(env, argv[1], &relaxed)) {
      return enif_make_badarg(env);
  }

  size_t result = mlx_metal_set_memory_limit(limit, relaxed);

  return erlang::nif::make(env, static_cast<uint64_t>(result));
}

static ErlNifFunc nif_funcs[] =
{
  {"hello", 0, hello},

  // array
  {"array_from_bool", 1, array_from_bool},
  {"array_itemsize", 1, array_itemsize},
  {"array_shape", 1, array_shape},
  {"array_size", 1, array_size},
  {"array_nbytes", 1, array_nbytes},
  {"array_ndim", 1, array_ndim},

  // random
  {"random_key", 1, random_key},
  {"random_seed", 1, random_seed},

  // stream
  // {"stream_new", 2, stream_new},
  // {"stream_new_on_device", 1, stream_new_on_device},
  // {"stream_equal", 2, stream_equal},
  // {"default_stream", 1, default_stream},
  // {"set_default_stream", 1, set_default_stream},

  // device
  {"device_new", 2, device_new},
  {"device_get_type", 1, device_get_type},
  {"default_device", 0, default_device},
  {"set_default_device", 1, set_default_device},

  // string
  // {"string_new", 1, string_new},
  // {"string_data", 1, string_data},

  // metal
  {"metal_get_active_memory", 0, metal_get_active_memory},
  {"metal_get_cache_memory", 0, metal_get_cache_memory},
  {"metal_get_peak_memory", 0, metal_get_peak_memory},
  {"metal_is_available", 0, metal_is_available},
  {"metal_set_cache_limit", 1, metal_set_cache_limit},
  {"metal_set_memory_limit", 2, metal_set_memory_limit}
};

static int on_load(ErlNifEnv *env, void **, ERL_NIF_TERM) {
  ErlNifResourceType *rt;

  {
    using res_type = NifRes<mlx_array>;
    rt = enif_open_resource_type(env, "Elixir.Mlx.Nif", "NifResMlxArray", destruct_mlx_array_resource, ERL_NIF_RT_CREATE, NULL);
    if (!rt) return -1;
    res_type::type = rt;
  }

  {
    using res_type = NifRes<mlx_device>;
    rt = enif_open_resource_type(env, "Elixir.Mlx.Nif", "NifResMlxDevice", destruct_mlx_device_resource, ERL_NIF_RT_CREATE, NULL);
    if (!rt) return -1;
    res_type::type = rt;
  }

  {
    using res_type = NifRes<mlx_stream>;
    rt = enif_open_resource_type(env, "Elixir.Mlx.Nif", "NifResMlxStream", destruct_mlx_stream_resource, ERL_NIF_RT_CREATE, NULL);
    if (!rt) return -1;
    res_type::type = rt;
  }

  return 0;
}

static int on_reload(ErlNifEnv *, void **, ERL_NIF_TERM) {
  return 0;
}

static int on_upgrade(ErlNifEnv *, void **, void **, ERL_NIF_TERM) {
  return 0;
}

ERL_NIF_INIT(Elixir.Mlx.Nif, nif_funcs, on_load, on_reload, on_upgrade, NULL)