#include <erl_nif.h>
#include "nif_utils.hpp"
#include "mlx_nif_resource.hpp"

#include "mlx/c/mlx.h"

template<> ErlNifResourceType * NifRes<mlx_device>::type = nullptr;
template<> ErlNifResourceType * NifRes<mlx_stream>::type = nullptr;
template<> ErlNifResourceType * NifRes<mlx_array>::type = nullptr;
template<> ErlNifResourceType * NifRes<mlx_vector_array>::type = nullptr;
template<> ErlNifResourceType * NifRes<mlx_vector_vector_array>::type = nullptr;
template<> ErlNifResourceType * NifRes<mlx_closure>::type = nullptr;
template<> ErlNifResourceType * NifRes<mlx_safetensors>::type = nullptr;

static ERL_NIF_TERM hello(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  return erlang::nif::make_binary(env, "Hello world!");
}

// array

static ERL_NIF_TERM array_tostring(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  using res_type = NifRes<mlx_array>;
  ERL_NIF_TERM error{};
  res_type * array = nullptr;
  if ((array = res_type::get_resource(env, argv[0], error)) == nullptr) {
    return error;
  }
  return  erlang::nif::make_binary(env, mlx_string_data(mlx_tostring(array->val)));
}

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

static ERL_NIF_TERM array_from_int(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  using res_type = NifRes<mlx_array>;

  int value;
  if (!erlang::nif::get(env, argv[0], &value)) {
      return enif_make_badarg(env);
  }

  ERL_NIF_TERM error{};
  auto array = res_type::allocate_resource(env, error);
  array->val = mlx_array_from_int(value);
  ERL_NIF_TERM ret = array->make_resource(env);
  return erlang::nif::ok(env, ret);
}

static ERL_NIF_TERM array_from_float(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  using res_type = NifRes<mlx_array>;

  double value;
  if (!erlang::nif::get(env, argv[0], &value)) {
      return enif_make_badarg(env);
  }

  ERL_NIF_TERM error{};
  auto array = res_type::allocate_resource(env, error);
  array->val = mlx_array_from_float(value);
  ERL_NIF_TERM ret = array->make_resource(env);
  return erlang::nif::ok(env, ret);
}

static ERL_NIF_TERM array_from_complex(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  using res_type = NifRes<mlx_array>;

  double real_value;
  if (!erlang::nif::get(env, argv[0], &real_value)) {
      return enif_make_badarg(env);
  }

  double imag_value;
  if (!erlang::nif::get(env, argv[1], &imag_value)) {
      return enif_make_badarg(env);
  }

  ERL_NIF_TERM error{};
  auto array = res_type::allocate_resource(env, error);
  array->val = mlx_array_from_complex(real_value, imag_value);
  ERL_NIF_TERM ret = array->make_resource(env);
  return erlang::nif::ok(env, ret);
}

// static ERL_NIF_TERM array_item_uint8(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
// {
//   using res_type = NifRes<mlx_array>;

//   uint8_t value;
//   if (!erlang::nif::get(env, argv[0], &value)) {
//       return enif_make_badarg(env);
//   }

//   ERL_NIF_TERM error{};
//   auto array = res_type::allocate_resource(env, error);
//   array->val = mlx_array_from_uint8(value);
//   ERL_NIF_TERM ret = array->make_resource(env);
//   return erlang::nif::ok(env, ret);
// }

// static ERL_NIF_TERM array_item_uint16(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
// {
//   using res_type = NifRes<mlx_array>;

//   uint16_t value;
//   if (!erlang::nif::get(env, argv[0], &value)) {
//       return enif_make_badarg(env);
//   }

//   ERL_NIF_TERM error{};
//   auto array = res_type::allocate_resource(env, error);
//   array->val = mlx_array_from_uint16(value);
//   ERL_NIF_TERM ret = array->make_resource(env);
//   return erlang::nif::ok(env, ret);
// }

// static ERL_NIF_TERM array_item_uint32(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
// {
//   using res_type = NifRes<mlx_array>;

//   uint32_t value;
//   if (!erlang::nif::get(env, argv[0], &value)) {
//       return enif_make_badarg(env);
//   }

//   ERL_NIF_TERM error{};
//   auto array = res_type::allocate_resource(env, error);
//   array->val = mlx_array_from_uint32(value);
//   ERL_NIF_TERM ret = array->make_resource(env);
//   return erlang::nif::ok(env, ret);
// }

// static ERL_NIF_TERM array_item_uint64(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
// {
//   using res_type = NifRes<mlx_array>;

