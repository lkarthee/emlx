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

  # object
  def tostring(_obj), do: :erlang.nif_error(:not_loaded)

  def retain(_obj), do: :erlang.nif_error(:not_loaded)

  def free(_obj), do: :erlang.nif_error(:not_loaded)

  # array

  def array_from_bool(_val), do: :erlang.nif_error(:not_loaded)

  def array_from_int(_val), do: :erlang.nif_error(:not_loaded)

  def array_from_float(_val), do: :erlang.nif_error(:not_loaded)

  def array_from_complex(_val), do: :erlang.nif_error(:not_loaded)

  def array_from_data(_data, _shape, _dim, _dtype), do: :erlang.nif_error(:not_loaded)

  def array_itemsize(_array), do: :erlang.nif_error(:not_loaded)

  def array_size(_array), do: :erlang.nif_error(:not_loaded)

  def array_strides(_array), do: :erlang.nif_error(:not_loaded)

  def array_nbytes(_array), do: :erlang.nif_error(:not_loaded)

  def array_ndim(_array), do: :erlang.nif_error(:not_loaded)

  def array_shape(_array), do: :erlang.nif_error(:not_loaded)

  def array_dim(_array, _dim), do: :erlang.nif_error(:not_loaded)

  def array_get_dtype(_array, _dim), do: :erlang.nif_error(:not_loaded)

  def array_eval(_array), do: :erlang.nif_error(:not_loaded)

  def array_item_bool(_array), do: :erlang.nif_error(:not_loaded)

  def array_item_uint8(_array), do: :erlang.nif_error(:not_loaded)

  def array_item_uint16(_array), do: :erlang.nif_error(:not_loaded)

  def array_item_uint32(_array), do: :erlang.nif_error(:not_loaded)

  def array_item_uint64(_array), do: :erlang.nif_error(:not_loaded)

  def array_item_int8(_array), do: :erlang.nif_error(:not_loaded)
  
  def array_item_int16(_array), do: :erlang.nif_error(:not_loaded)
  
  def array_item_int32(_array), do: :erlang.nif_error(:not_loaded)
  
  def array_item_int64(_array), do: :erlang.nif_error(:not_loaded)
  
  def array_item_float32(_array), do: :erlang.nif_error(:not_loaded)
  
  def array_item_complex64(_array), do: :erlang.nif_error(:not_loaded)

  def array_data_bool(_array), do: :erlang.nif_error(:not_loaded)

  def array_data_uint8(_array), do: :erlang.nif_error(:not_loaded)

  def array_data_uint16(_array), do: :erlang.nif_error(:not_loaded)

  def array_data_uint32(_array), do: :erlang.nif_error(:not_loaded)

  def array_data_uint64(_array), do: :erlang.nif_error(:not_loaded)

  def array_data_int8(_array), do: :erlang.nif_error(:not_loaded)
  
  def array_data_int16(_array), do: :erlang.nif_error(:not_loaded)
  
  def array_data_int32(_array), do: :erlang.nif_error(:not_loaded)
  
  def array_data_int64(_array), do: :erlang.nif_error(:not_loaded)
  
  def array_data_float32(_array), do: :erlang.nif_error(:not_loaded)
  
  def array_data_complex64(_array), do: :erlang.nif_error(:not_loaded)

  # vector of arrays

  def vector_array_new(), do: :erlang.nif_error(:not_loaded)

  def vector_array_from_arrays(_arrays, _num_arrays), do: :erlang.nif_error(:not_loaded)

  def vector_array_from_array(_array), do: :erlang.nif_error(:not_loaded)

  def vector_array_add(_vec, _array), do: :erlang.nif_error(:not_loaded)

  def vector_array_add_arrays(_vec, _arrays, _num_arrays), do: :erlang.nif_error(:not_loaded)

  def vector_array_get(_vec, _index), do: :erlang.nif_error(:not_loaded)
  
  def vector_array_size(_vec), do: :erlang.nif_error(:not_loaded)


  # vec of vec of arrays

  def vector_vector_array_new(), do: :erlang.nif_error(:not_loaded)

  def vector_vector_array_add(_vec2, _vec), do: :erlang.nif_error(:not_loaded)

  def vector_vector_array_get(_vec2, _index), do: :erlang.nif_error(:not_loaded)

  def vector_vector_array_get2d(_vec, _index, _arr_index), do: :erlang.nif_error(:not_loaded)

  def vector_vector_array_size(_vec2), do: :erlang.nif_error(:not_loaded)

  # stream

  def stream_new(_index, _device), do: :erlang.nif_error(:not_loaded)

  def stream_new_on_device(_device), do: :erlang.nif_error(:not_loaded)

  def stream_equal(_lhs, _rhs), do: :erlang.nif_error(:not_loaded)

  def default_stream(_device), do: :erlang.nif_error(:not_loaded)

  def set_default_stream(_stream), do: :erlang.nif_error(:not_loaded)

  # device 

  def device_new(_type, _index), do: :erlang.nif_error(:not_loaded)

  def device_get_type(_device), do: :erlang.nif_error(:not_loaded)

  def default_device(), do: :erlang.nif_error(:not_loaded)

  def set_default_device(_device), do: :erlang.nif_error(:not_loaded)

  # string

  def string_new(_str), do: :erlang.nif_error(:not_loaded)

  def string_data(_str), do: :erlang.nif_error(:not_loaded)

  # map

  # closures

  def closure_new(_arrays, _func), do: :erlang.nif_error(:not_loaded)

  def closure_new_unary(_array, _func), do: :erlang.nif_error(:not_loaded)

  def closure_new_with_payload(_array, _payload, _dtor), do: :erlang.nif_error(:not_loaded)

  def closure_apply(_cls, _inputs), do: :erlang.nif_error(:not_loaded)

  def closure_value_and_grad_apply(_cls, _inputs), do: :erlang.nif_error(:not_loaded)

  # io utils

  def safetensors_new(), do: :erlang.nif_error(:not_loaded)

  def safetensors_data(_safetensors), do: :erlang.nif_error(:not_loaded)

  def safetensors_metadata(_safetensors), do: :erlang.nif_error(:not_loaded)

  # operations

  def abs(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def add(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def addmm(_c, _a, _b, _alpha, _beta, _stream), do: :erlang.nif_error(:not_loaded)

  def all_axes(_a, _axes, _num_axes, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def all_axis(_a, _axis, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def all_all(_a, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def allclose(_a, _b, _rtol, _atol, _equal_nan, _stream), do: :erlang.nif_error(:not_loaded)

  def any(_a, _axes, _num_axes, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def any_all(_a, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def arange(_start, _stop, _step, _dtype, _stream), do: :erlang.nif_error(:not_loaded)

  def arccos(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def arccosh(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def arcsin(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def arcsinh(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def arctan(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def arctanh(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def argmax(_a, _axis, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def argmax_all(_a, _axis, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def argmax_all(_a, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def argmin(_a, _axis, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def argmin_all(_a, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def argpartition(_a, _kth, _axis, _stream), do: :erlang.nif_error(:not_loaded)

  def argpartition_all(_a, _kth, _stream), do: :erlang.nif_error(:not_loaded)

  def argsort(_a, _axis, _stream), do: :erlang.nif_error(:not_loaded)

  def argsort_all(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def array_equal(_a, _b, _equal_nan, _stream), do: :erlang.nif_error(:not_loaded)

  def as_strided(_array, _shape, _num_shape, _strides, _num_strides, _offset, _stream), do: :erlang.nif_error(:not_loaded)

  def astype(_array, _dtype, _stream), do: :erlang.nif_error(:not_loaded)

  def atleast_1d(_array, _stream), do: :erlang.nif_error(:not_loaded)

  def atleast_2d(_array, _stream), do: :erlang.nif_error(:not_loaded)

  def atleast_3d(_array, _stream), do: :erlang.nif_error(:not_loaded)

  def broadcast_arrays(_inputs, _stream), do: :erlang.nif_error(:not_loaded)

  def broadcast_to(_a, _shape, _num_shape, _stream), do: :erlang.nif_error(:not_loaded)

  def ceil(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def clip(_a, _a_min, _a_max, _stream), do: :erlang.nif_error(:not_loaded)

  def concatenate(_arrays, _axis, _stream), do: :erlang.nif_error(:not_loaded)

  def concatenate_all(_arrays, _stream), do: :erlang.nif_error(:not_loaded)

  def conv1d(_input, _weight, _stride, _padding, _dilation, _groups, _stream), do: :erlang.nif_error(:not_loaded)

  def conv2d(_input, _weight, _f_stride, _s_stride, _f_padding, _s_padding, _f_dilation, _s_dilation, _groups, _stream), do: :erlang.nif_error(:not_loaded)

  def conv_general(_input, _weight, _stride, _num_stride, _padding_lo, _num_padding_lo, _padding_hi, _num_padding_hi, _kernel_dilation, _num_kernel_dilation, _input_dilation, _num_input_dilation, _groups, _flip, _stream), do: :erlang.nif_error(:not_loaded)

  def copy(_array, _stream), do: :erlang.nif_error(:not_loaded)

  def cos(_array, _stream), do: :erlang.nif_error(:not_loaded)

  def cosh(_array, _stream), do: :erlang.nif_error(:not_loaded)

  def cummax(_array, _axis, _reverse, _inclusive, _stream), do: :erlang.nif_error(:not_loaded)

  def cummin(_array, _axis, _reverse, _inclusive, _stream), do: :erlang.nif_error(:not_loaded)

  def cumprod(_array, _axix, _reverse, _inclusive, _stream), do: :erlang.nif_error(:not_loaded)

  def cumsum(_array, _axis, _reverse, _inclusive, _stream), do: :erlang.nif_error(:not_loaded)

  def depends(_inputs, _dependencies), do: :erlang.nif_error(:not_loaded)

  def dequantize(_w, _scales, _biases, _group_size, _bits, _stream), do: :erlang.nif_error(:not_loaded)

  def diag(_a, _k, _stream), do: :erlang.nif_error(:not_loaded)

  def diagonal(_a, _offset, _axis1, _axis2, _stream), do: :erlang.nif_error(:not_loaded)

  def divide(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def divmod(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def equal(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def erf(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def erfinv(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def exp(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def expand_dims(_array, _axes, _num_axes, _stream), do: :erlang.nif_error(:not_loaded)

  def eye(_n, _m, _k, _dtype, _s), do: :erlang.nif_error(:not_loaded)

  def flatten(_a, _start_axis, _end_axis, _stream), do: :erlang.nif_error(:not_loaded)

  def floor(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def floor_divide(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def full(_shape, _num_shape, _vals, _dtype, _stream), do: :erlang.nif_error(:not_loaded)

  def gather(_a, _indicies, _axes, _num_axes, _slice_sizes, _num_slice_sizes, _stream), do: :erlang.nif_error(:not_loaded)

  def greater(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def greater_equal(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def identity(_n, _dtype, _s), do: :erlang.nif_error(:not_loaded)

  def inner(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def isclose(_a, _b, _rtol, _atol, _equal_nan, _stream), do: :erlang.nif_error(:not_loaded)

  def isinf(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def isnan(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def isneginf(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def isposinf(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def less(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def less_equal(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def linspace(_start, _stop, _num, _dtype, _stream), do: :erlang.nif_error(:not_loaded)

  def log(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def log10(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def log1p(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def log2(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def logaddexp(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def logical_and(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def logical_not(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def logical_or(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def logsumexp(_a, _axes, _num_axes, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def logsumexp_all(_a, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def matmul(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def max(_a, _axes, _num_axes, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def max_all(_a, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def maximum(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def mean(_a, _axes, _num_axes, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def mean_all(_a, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def min(_a, _axes, _num_axes, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def min_all(_a, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def minimum(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def moveaxis(_a, _source, _destination, _stream), do: :erlang.nif_error(:not_loaded)

  def multiply(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def negative(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def not_equal(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def ones(_shape, _num_shape, _dtype, _stream), do: :erlang.nif_error(:not_loaded)

  def ones_like(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def outer(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def pad(_a, _axes, _num_axes, _low_pad_size, _num_low_pad_size, _high_pad_size, _num_high_pad_size, _pad_value, _stream), do: :erlang.nif_error(:not_loaded)


  def partition(_a, _kth, _axis, _stream), do: :erlang.nif_error(:not_loaded)

  def partition_all(_a, _kth, _stream), do: :erlang.nif_error(:not_loaded)

  def power(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def prod(_a, _axes, _num_axes, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def prod_all(_a, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def quantize(_w, _groupsize, _bits, _stream), do: :erlang.nif_error(:not_loaded)

  def quantized_matmul(_x, _w, _scales, _biases, _traspose, _group_size, _bits, _stream), do: :erlang.nif_error(:not_loaded)

  def reciprocal(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def remainder(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def repeat(_a, _repeats, _axis, _stream), do: :erlang.nif_error(:not_loaded)

  def repeat_all(_a, _repeats, _stream), do: :erlang.nif_error(:not_loaded)

  def reshape(_a, _shape, _num_shape, _stream), do: :erlang.nif_error(:not_loaded)

  def round(_a, _decimals, _stream), do: :erlang.nif_error(:not_loaded)

  def rsqrt(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def scatter(_a, _indices, _updates, _axes, _num_axes, _stream), do: :erlang.nif_error(:not_loaded)

  def scatter_add(_a, _indices, _updates, _axes, _num_axes, _stream), do: :erlang.nif_error(:not_loaded)

  def scatter_max(_a, _indices, _updates, _axes, _num_axes, _stream), do: :erlang.nif_error(:not_loaded)

  def scatter_min(_a, _indices, _updates, _axes, _num_axes, _stream), do: :erlang.nif_error(:not_loaded)

  def scatter_prod(_a, _indices, _updates, _axes, _num_axes, _stream), do: :erlang.nif_error(:not_loaded)

  def sigmoid(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def sign(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def sin(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def sinh(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def slice(_a, _start, _num_start, _stop, _num_stop, _striders, _num_strides, _stream), do: :erlang.nif_error(:not_loaded)

  def softmax(_a, _axes, _num_axes, _stream), do: :erlang.nif_error(:not_loaded)

  def sort(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def sort_all(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def split_equal_parts(_a, _num_splits, _axis, _stream), do: :erlang.nif_error(:not_loaded)

  def split(_a, _indices, _num_indices, _axis, _stream), do: :erlang.nif_error(:not_loaded)

  def sqrt(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def squeeze(_a, _axes, _num_axes, _stream), do: :erlang.nif_error(:not_loaded)

  def squeeze_all(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def stack(_arrays, _axis, _stream), do: :erlang.nif_error(:not_loaded)

  def stack_all(_arrays, _stream), do: :erlang.nif_error(:not_loaded)

  def stop_gradient(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def substract(_a, _b, _stream), do: :erlang.nif_error(:not_loaded)

  def sum(_a, _axes, _num_axes, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def sum_all(_a, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def swapaxes(_a, _axis1, _axis2, _stream), do: :erlang.nif_error(:not_loaded)

  def take(_a, _indices, _axis, _stream), do: :erlang.nif_error(:not_loaded)

  def take_all(_a, _indices, _stream), do: :erlang.nif_error(:not_loaded)

  def take_along_axis(_a, _indices, _axis, _stream), do: :erlang.nif_error(:not_loaded)

  def tan(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def tanh(_a, _s), do: :erlang.nif_error(:not_loaded)

  def tensordot(_a, _b, _axes_a, _num_axes_a, _axes_b, _num_axes_b, _stream), do: :erlang.nif_error(:not_loaded)

  def tensordot_along_axis(_a, _b, _axis, _stream), do: :erlang.nif_error(:not_loaded)

  def tile(_a, _reps, _num_reps, _stream), do: :erlang.nif_error(:not_loaded)

  def topk(_a, _k, _axis, _stream), do: :erlang.nif_error(:not_loaded)

  def topk_all(_a, _k, _stream), do: :erlang.nif_error(:not_loaded)

  def transpose(_a, _axes, _num_axes, _stream), do: :erlang.nif_error(:not_loaded)

  def transpose_all(_a, _stream), do: :erlang.nif_error(:not_loaded)

  def tri(_n, _m, _k, _dtype, _stream), do: :erlang.nif_error(:not_loaded)

  def tril(_x, _k, _s), do: :erlang.nif_error(:not_loaded)

  def triu(_x, _k, _stream), do: :erlang.nif_error(:not_loaded)

  def var(_a, _axes, _num_axes, _keepdims, _ddof, _s), do: :erlang.nif_error(:not_loaded)

  def var_all(_a, _keepdims, _ddof, _stream), do: :erlang.nif_error(:not_loaded)

  def where(_condition, _x, _y, _stream), do: :erlang.nif_error(:not_loaded)

  def zeros(_shape, _num_shape, _dtype, _stream), do: :erlang.nif_error(:not_loaded)

  def zeros_like(_a, _stream), do: :erlang.nif_error(:not_loaded)

  # fft

  def fft_fft(_array, _n, _axis, _stream), do: :erlang.nif_error(:not_loaded)

  def fft_fft2(_array, _n, _num_n, _axes, _num_axes, _stream), do: :erlang.nif_error(:not_loaded)

  def fft_fftn(_array, _n, _num_n, _axes, _num_axes, _stream), do: :erlang.nif_error(:not_loaded)

  def fft_ifft(_array, _n, _axis, _stream), do: :erlang.nif_error(:not_loaded)

  def fft_ifft2(_array, _n, _num_n, _axes, _num_axes, _stream), do: :erlang.nif_error(:not_loaded)

  def fft_ifftn(_array, _n, _num_n, _axes, _num_axes, _stream), do: :erlang.nif_error(:not_loaded)

  def fft_irfft(_array, _n, _axis, _stream), do: :erlang.nif_error(:not_loaded)

  def fft_irfft2(_array, _n, _num_n, _axes, _num_axes, _stream), do: :erlang.nif_error(:not_loaded)

  def fft_irfftn(_array, _n, _num_n, _axes, _num_axes, _stream), do: :erlang.nif_error(:not_loaded)

  def fft_rfft(_array, _n, _axis, _stream), do: :erlang.nif_error(:not_loaded)

  def fft_rfft2(_array, _n, _num_n, _axes, _num_axes, _stream), do: :erlang.nif_error(:not_loaded)

  def fft_rfftn(_array, _n, _num_n, _axes, _num_axes, _stream), do: :erlang.nif_error(:not_loaded)

  # linear algebra

  def linalg_norm_p(_array, _ord, _axis, _num_axis, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def linalg_norm_ord(_array, _ord, _axis, _num_axis, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def linalg_norm(_array, _axis, _num_axis, _keepdims, _stream), do: :erlang.nif_error(:not_loaded)

  def linalg_qr(_array, _stream), do: :erlang.nif_error(:not_loaded)

  # random 

  def random_bernouli(_array, _shape, _num_shape, _key, _stream), do: :erlang.nif_error(:not_loaded)

  def random_bits(_shape, _num_shape, _width, _key, _stream), do: :erlang.nif_error(:not_loaded)

  def random_categorical_shape(_logits, _axis, _shape, _num_shape, _key, _stream), do: :erlang.nif_error(:not_loaded)

  def random_categorical_num_samples(_logits, _axis, _num_samples, _key, _stream), do: :erlang.nif_error(:not_loaded)

  def random_categorical(_logits, _axis, _key, _stream), do: :erlang.nif_error(:not_loaded)

  def random_gumbel(_shape, _num_shape, _dtype, _key, _stream), do: :erlang.nif_error(:not_loaded)

  def random_key(_seed), do: :erlang.nif_error(:not_loaded)

  def random_normal(_shape, _num_shape, _dtype, _loc, _scale, _key, _stream), do: :erlang.nif_error(:not_loaded)

  def random_randint(_low, _high, _shape, _num_shape,  _dtype, _key, _stream), do: :erlang.nif_error(:not_loaded)

  def random_seed(_seed), do: :erlang.nif_error(:not_loaded)

  def random_split_equal_parts(_key, _num, _stream), do: :erlang.nif_error(:not_loaded)

  def random_split(_key, _stream), do: :erlang.nif_error(:not_loaded)

  def random_truncated_normal(_lower, _upper, _shape, _num_shape, _dtype, _key, _stream), do: :erlang.nif_error(:not_loaded)

  def random_uniform(_low, _high, _shape, _num_shape, _dtype, _key, _stream), do: :erlang.nif_error(:not_loaded)

  # io operations

  def load_file(_in_stream, _stream), do: :erlang.nif_error(:not_loaded)

  def load(_file, _stream), do: :erlang.nif_error(:not_loaded)

  def load_safetensors_file(_in_stream, _stream), do: :erlang.nif_error(:not_loaded)

  def load_safetensors(_file, _stream), do: :erlang.nif_error(:not_loaded)

  def save_file(_out_stream, _array), do: :erlang.nif_error(:not_loaded)

  def save(_file, _array), do: :erlang.nif_error(:not_loaded)

  def save_safetensors_file(_in_stream, _param, _metadata), do: :erlang.nif_error(:not_loaded)

  def save_safetensors(_file, _param, _metadata), do: :erlang.nif_error(:not_loaded)

  # transforms

  def checkpoint(_func), do: :erlang.nif_error(:not_loaded)

  def eval(_outputs), do: :erlang.nif_error(:not_loaded)

  def jvp(_func, _primals, _tangents), do: :erlang.nif_error(:not_loaded)

  def value_and_grad(_func, _arg_nums, _num_argnums), do: :erlang.nif_error(:not_loaded)

  def vjp(_func, _primals, _cotangents), do: :erlang.nif_error(:not_loaded)

  # compilation

  def compile(_func, _shapeless), do: :erlang.nif_error(:not_loaded)

  def disable_compile(), do: :erlang.nif_error(:not_loaded)

  def enable_compile(), do: :erlang.nif_error(:not_loaded)

  # fast custom ops

  def mlx_fast_rope(_array, _dims, _traditional, _base, _scale, _offset, _stream), do: :erlang.nif_error(:not_loaded)

  # metal

  def metal_get_active_memory, do: :erlang.nif_error(:not_loaded)

  def metal_get_cache_memory, do: :erlang.nif_error(:not_loaded)

  def metal_get_peak_memory, do: :erlang.nif_error(:not_loaded)

  def metal_is_available, do: :erlang.nif_error(:not_loaded)

  def metal_set_cache_limit(_limit), do: :erlang.nif_error(:not_loaded)

  def metal_set_memory_limit(_limit, _relaxed), do: :erlang.nif_error(:not_loaded)

end