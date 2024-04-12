defmodule Mlx.Nif do
  @on_load :load_nif
  def load_nif do
    nif_file = ~c"#{:code.priv_dir(:emlx)}/mlx_nif"

    case :erlang.load_nif(nif_file, 0) do
      :ok -> :ok
      {:error, {:reload, _}} -> :ok
      {:error, reason} -> IO.puts("Failed to load nif: #{inspect(reason)}")
    end
  end

  def hello, do: :erlang.nif_error(:not_loaded)

  def metal_get_active_memory, do: :erlang.nif_error(:not_loaded)

  def metal_get_cache_memory, do: :erlang.nif_error(:not_loaded)

  def metal_get_peak_memory, do: :erlang.nif_error(:not_loaded)

  def metal_is_available, do: :erlang.nif_error(:not_loaded)

  def metal_set_cache_limit(_limit), do: :erlang.nif_error(:not_loaded)

  def metal_set_memory_limit(_limit, _relaxed), do: :erlang.nif_error(:not_loaded)

  
end