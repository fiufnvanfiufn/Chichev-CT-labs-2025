#include <iostream>
#include <string.h>
#include "mymath/mymath.hpp"
#include "ourmath/ourmath.hpp"

int Demonstrative() {
    std::cout << "Я умею суммировать! Зацени 1 + 1 = ";
    std::cout << mymath::sum(10, 32) << std::endl;

    std::cout << "А я умею получать остаток от деления, смотри 10000 % 2 = ";
    std::cout << ourmath::RemainderOfDevision(5, 2) << std::endl;

    return 0;
}

int Interactive() {
    std::cout << "Введите цифрами два целых числа, делимое, остаток от которого при делении на делитель хотите получить, сам делитель" << std::endl;
    int devisible{};
    int devider{};
    std::cin >> devisible >> devider;
    std::cout << devisible << " % " << devider << " = " << ourmath::RemainderOfDevision(devisible, devider) << std::endl;
    return 0;
}

int main(int argc, char *argv[]) {
    bool isInteractive = false;    // по умолчанию демо-режим.

    // Если i передается в качестве аргумента, то программу
    // необходимо запустить в интерактивном режиме
    if ((argc == 2) && strcmp(argv[1], "i") == 0) {
        isInteractive = true;
    }

    if (isInteractive) {
        return Interactive();

    } else {
        return Demonstrative();
    }
    return 0;
}
