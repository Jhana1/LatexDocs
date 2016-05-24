template <typename T>
using uCat = T(*)(T);

template <typename T>
using mCat = T(*)(T, T);

__device__ int square(int a)
{
    return a * a;
}

__device__ int mult(int a, int b)
{
    return a * b;
}

template <typename T>
__device__ T mult(T a, T b)
{
    return a * b;
}

template <typename T, mCat<T> func>
__global__ void biMapKernel(T *a, T *b, T *c, size_t size)
{
    size_t i = threadIdx.x + blockIdx.x * blockDim.x;
    if (i < size)
        c[i] = func(a[i], b[i]);
}

template <typename T, uCat<T> func>
__global__ void MapKernel(T *a, T *c, size_t size)
{
    size_t i = threadIdx.x + blockIdx.x * blockDim.x;
    if (i < size)
        c[i] = func(a[i]);
}
