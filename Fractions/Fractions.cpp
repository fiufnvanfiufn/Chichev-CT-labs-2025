#include "Fractions.hpp"

namespace ClassFractions{
Fractions::Fractions() {
    _numerator = 0;
    _denominator = 0;
}

Fractions::Fractions(int integerPart, int numerator, int denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero!");
    }

    this->_numerator = numerator + denominator * integerPart;
    this->_denominator = denominator;

    ShortenFraction();
}

Fractions::Fractions(const Fractions& ex) {
    this->_numerator = ex._numerator;
    this->_denominator = ex._denominator;
}

Fractions::Fractions(const char* line) {
    int integerPart{};
    int numerator{};
    int denominator{};

    if (sscanf(line, "%d %d/%d", &integerPart, &numerator, &denominator) == 3) {
        sscanf(line, "%d/%d", &integerPart, &numerator, &denominator);
    } else if (sscanf(line, "%d %d/%d", &integerPart, &numerator, &denominator) == 2) {
        sscanf(line, "%d/%d", &numerator, &denominator);
    } else if (sscanf(line, "%d %d/%d", &integerPart, &numerator, &denominator) == 1){
        sscanf(line, "%d", &integerPart);
    } else {
        std::cout << "Вы неправильно задали дробь" << std::endl;
    }

    SetNumerator(numerator + denominator * integerPart);
    SetDenominator(denominator);
}

Fractions& Fractions::operator=(const Fractions& other) {
    if (this == &other) {
        return *this;
    }

    _numerator = other._numerator;
    _denominator = other._denominator;

    ShortenFraction();

    return *this;
}

Fractions::Fractions(double x) {
    int whole{};
    int fraction{};
    int dec = 1;

    SplitDouble(x, whole, fraction, dec);

    if (whole < 0) {
        fraction *= -1;
    }

    this->_numerator = fraction + whole * dec;
    this->_denominator = dec;

    ShortenFraction();
}

Fractions& Fractions::operator=(const char* line) {
    int integerPart{};
    int numerator{};
    int denominator = 1;

    if (sscanf(line, "%d %d/%d", &integerPart, &numerator, &denominator) == 3) {
        SetNumerator(numerator + integerPart * denominator);
        SetDenominator(denominator);
        ShortenFraction();
        return *this;
    } else if (sscanf(line, "%d/%d", &numerator, &denominator) == 2) {
        integerPart = 0;
        SetNumerator(numerator + integerPart * denominator);
        SetDenominator(denominator);
        ShortenFraction();
        return *this;
    } else if (sscanf(line, "%d", &integerPart) == 1){
        numerator = 0;
        denominator = 1;
        SetNumerator(numerator + integerPart * denominator);
        SetDenominator(denominator);
        ShortenFraction();
        return *this;
    } else {
        std::cout << "Вы неправильно задали дробь" << std::endl;
    }

    return *this;
};
Fractions& Fractions::operator=(double x) {
    int whole{};
    int fraction{};
    int dec = 1;

    SplitDouble(x, whole, fraction, dec);

    if (whole < 0) {
        fraction *= -1;
    }

    SetNumerator(fraction + whole * dec);
    SetDenominator(dec);

    ShortenFraction();
    return *this;
}

void Fractions::SplitDouble(double num, int& whole, int& fraction, int& dec) {
    double fracPart;
    whole = static_cast<int>(num);
    fracPart = fabs(num - whole);
    while (fracPart != floor(fracPart)) {
        fracPart *= 10;
        dec *= 10;
    }

    fraction = static_cast<int>(fracPart);
}

int Fractions::Get_Numerator() {
    return _numerator;
}

int Fractions::Get_Denominator() {
    return _denominator;
}

void Fractions::ShortenFraction() {
    int gcd = std::gcd(this->_numerator, this->_denominator);
    _numerator /= gcd;
    _denominator /= gcd;
}

Fractions Fractions::operator+(const Fractions& ex) const {
    int a = std::gcd(ex._denominator, this->_denominator);

    int new_numerator = this->_numerator * ex._denominator + ex._numerator * this->_denominator;
    int new_denominator = this->_denominator * ex._denominator;

    Fractions result(0, new_numerator, new_denominator);
    result.ShortenFraction();

    return result;
}

Fractions Fractions::operator+(double x) {
    Fractions a(x);
    Fractions b(*this + a);
    return b;
}

Fractions Fractions::operator+(int x) {
    Fractions a(x, 0, 1);
    Fractions b(*this + a);
    return b;
}

Fractions Fractions::operator+=(const Fractions& x){
    *this = *this + x;
    return *this;
}

Fractions Fractions::operator+=(int x) {
    Fractions a(x, 0, 1);
    *this += a;
    ShortenFraction();
    return *this;
}

Fractions Fractions::operator+=(double x) {
    Fractions a(x);
    *this += a;
    ShortenFraction();
    return *this;
}
}  // namespace ClassFractions
