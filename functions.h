#pragma once
#include <cmath>

template <typename T>
int sign(T val) {
    return (T(0) < val) - (val < T(0));
}
// 2 |   5	27	33	35	38	45


double foo1(double x) { return std::pow((x), 3) - 3 * x; } 
double foo2(double x) { return std::pow(6 * x, 2) - 12 * x; }
double foo3(double x) { return std::cos(x) + std::sin(x); }
double foo4(double x) { return sign(x) * (std::pow((x), 2)) - 3 * x; }
double foo5(double x) { return (std::pow((x), 6) - 2 * std::pow((x), 2)) * std::sin(x); }
double foo6(double x) { return std::pow((x), 4) - 3 * std::pow((x), 2) + 5; }