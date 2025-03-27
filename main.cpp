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
    while (!stack.empty()) {
        std::cout << stack.top_inf() << ' ';
        stack.pop();
    }
    std::cout << std::endl;
}

int main(int, char**) {
    int n{};

    MyStack<int> Data;
    std::cin >> n;

    Multipliers(n, Data);
    return 0;
}
