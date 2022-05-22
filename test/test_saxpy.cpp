#include <gtest/gtest.h>

#include <cuda/saxpy.h>

#include <random>

TEST(saxpy, medium_array)
{
    int n = 1000;
    std::vector<float> x(n, 0);
    std::vector<float> y(n, 0);

    std::default_random_engine e(239);
    std::uniform_real_distribution<float> dist(0, 1);
    for (auto &v: x) {
        v = dist(e);
    }

    for (auto &v: y) {
        v = dist(e);
    }

    float a = dist(e);

    std::vector<float> res(n);

    saxpy(a, x.data(), y.data(), n, res.data());

    for (uint32_t i = 0; i < n; ++i) {
        ASSERT_FLOAT_EQ(res[i], a * x[i] + y[i]);
    }

//    bool all_same = true;
//    for (uint32_t i = 0; i < n; ++i) {
//        all_same = all_same && (std::abs(res[i] - (a * x[i] + y[i])) < 1e-7f);
//    }
//    ASSERT_TRUE(all_same);
}