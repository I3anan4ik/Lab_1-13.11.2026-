#pragma once
#include <concepts>
#include <type_traits>
#include <utility>
#include <vector>
#include <cmath>

template<typename Function>
concept function_of_x = std::invocable<Function, double> && std::convertible_to<std::invoke_result_t<Function, double>, double>;


template<typename Function>
double min_uniform_search(double a, double b, double eps, Function f){
    double xk = a;
    double step = eps / 2;
    double min_res = xk;
    for(;xk <= b; xk += step)
        min_res = (f(xk) < f(min_res)) ? xk : min_res;
    return min_res;
}

template <typename Function>
double min_local(double a, double b, double eps, Function f)
requires function_of_x<Function> {
    if (b - a < 2 * eps) return (a + b) / 2.0;

    double step = (b - a) / 10.0;
    double xprev = a;
    double fprev = f(xprev);

    double xcurrent = a + step;
    double fcurrent = f(xcurrent);

    if (fcurrent >= fprev) {
        return min_local(xprev, xcurrent, eps, f);
    }

    double xnext = xcurrent + step;
    while (xnext <= b) {
        double fnext = f(xnext);
        if (fnext >= fcurrent) {
            return min_local(xprev, xnext, eps, f);
        }
        xprev = xcurrent;
        fprev = fcurrent;
        xcurrent = xnext;
        fcurrent = fnext;
        xnext += step;
    }
    return min_local(xprev, b, eps, f);
}

template <typename Function>
double min_dihotomia(double a, double b, double eps, Function f) {
    double xmiddle = (b + a)/2.0;
    if((b - a) < 2 * eps) return xmiddle;
    double xleft = (xmiddle + a)/2.0;
    double xright = (b + xmiddle)/2.0;
    double fmiddle = f(xmiddle);
    double fleft = f(xleft);
    double fright = f(xright);
    while((b - a) >= 2 * eps) {
        if(fleft < fmiddle) {
            b = xmiddle;
            xmiddle = xleft;
            fmiddle = fleft;
            xright = (b + xmiddle) / 2.0;
            fright = f(xright);
            xleft = (xmiddle + a) / 2.0;
            fleft = f(xleft);
        } else if(fmiddle < fright){
            a = xleft;
            b = xright;
            xleft = (xmiddle + a) / 2.0;
            fleft = f(xleft);
            xright = (b + xmiddle) / 2.0;
            fright = f(xright);
        } else {
            a=xmiddle;
            xmiddle = xright;
            fmiddle = fright;
            xright = (b + xmiddle) / 2.0;
            fright = f(xright);
            xleft = (xmiddle + a) / 2.0;
            fleft = f(xleft);
        }
    }
    return xmiddle;
}

template <typename Function>
double min_golden_ration(double a, double b, double eps, Function f) // ошибка есть
requires function_of_x<Function>{
    double y = a + (3- std::sqrt(5))/2.0 * (b - a);
    double z = a + b - y;
    double fy = f(y);
    double fz = f(z);
    while((b-a) > eps){
        if(f(y) < f(z)){
            b = z;
            z = y;
            fz = fy;
            y = a + b - z;
            fy = f(y);
        } else{
            a =y;
            y = z;
            fy = fz;
            z = a + b - y;
            fz = f(z);
        }
    }
    return fy < fz ? y : z;
}

template <typename Function>
double min_fibbonachi(double a, double b, double eps, Function f) {
    std::vector<double> F = {1.0, 1.0};
    double target = (b - a) / eps;
    
    while (F.back() <= target) {
        size_t sz = F.size();
        F.push_back(F[sz - 1] + F[sz - 2]);
    }

    int n = static_cast<int>(F.size()) - 1;

    double x1 = a + (F[n - 2] / F[n]) * (b - a);
    double x2 = a + (F[n - 1] / F[n]) * (b - a);
    
    double f1 = f(x1);
    double f2 = f(x2);

    for (int k = 1; k <= n - 2; ++k) {
        if (f1 <= f2) {
            b = x2;
            x2 = x1;
            f2 = f1;
            x1 = a + (F[n - k - 2] / F[n - k]) * (b - a);
            f1 = f(x1);
        } else {
            a = x1;
            x1 = x2;
            f1 = f2;
            x2 = a + (F[n - k - 1] / F[n - k]) * (b - a);
            f2 = f(x2);
        }
    }

    double delta = eps * 0.01;
    x2 = x1 + delta;
    f2 = f(x2);

    if (f1 <= f2) {
        b = x2;
    } else {
        a = x1;
    }

    return (a + b) / 2.0;
}