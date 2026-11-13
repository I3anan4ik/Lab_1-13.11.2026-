#include <iostream>
#include <iomanip>
#include "functions.h"
#include "function.h"

// 2 |   5	27	33	35	38	45


int main() {
    std::cout << std::fixed << std::setprecision(8);

    std::cout << "Uniform:\n";
    double x1_min_uni = min_uniform_search(-3.0, 0.0, 1e-6, foo1);
    double x2_min_uni = min_uniform_search(-4.0, 0.0, 1e-6, foo2);
    double x3_min_uni = min_uniform_search(-1.0, 3.0, 1e-6, foo3);
    double x4_min_uni = min_uniform_search(-4.0, 1.0, 1e-6, foo4);
    double x5_min_uni = min_uniform_search(-2.0, 0.0, 1e-6, foo5);
    double x6_min_uni = min_uniform_search(0.0, 2.0, 1e-6, foo6);
    std::cout << "foo1: x = " << x1_min_uni << " f(x) = " << foo1(x1_min_uni) << '\n';
    std::cout << "foo2: x = " << x2_min_uni << " f(x) = " << foo2(x2_min_uni) << '\n';
    std::cout << "foo3: x = " << x3_min_uni << " f(x) = " << foo3(x3_min_uni) << '\n';
    std::cout << "foo4: x = " << x4_min_uni << " f(x) = " << foo4(x4_min_uni) << '\n';
    std::cout << "foo5: x = " << x5_min_uni << " f(x) = " << foo5(x5_min_uni) << '\n';
    std::cout << "foo6: x = " << x6_min_uni << " f(x) = " << foo6(x6_min_uni) << '\n';

    std::cout << "Localization:\n";
    double x1_min_local = min_local(-3.0, 0.0, 1e-6, foo1);
    double x2_min_local = min_local(-4.0, 0.0, 1e-6, foo2);
    double x3_min_local = min_local(-1.0, 3.0, 1e-6, foo3);
    double x4_min_local = min_local(-4.0, 1.0, 1e-6, foo4);
    double x5_min_local = min_local(-2.0, 0.0, 1e-6, foo5);
    double x6_min_local = min_local(0.0, 2.0, 1e-6, foo6);
    std::cout << "foo1: x = " << x1_min_local << " f(x) = " << foo1(x1_min_local) << '\n';
    std::cout << "foo2: x = " << x2_min_local << " f(x) = " << foo2(x2_min_local) << '\n';
    std::cout << "foo3: x = " << x3_min_local << " f(x) = " << foo3(x3_min_local) << '\n';
    std::cout << "foo4: x = " << x4_min_local << " f(x) = " << foo4(x4_min_local) << '\n';
    std::cout << "foo5: x = " << x5_min_local << " f(x) = " << foo5(x5_min_local) << '\n';
    std::cout << "foo6: x = " << x6_min_local << " f(x) = " << foo6(x6_min_local) << '\n';

    std::cout << "Dihotomia:\n";
    double x1_min_dih = min_dihotomia(-3.0, 0.0, 1e-6, foo1);
    double x2_min_dih = min_dihotomia(-4.0, 0.0, 1e-6, foo2);
    double x3_min_dih = min_dihotomia(-1.0, 3.0, 1e-6, foo3);
    double x4_min_dih = min_dihotomia(-4.0, 1.0, 1e-6, foo4);
    double x5_min_dih = min_dihotomia(-2.0, 0.0, 1e-6, foo5);
    double x6_min_dih = min_dihotomia(0.0, 2.0, 1e-6, foo6);
    std::cout << "foo1: x = " << x1_min_dih << " f(x) = " << foo1(x1_min_dih) << '\n';
    std::cout << "foo2: x = " << x2_min_dih << " f(x) = " << foo2(x2_min_dih) << '\n';
    std::cout << "foo3: x = " << x3_min_dih << " f(x) = " << foo3(x3_min_dih) << '\n';
    std::cout << "foo4: x = " << x4_min_dih << " f(x) = " << foo4(x4_min_dih) << '\n';
    std::cout << "foo5: x = " << x5_min_dih << " f(x) = " << foo5(x5_min_dih) << '\n';
    std::cout << "foo6: x = " << x6_min_dih << " f(x) = " << foo6(x6_min_dih) << '\n';

    std::cout << "Golden_ration:\n";
    double x1_min_gold = min_golden_ration(-3.0, 0.0, 1e-6, foo1);
    double x2_min_gold = min_golden_ration(-4.0, 0.0, 1e-6, foo2);
    double x3_min_gold = min_golden_ration(-1.0, 3.0, 1e-6, foo3);
    double x4_min_gold = min_golden_ration(-4.0, 1.0, 1e-6, foo4);
    double x5_min_gold = min_golden_ration(-2.0, 0.0, 1e-6, foo5);
    double x6_min_gold = min_golden_ration(0.0, 2.0, 1e-6, foo6);
    std::cout << "foo1: x = " << x1_min_gold  << " f(x) = " << foo1(x1_min_gold ) << '\n';
    std::cout << "foo2: x = " << x2_min_gold  << " f(x) = " << foo2(x2_min_gold ) << '\n';
    std::cout << "foo3: x = " << x3_min_gold  << " f(x) = " << foo3(x3_min_gold ) << '\n';
    std::cout << "foo4: x = " << x4_min_gold  << " f(x) = " << foo4(x4_min_gold ) << '\n';
    std::cout << "foo5: x = " << x5_min_gold  << " f(x) = " << foo5(x5_min_gold ) << '\n';
    std::cout << "foo6: x = " << x6_min_gold  << " f(x) = " << foo6(x6_min_gold ) << '\n';

    std::cout << "Fibbonachi:\n";
    double x1_min_fib = min_fibbonachi(-3.0, 0, 1e-6, foo1);
    double x2_min_fib = min_fibbonachi(-4.0, 0.0, 1e-6, foo2);
    double x3_min_fib = min_fibbonachi(-1.0, 3.0, 1e-6, foo3);
    double x4_min_fib = min_fibbonachi(-4.0, 1.0, 1e-6, foo4);
    double x5_min_fib = min_fibbonachi(-2.0, 0.0, 1e-6, foo5);
    double x6_min_fib = min_fibbonachi(0.0, 2.0, 1e-6, foo6);
    std::cout << "foo1: x = " << x1_min_fib << " f(x) = " << foo1(x1_min_fib) << '\n';
    std::cout << "foo2: x = " << x2_min_fib << " f(x) = " << foo2(x2_min_fib) << '\n';
    std::cout << "foo3: x = " << x3_min_fib << " f(x) = " << foo3(x3_min_fib) << '\n';
    std::cout << "foo4: x = " << x4_min_fib << " f(x) = " << foo4(x4_min_fib) << '\n';
    std::cout << "foo5: x = " << x5_min_fib << " f(x) = " << foo5(x5_min_fib) << '\n';
    std::cout << "foo6: x = " << x6_min_fib << " f(x) = " << foo6(x6_min_fib) << '\n';

    return 0;
}