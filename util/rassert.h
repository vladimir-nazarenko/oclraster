#pragma once
#include <string>
#include <stdexcept>

#define rassert(expr) { std::string msg =  std::string("Assertion failed at file ") + __FILE__ + ":" + std::to_string(__LINE__); if (!(expr)) throw std::runtime_error(msg); }
