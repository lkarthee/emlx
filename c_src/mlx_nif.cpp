#include <erl_nif.h>
#include "nif_utils.hpp"

#include "mlx/c/mlx.h"

static ERL_NIF_TERM hello(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  return erlang::nif::make_binary(env, "Hello world!");
  //enif_make_string(env, "Hello world!", ERL_NIF_LATIN1);
}

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
  bool relaxed;
  if (!erlang::nif::get(env, argv[0], &limit)) {
      return enif_make_badarg(env);
  }
  if (!erlang::nif::get(env, argv[1], &relaxed)) {
      return enif_make_badarg(env);
  }

  size_t result = mlx_metal_set_memory_limit(limit, relaxed);

  return erlang::nif::make(env, static_cast<uint64_t>(result));
}

static ErlNifFunc nif_funcs[] =
{
  {"hello", 0, hello},
  {"metal_get_active_memory", 0, metal_get_active_memory},
  {"metal_get_cache_memory", 0, metal_get_cache_memory},
  {"metal_get_peak_memory", 0, metal_get_peak_memory},
  {"metal_is_available", 0, metal_is_available},
  {"metal_set_cache_limit", 1, metal_set_cache_limit},
  {"metal_set_memory_limit", 2, metal_set_memory_limit}
};

static int on_load(ErlNifEnv *, void **, ERL_NIF_TERM) {
  return 0;
}

static int on_reload(ErlNifEnv *, void **, ERL_NIF_TERM) {
  return 0;
}

static int on_upgrade(ErlNifEnv *, void **, void **, ERL_NIF_TERM) {
  return 0;
}

ERL_NIF_INIT(Elixir.Mlx.Nif, nif_funcs, on_load, on_reload, on_upgrade, NULL)