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
        }
    }
    if (n > 1) {
        stack.push(n);
    }
}

int main(int, char**) {
    int n{};

    MyStack<int> Data;
    std::cin >> n;

    Multipliers(n, Data);

    std::cout << Data.top_inf() << std::endl;
    return 0;
}