//   uint64_t value;
//   if (!erlang::nif::get(env, argv[0], &value)) {
//       return enif_make_badarg(env);
//   }

//   ERL_NIF_TERM error{};
//   auto array = res_type::allocate_resource(env, error);
//   array->val = mlx_array_from_uint64(value);
//   ERL_NIF_TERM ret = array->make_resource(env);
//   return erlang::nif::ok(env, ret);
// }

// static ERL_NIF_TERM array_item_int8(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
// {
//   using res_type = NifRes<mlx_array>;

//   int8_t value;
//   if (!erlang::nif::get(env, argv[0], &value)) {
//       return enif_make_badarg(env);
//   }

//   ERL_NIF_TERM error{};
//   auto array = res_type::allocate_resource(env, error);
//   array->val = mlx_array_from_int8(value);
//   ERL_NIF_TERM ret = array->make_resource(env);
//   return erlang::nif::ok(env, ret);
// }

// static ERL_NIF_TERM array_item_int16(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
// {
//   using res_type = NifRes<mlx_array>;

//   int16_t value;
//   if (!erlang::nif::get(env, argv[0], &value)) {
//       return enif_make_badarg(env);
//   }

//   ERL_NIF_TERM error{};
//   auto array = res_type::allocate_resource(env, error);
//   array->val = mlx_array_from_int16(value);
//   ERL_NIF_TERM ret = array->make_resource(env);
//   return erlang::nif::ok(env, ret);
// }

// static ERL_NIF_TERM array_item_int32(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
// {
//   using res_type = NifRes<mlx_array>;

//   int32_t value;
//   if (!erlang::nif::get(env, argv[0], &value)) {
//       return enif_make_badarg(env);
//   }

//   ERL_NIF_TERM error{};
//   auto array = res_type::allocate_resource(env, error);
//   array->val = mlx_array_from_int32(value);
//   ERL_NIF_TERM ret = array->make_resource(env);
//   return erlang::nif::ok(env, ret);
// }

// static ERL_NIF_TERM array_item_int64(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
// {
//   using res_type = NifRes<mlx_array>;

//   int64_t value;
//   if (!erlang::nif::get(env, argv[0], &value)) {
//       return enif_make_badarg(env);
//   }

//   ERL_NIF_TERM error{};
//   auto array = res_type::allocate_resource(env, error);
//   array->val = mlx_array_from_int64(value);
//   ERL_NIF_TERM ret = array->make_resource(env);
//   return erlang::nif::ok(env, ret);
// }

// static ERL_NIF_TERM array_item_float32(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
// {
//   using res_type = NifRes<mlx_array>;

//   float32 value;
//   if (!erlang::nif::get(env, argv[0], &value)) {
//       return enif_make_badarg(env);
//   }

//   ERL_NIF_TERM error{};
//   auto array = res_type::allocate_resource(env, error);
//   array->val = mlx_array_from_float32(value);
//   ERL_NIF_TERM ret = array->make_resource(env);
//   return erlang::nif::ok(env, ret);
// }

// static ERL_NIF_TERM array_item_complex64(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
// {
//   using res_type = NifRes<mlx_array>;

//   complex64 value;
//   if (!erlang::nif::get(env, argv[0], &value)) {
//       return enif_make_badarg(env);
//   }

//   ERL_NIF_TERM error{};
//   auto array = res_type::allocate_resource(env, error);
//   array->val = mlx_array_from_complex64(value);
//   ERL_NIF_TERM ret = array->make_resource(env);
//   return erlang::nif::ok(env, ret);
// }

