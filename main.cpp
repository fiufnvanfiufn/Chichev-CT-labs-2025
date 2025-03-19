#include "Fractions/Fractions.hpp"

int main(int, char**) {
    std::cout << "Введите дробь: \n";
    ClassFractions::Fractions z;
    std::cin >> z;
    std::cout << "z=" << z << std::endl;
    // проверка конструкторов
    ClassFractions::Fractions fr1(0, 10, 14), fr2;
    std::cout << "fr2=" << fr2 << std::endl;
    std::cout << "fr1=" << fr1 << std::endl;
    ClassFractions::Fractions fr = "-1 4/8";
    std::cout << "fr=" << fr << std::endl;
    ClassFractions::Fractions x(z), y;
    std::cout << "x=" << x << std::endl;
    double dbl = -1.25;
    ClassFractions::Fractions f = dbl;
    std::cout << "f=" << f << std::endl;
    // проверка перегруженной операции "+"
    y = x + z;
    std::cout << "y=" << y << std::endl;
    y += x;
    f += dbl / 2;
    std::cout << "f=" << f << std::endl;
    y = x + dbl;
    std::cout << "y=" << y << std::endl;
    y = dbl + y;
    std::cout << "y=" << y << std::endl;
    y += dbl;
    std::cout << "y=" << y << std::endl;
    int i = 5;
    y += i;
    std::cout << "y=" << y << std::endl;
    y = i + x;
    std::cout << "y=" << y << std::endl;
    y = x + i;
    std::cout << "y=" << y << std::endl;
    y += dbl + i + x;
    std::cout << "y=" << y << std::endl;
    return 0;
}
