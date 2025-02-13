#include <iostream>
#include "mymath/mymath.hpp"
#include "ourmath/ourmath.hpp"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Я умею суммировать! Зацени 1+1=";
    std::cout << mymath::sum(10, 32) << std::endl;

    std::cout << "А я умею получать остаток от деления, смотри 10000 % 2 = ";
    std::cout << ourmath::RemainderOfDevision(5, 2) << std::endl;

    return 0;
}
