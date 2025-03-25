#pragma once
#include <cstring>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <cmath>
#include <cstdlib>

namespace ClassFractions {
class Fractions {
private:
    int _numerator;
    int _denominator;
public:
    Fractions();

    Fractions(int integerPart, int numerator, int denominator);

    Fractions(const char* line);

    Fractions(double x);

    Fractions& operator=(const char* line);

    Fractions& operator=(const Fractions& other);

    void SetNumerator(int numerator) {
        _numerator = numerator;
    }

    void SetDenominator(int denominator) {
        this->_denominator = denominator;
    }

    Fractions& operator=(double x);

    void SplitDouble(double num, int& whole, int& fraction, int& dec);

    void ShortenFraction();

    Fractions operator+(double x);

    Fractions operator+(int x);

    Fractions operator+(const Fractions& ex) const;

    Fractions(const Fractions& ex);

    Fractions operator+=(const Fractions& ex);

    Fractions operator+=(int x);

    Fractions operator+=(double x);

    int Get_Numerator();

    int Get_Denominator();

    friend Fractions operator+(int a, const Fractions& b);

    friend Fractions operator+(double a, const Fractions& b);

    friend std::ostream& operator<<(std::ostream& out, const Fractions& a);

    friend std::istream& operator>>(std::istream& in, Fractions& a);
};
}  // namespace ClassFractions
