#pragma once
#include <cstring>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <cmath>

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

    friend Fractions operator+(int a, const Fractions& b) {
        Fractions x(a, 0, 1);
        return x + b;
    }

    friend Fractions operator+(double a, const Fractions& b) {
        Fractions x(a);
        return x + b;
    }

    friend std::ostream& operator<<(std::ostream& out, const Fractions& a) {
        if (a._denominator == 0) {
            out << "знаменатель равен 0!" << std::endl;
            return out;
        }

        if (std::abs(a._numerator / a._denominator) < 1 && a._numerator != 0) {
            out << a._numerator << '/' << a._denominator << std::endl;
        } else if (a._numerator == 0) {
            out << a._numerator / a._denominator << std::endl;
        } else if (std::abs(a._denominator == 1)) {
            out << a._numerator << std::endl;
        } else {
            out << a._numerator / a._denominator << ' ' << std::abs(a._numerator - a._denominator * (a._numerator / a._denominator)) << '/' << a._denominator << std::endl;
        }

        return out;
    }

    friend std::istream& operator>>(std::istream& in, Fractions& a) {
        char* line = new char[30];
        in >> line;
        a = line;
        return in;
    }
};
}  // namespace ClassFractions
