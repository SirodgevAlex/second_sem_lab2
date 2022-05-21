#pragma once

#include <iostream>

using namespace std;

template<class T>
class Complex {
public:
    int x, y;
public:
    Complex() {
        x = 0;
        y = 0;
    }
    Complex(T a, T b) {
        x = a;
        y = b;
    }
};


template <typename T>
Complex<T> operator + (Complex<T> n1, Complex<T> n2){
    //ComplexNumber<T> number = new ComplexNumber<T>;
    Complex<T>* number = (Complex<T>*) malloc(sizeof(Complex<T>));
    number->x = n1.x + n2.x;
    number->y = n1.y + n2.y;
    return *number;
}

template <typename T>
Complex<T> operator - (Complex<T> n1, Complex<T> n2){
    //ComplexNumber<T> number = new ComplexNumber<T>;
    Complex<T>* number = (Complex<T>*) malloc(sizeof(Complex<T>));
    number->x = n1.x - n2.x;
    number->y = n1.y - n2.y;
    return *number;
}

template <typename T>
Complex<T> operator * (Complex<T> n1, Complex<T> n2){
    //ComplexNumber<T> number = new ComplexNumber<T>;
    Complex<T>* number = (Complex<T>*) malloc(sizeof(Complex<T>));
    number->x = n1.x * n2.x - n1.y * n2.y;
    number->y = n1.x * n2.y + n2.x * n1.y;
    return *number;
}

template <typename T>
int operator == (Complex<T> n1, Complex<T> n2){
    if (n1.x == n2.x && n1.y == n2.y){
        return 1;
    }
    return 0;
}

template <typename T>
Complex<T> operator * (float n1, Complex<T> n2){
    //ComplexNumber<T> number = new ComplexNumber<T>;
    Complex<T>* number = (Complex<T>*) malloc(sizeof(Complex<T>));
    number->x = n2.x * n1;
    number->y = n2.y * n1;
    return *number;
}

template <typename T>
std::ostream& operator<< (std::ostream &out, const Complex<T> &number)
{
    out << "(" << number.x << ", " << number.y << ")";
    return out;
}

template <typename T>
std::istream& operator>> (std::istream &in, Complex<T> &number)
{

    in >> number.x;
    in >> number.y;

    return in;
}