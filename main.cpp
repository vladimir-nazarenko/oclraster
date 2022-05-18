#include <iostream>

#define CL_TARGET_OPENCL_VERSION 120
#include <CL/cl.h>

inline void CHECK_CL_STATUS(cl_int status)
{
    if (status != CL_SUCCESS)
        throw std::runtime_error("Invalid cl status");
}

int main()
{
	std::cout << "Oclraster" << std::endl;

    cl_uint num_platforms;
    CHECK_CL_STATUS(clGetPlatformIDs(CL_UINT_MAX, nullptr, &num_platforms));
    std::cout << "Found " << num_platforms << " platforms" << std::endl;

	return 0;
}
