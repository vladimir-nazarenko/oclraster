project (swraster)
cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

include (${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set (CMAKE_CXX_STANDARD 14)

find_package(CUDA REQUIRED)

include_directories(.)

set (SOURCES
		cuda/check_error.h
		cuda/saxpy.h
		cuda/saxpy.cu
		util/cl_engine.cpp
		util/cl_engine.h
		util/config.cpp
		util/config.h
		util/rassert.h)

add_executable(${PROJECT_NAME} ${SOURCES} main.cpp)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})

set (TEST_SOURCES
		test/test_saxpy.cpp)

cuda_add_executable(${PROJECT_NAME}_Test ${SOURCES} ${TEST_SOURCES})
target_link_libraries(${PROJECT_NAME}_Test ${CONAN_LIBS})