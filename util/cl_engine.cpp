#include "cl_engine.h"

#include <stdexcept>
#include <iostream>
#include <vector>

#include "config.h"
#include "rassert.h"

inline void CHECK_CL_STATUS(cl_int status)
{
    if (status != CL_SUCCESS)
        throw std::runtime_error("Invalid cl status");
}

CLEngine::CLEngine()
        : platform_(CL_NONE)
{
    initPlatform();
    initDevice();
}

void CLEngine::initDevice()
{
    cl_uint device_count;
    CHECK_CL_STATUS(clGetDeviceIDs(platform_, CL_DEVICE_TYPE_GPU, CL_UINT_MAX, nullptr, &device_count));
    std::cout << "Found " << device_count << " devices" << std::endl;
    std::vector<cl_device_id> device_ids(device_count);
    CHECK_CL_STATUS(clGetDeviceIDs(platform_, CL_DEVICE_TYPE_GPU, device_count, device_ids.data(), nullptr));

    int target_device_index = Config::getInstance().getValue<int>("device_index");
    for (cl_uint i = 0; i < device_count; ++i) {
        std::cout << "Device " << i << std::endl;
        std::string device_name(64, '~');
        CHECK_CL_STATUS(clGetDeviceInfo(device_ids[i], CL_DEVICE_NAME, device_name.capacity(), (void *)device_name.data(), nullptr));
        std::cout << "Name: " << device_name << std::endl;

        if (i == target_device_index) {
            std::cout << "Device selected." << std::endl;
            device_ = device_ids[i];
        }
    }

    rassert(device_ != CL_NONE);
}

void CLEngine::initPlatform()
{
    cl_uint num_platforms;
    CHECK_CL_STATUS(clGetPlatformIDs(CL_UINT_MAX, nullptr, &num_platforms));
    std::cout << "Found " << num_platforms << " platforms" << std::endl;
    std::vector<cl_platform_id> platform_ids(num_platforms);
    CHECK_CL_STATUS(clGetPlatformIDs(num_platforms, platform_ids.data(), nullptr));

    int target_platform_index = Config::getInstance().getValue<int>("platform_index");
    for (cl_uint i = 0; i < num_platforms; ++i) {
        std::cout << "Platform " << i << std::endl;
        std::string platform_name(64, '~');
        CHECK_CL_STATUS(clGetPlatformInfo(platform_ids[i], CL_PLATFORM_NAME, platform_name.capacity(), (void *)platform_name.data(), nullptr));
        std::cout << "Name: " << platform_name << std::endl;

        if (i == target_platform_index) {
            std::cout << "Platform selected." << std::endl;
            platform_ = platform_ids[i];
        }
    }

    rassert(platform_ != CL_NONE);
}
