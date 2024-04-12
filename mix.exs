defmodule Emlx.MixProject do
  use Mix.Project

  @version "0.1.0"
  @github_url "https://github.com/lkarthee/emlx"

  def project do
    [
      app: :emlx,
      version: @version,
      elixir: "~> 1.16",
      start_permanent: Mix.env() == :prod,
      deps: deps(),
      package: package(),
      docs: docs(),
      description: "MLX bindings for Elixir",
      compilers: [:elixir_make] ++ Mix.compilers(),
      make_precompiler: {:nif, CCPrecompiler},
      make_precompiler_url: "#{@github_url}/releases/download/v#{@version}/@{artefact_filename}",
      make_precompiler_filename: "emlx_nif",
      make_precomipler_nif_versions: [versions: ["2.16"]],
      cc_precompiler: [
        cleanup: "clean",
        compilers: %{
          {:unix, :darwin} => %{
            :include_default_ones => true
          }
        }
      ]
    ]
  end

  # Run "mix help compile.app" to learn about applications.
  def application do
    [
      extra_applications: [:logger]
    ]
  end

  # Run "mix help deps" to learn about dependencies.
  defp deps do
    [
      # compilation
      {:cc_precompiler, "~> 0.1.8 or ~>0.2", runtime: false},
      {:elixir_make, "~> 0.8", runtime: false},

      # docs
      {:ex_doc, "~> 0.29", only: :docs, runtime: false}
    ]
  end

  defp docs do
    [
      main: "Emlx",
      source_ref: "v#{@version}",
      source_url: @github_url
    ]
  end

  defp package do
    [
      name: "emlx",
      files: ~w(3rd_party/mlx-c c_src lib mix.exs README* LICENSE* Makefile),
      licenses: ["MIT"],
      links: %{"GitHub" => @github_url}
    ]
  end
end
