#pragma once
#include <string>
#include <stdexcept>
#include <cuda_runtime.h>

#define cudaCheckError(expr) { cudaError_t e = (expr); if(e != cudaSuccess) { std::string msg =  std::string("CUDA error ") + cudaGetErrorString(e) + " at " + __FILE__ + ":" + std::to_string(__LINE__); throw std::runtime_error(msg); } }