static ERL_NIF_TERM array_item_bool(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  using res_type = NifRes<mlx_array>;

  ERL_NIF_TERM error{};
  res_type * array = nullptr;
  if ((array = res_type::get_resource(env, argv[0], error)) == nullptr) {
    return error;
  }
  auto item = mlx_array_item_bool(array->val);
  return erlang::nif::make(env, item);
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

static ERL_NIF_TERM array_get_dtype(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  using res_type = NifRes<mlx_array>;

  ERL_NIF_TERM error{};
  res_type * array = nullptr;
  if ((array = res_type::get_resource(env, argv[0], error)) == nullptr) {
    return error;
  }
  auto dtype = mlx_array_get_dtype(array->val);
  switch(dtype)
  {
    case MLX_BOOL:
      return erlang::nif::atom(env, "bool");

    case MLX_UINT8:
      return erlang::nif::atom(env, "uint8");

    case MLX_UINT16:
      return erlang::nif::atom(env, "uint16");

    case MLX_UINT32:
      return erlang::nif::atom(env, "uint32");

    case MLX_UINT64:
      return erlang::nif::atom(env, "uint64");

    case MLX_INT8:
      return erlang::nif::atom(env, "int8");

    case MLX_INT16:
      return erlang::nif::atom(env, "int16");

    case MLX_INT32:
      return erlang::nif::atom(env, "int32");

    case MLX_INT64:
      return erlang::nif::atom(env, "int64");

    case MLX_FLOAT16:
      return erlang::nif::atom(env, "float16");

    case MLX_FLOAT32:
      return erlang::nif::atom(env, "float32");

    case MLX_BFLOAT16:
      return erlang::nif::atom(env, "bfloat16");

    case MLX_COMPLEX64:
      return erlang::nif::atom(env, "complex64");
  } 
}

// random


static ERL_NIF_TERM random_bernouli(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  return erlang::nif::atom(env, "nil");
}
// random_bernouli(_array, _shape, _num_shape, _key, _stream)

// random_bits(_shape, _num_shape, _width, _key, _stream)

// random_categorical_shape(_logits, _axis, _shape, _num_shape, _key, _stream)

// random_categorical_num_samples(_logits, _axis, _num_samples, _key, _stream)

// random_categorical(_logits, _axis, _key, _stream)

// random_gumbel(_shape, _num_shape, _dtype, _key, _stream)

// random_key(_seed)

// random_normal(_shape, _num_shape, _dtype, _loc, _scale, _key, _stream)

// random_randint(_low, _high, _shape, _num_shape,  _dtype, _key, _stream)

// random_seed(_seed)

// random_split_equal_parts(_key, _num, _stream)

// random_split(_key, _stream)

// random_truncated_normal(_lower, _upper, _shape, _num_shape, _dtype, _key, _stream)

// random_uniform(_low, _high, _shape, _num_shape, _dtype, _key, _stream)

static ERL_NIF_TERM random_uniform(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  return erlang::nif::atom(env, "nil");
}

static ERL_NIF_TERM random_key(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  using res_type = NifRes<mlx_array>;

  uint64_t seed;
  if (!erlang::nif::get(env, argv[0], &seed)) {
      return enif_make_badarg(env);
  }

  ERL_NIF_TERM error{};
  auto array = res_type::allocate_resource(env, error);
  array->val = mlx_random_key(seed);;
  ERL_NIF_TERM ret = array->make_resource(env);
  return erlang::nif::ok(env, ret);
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
  using res_type = NifRes<mlx_device>;

  ERL_NIF_TERM error{};
  res_type * device = nullptr;
  if ((device = res_type::get_resource(env, argv[0], error)) == nullptr) {
    return error;
  }
  mlx_set_default_device(device->val);
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

// stream

static ERL_NIF_TERM stream_new(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  using device_res_type = NifRes<mlx_device>;
  using res_type = NifRes<mlx_stream>;

  int index;
  if (!erlang::nif::get(env, argv[0], &index)) {
      return enif_make_badarg(env);
  }
  ERL_NIF_TERM error{};
  device_res_type * device = nullptr;
  if ((device = device_res_type::get_resource(env, argv[1], error)) == nullptr) {
    return error;
  }

  auto stream = res_type::allocate_resource(env, error);
  stream->val = mlx_stream_new(index, device->val);
  ERL_NIF_TERM ret = stream->make_resource(env);
  return erlang::nif::ok(env, ret);
}

static ERL_NIF_TERM stream_new_on_device(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  using device_res_type = NifRes<mlx_device>;
  using res_type = NifRes<mlx_stream>;

  ERL_NIF_TERM error{};
  device_res_type * device = nullptr;
  if ((device = device_res_type::get_resource(env, argv[1], error)) == nullptr) {
    return error;
  }

  auto stream = res_type::allocate_resource(env, error);
  stream->val = mlx_stream_new_on_device(device->val);
  ERL_NIF_TERM ret = stream->make_resource(env);
  return erlang::nif::ok(env, ret);
}

static ERL_NIF_TERM stream_equal(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  using res_type = NifRes<mlx_stream>;

  ERL_NIF_TERM error{};
  res_type * rhs = nullptr;
  if ((rhs = res_type::get_resource(env, argv[0], error)) == nullptr) {
    return error;
  }
  res_type * lhs = nullptr;
  if ((lhs = res_type::get_resource(env, argv[0], error)) == nullptr) {
    return error;
  }
  mlx_stream_equal(rhs->val, lhs->val);
  return erlang::nif::atom(env, "nil");
}

static ERL_NIF_TERM set_default_stream(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  using res_type = NifRes<mlx_stream>;

  ERL_NIF_TERM error{};
  res_type * stream = nullptr;
  if ((stream = res_type::get_resource(env, argv[0], error)) == nullptr) {
    return error;
  }
  mlx_set_default_stream(stream->val);
  return erlang::nif::atom(env, "nil");
}

static ERL_NIF_TERM default_stream(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  using device_res_type = NifRes<mlx_device>;
  using res_type = NifRes<mlx_stream>;

  ERL_NIF_TERM error{};
  device_res_type * device = nullptr;
  if ((device = device_res_type::get_resource(env, argv[0], error)) == nullptr) {
    return error;
  }
  auto stream = res_type::allocate_resource(env, error);
  stream->val = mlx_default_stream(device->val);
  ERL_NIF_TERM ret = stream->make_resource(env);
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
  {"array_tostring", 1, array_tostring},
  {"array_from_bool", 1, array_from_bool},
  {"array_from_int", 1, array_from_int},
  {"array_from_float", 1, array_from_float},
  {"array_from_complex", 2, array_from_complex},


  // {"array_from_uint8", 1, array_from_uint8},
  // {"array_from_uint16", 1, array_from_uint16},
  // {"array_from_uint32", 1, array_from_uint32},
  // {"array_from_uint64", 1, array_from_uint64},
  // {"array_from_int8", 1, array_from_int8},
  // {"array_from_int16", 1, array_from_int16},
  // {"array_from_int32", 1, array_from_int32},
  // {"array_from_int64", 1, array_from_int64},
  // {"array_from_float32", 1, array_from_float32},
  // {"array_from_complex64", 1, array_from_complex64},

  {"array_item_bool", 1, array_item_bool},

  {"array_itemsize", 1, array_itemsize},
  {"array_shape", 1, array_shape},
  {"array_size", 1, array_size},
  {"array_nbytes", 1, array_nbytes},
  {"array_ndim", 1, array_ndim},
  {"array_get_dtype", 1, array_get_dtype},

  // random
  // {"random_bernouli", 5, random_bernouli},
  // {"random_bits", 5, random_bits},
  // {"random_categorical_shape", 6, random_categorical_shape},
  // {"random_categorical_num_samples", 5, random_categorical_num_samples},
  // {"random_categorical", 4, random_categorical},
  // {"random_gumbel", 5, random_gumbel},
  // {"random_key", 1, random_key},
  // {"random_normal", 7, random_normal},
  // {"random_randint", 7, random_randint},
  // {"random_seed", 1, random_seed},
  // {"random_split_equal_parts", 3, random_split_equal_parts},
  // {"random_split", 2, random_split},
  // {"random_truncated_normal", 7, random_truncated_normal},
  // {"random_uniform", 7, random_uniform},

  // stream
  {"stream_new", 2, stream_new},
  {"stream_new_on_device", 1, stream_new_on_device},
  {"stream_equal", 2, stream_equal},
  {"default_stream", 1, default_stream},
  {"set_default_stream", 1, set_default_stream},

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
    using res_type = NifRes<mlx_vector_array>;
    rt = enif_open_resource_type(env, "Elixir.Mlx.Nif", "NifResMlxVectorArray", destruct_mlx_vector_array_resource, ERL_NIF_RT_CREATE, NULL);
    if (!rt) return -1;
    res_type::type = rt;
  }

  {
    using res_type = NifRes<mlx_vector_vector_array>;
    rt = enif_open_resource_type(env, "Elixir.Mlx.Nif", "NifResMlxVectorVectorArray", destruct_mlx_vector_vector_array_resource, ERL_NIF_RT_CREATE, NULL);
    if (!rt) return -1;
    res_type::type = rt;
  }

  {
    using res_type = NifRes<mlx_closure>;
    rt = enif_open_resource_type(env, "Elixir.Mlx.Nif", "NifResMlxClosure", destruct_mlx_closure_resource, ERL_NIF_RT_CREATE, NULL);
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

  {
    using res_type = NifRes<mlx_safetensors>;
    rt = enif_open_resource_type(env, "Elixir.Mlx.Nif", "NifResMlxSafeTensors", destruct_mlx_safetensors_resource, ERL_NIF_RT_CREATE, NULL);
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