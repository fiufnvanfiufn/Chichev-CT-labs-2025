#include <iostream>
#include "Stack/Stack.hpp"

template<class DATA>
void Multipliers(int n, MyStack<DATA> &stack) {
    if (n < 2) {
        return;
    }

    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            stack.push(i);
            n /= i;
            std::cout << i << ' ';
        }
    }
    if (n > 1) {
        stack.push(n);
        std::cout << n;
    }
    std::cout << std::endl;

    std::cout << stack << std::endl;
}

int main(int, char**) {
    int n{};

    MyStack<int> Data;
    std::cin >> n;

    Multipliers(n, Data);

    MyStack<char> CharData;
    CharData.push('a');
    CharData.push('b');
    CharData.push('c');

    MyStack<char> CharData2(CharData);
    MyStack<char> CharData3;
    CharData3 = CharData2;
    CharData2.push('d');
    std::cout << CharData2 << std::endl;
    std::cout << CharData3 << std::endl;

    return 0;
}
