project (oclraster)
cmake_minimum_required(VERSION 3.10)

include (${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set (CMAKE_CXX_STANDARD 14)

set (SOURCES
		main.cpp
		util/cl_engine.cpp
		util/cl_engine.h util/config.cpp util/config.h util/rassert.h)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})