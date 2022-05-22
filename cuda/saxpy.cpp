#include "saxpy.h"

void saxpy(float a, const float *x, const float *y, unsigned int sz, float *res)
{
    for (unsigned int i = 0; i < sz; ++i) {
        res[i] = a * x[i] + y[i];
    }
}