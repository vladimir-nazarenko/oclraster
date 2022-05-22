#include "saxpy.h"
#include <cuda_runtime.h>

#include <cuda/check_error.h>

__global__ void cuda_saxpy(float a, const float *x, const float *y, unsigned int sz, float *res)
{
    int i = blockDim.x * blockIdx.x + threadIdx.x;

    if (i < sz) {
        res[i] = a * x[i] + y[i];
    }
}

void saxpy(float a, const float *x, const float *y, unsigned int sz, float *res)
{
//    for (unsigned int i = 0; i < sz; ++i) {
//        res[i] = a * x[i] + y[i];
//    }

    float *d_x, *d_y, *d_res;

    cudaCheckError(cudaMalloc(&d_x, sizeof(float) * sz));
    cudaCheckError(cudaMalloc(&d_y, sizeof(float) * sz));
    cudaCheckError(cudaMalloc(&d_res, sizeof(float) * sz));

    cudaCheckError(cudaMemcpy(d_x, x, sizeof(float) * sz, cudaMemcpyKind::cudaMemcpyHostToDevice));
    cudaCheckError(cudaMemcpy(d_y, y, sizeof(float) * sz, cudaMemcpyKind::cudaMemcpyHostToDevice));

    int wgr_sz = 256;
    int grid_sz = (sz + wgr_sz - 1) / wgr_sz;

    cuda_saxpy<<<grid_sz, wgr_sz>>>(a, d_x, d_y, sz, d_res);

    cudaCheckError(cudaMemcpy(res, d_res, sizeof(float) * sz, cudaMemcpyKind::cudaMemcpyDeviceToHost));

    cudaCheckError(cudaFree(d_x));
    cudaCheckError(cudaFree(d_y));
    cudaCheckError(cudaFree(d_res));
}