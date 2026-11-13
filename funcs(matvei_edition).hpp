#include<cmath>

// 9  |  3	 6	10	14	33	49

double f1(double x) {return std::exp(std::pow(x,2)) + 3 * x;}
double f2(double x) {return std::pow((x),3) - 3 * x;}
double f3(double x) {return std::pow(std::tan(x), 2);}
double f4(double x) {return std::pow(x,5) - 5 * std::pow(x,3);}
double f5(double x) {return std::cos(x) + std::sin(x);}
double f6(double x) {return (5 * std::pow(x,6) - 8 * x) * std::sin(x);}