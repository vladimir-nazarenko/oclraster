#pragma once

#define CL_TARGET_OPENCL_VERSION 120
#include <CL/cl.h>

class CLEngine {
public:
    CLEngine();
private:
    void initPlatform();
    void initDevice();

    cl_platform_id platform_;
    cl_device_id   device_;
};
