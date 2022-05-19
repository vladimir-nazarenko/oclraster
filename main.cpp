#include <iostream>

#include "util/cl_engine.h"
#include "util/config.h"
#include "util/rassert.h"

int main()
{
    try {
        CLEngine engine;


    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::terminate();
    } catch (...) {
        std::cerr << "Unhandled exception" << std::endl;
        std::terminate();
    }

	return 0;
}
