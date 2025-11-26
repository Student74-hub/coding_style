#include <iostream>
#include <cmath>
#include "mycomplex.h"
using namespace std;

// Конструктор комплексного числа с заданными действительной и мнимой частями
Complex::Complex( double aRe, double aIm )
{
    Re = aRe;
    Im = aIm;
}

// Конструктор копирования
Complex::Complex( const Complex& aRval )
{
    Re = aRval.Re;
    Im = aRval.Im;
}

// Деструктор
Complex::~Complex()
{
    Re = 0.0;
    Im = 0.0;
}

// Установка значений действительной и мнимой частей
void Complex::Set( double aRe, double aIm )
{
    Re = aRe;
    Im = aIm;
}

// Оператор преобразования к типу double (возвращает модуль)
Complex::operator double()
{
    return abs();
}

// Вычисление модуля комплексного числа
double Complex::abs()
{
    return sqrt( Re * Re + Im * Im );
}

// Арифметические операторы с комплексными числами

Complex Complex::operator+( const Complex& aRval )
{
    Complex Result;
    Result.Re = Re + aRval.Re;
    Result.Im = Im + aRval.Im;
    return Result;
}

Complex Complex::operator-( const Complex& aRval )
{
    Complex Result;
    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;
    return Result;
}

// Арифметические операторы с вещественными числами

Complex Complex::operator+( const double& aval )
{
    Complex result;
    result.Re = Re + aval;
    result.Im = Im;
    return result;
}

Complex Complex::operator-( const double& aRval )
{
    Complex Result( *this );
    Result.Re = Re - aRval;
    return Result;
}

Complex Complex::operator*( const Complex& aRval )
{
    Complex Result;
    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;
    return Result;
}

Complex Complex::operator*( const double& aRval )
{
    Complex Result;
    Result.Re = Re * aRval;
    Result.Im = Im * aRval;
    return Result;
}

Complex Complex::operator/( const double& aRval )
{
    Complex Result;
    Result.Re = Re / aRval;
    Result.Im = Im / aRval;
    return Result;
}

// Операторы присваивания с комплексными числами

Complex& Complex::operator+=( const Complex& arval )
{
    Re += arval.Re;
    Im += arval.Im;
    return *this;
}

Complex& Complex::operator-=( const Complex& aRval )
{
    Re -= aRval.Re;
    Im -= aRval.Im;
    return *this;
}

Complex& Complex::operator*=( const Complex& aRval )
{
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}

// Операторы присваивания с вещественными числами

Complex& Complex::operator+=( const double& aRval )
{
    Re += aRval;
    return *this;
}

Complex& Complex::operator-=( const double& aRval )
{
    Re -= aRval;
    return *this;
}

Complex& Complex::operator*=( const double& aRval )
{
    Re *= aRval;
    Im *= aRval;
    return *this;
}

Complex& Complex::operator/=( const double& aRval )
{
    Re /= aRval;
    Im /= aRval;
    return *this;
}

// Операторы присваивания

Complex& Complex::operator=( const Complex& aRval )
{
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}

Complex& Complex::operator=( const double& aRval )
{
    Re = aRval;
    Im = 0.0;
    return *this;
}

// Операторы ввода-вывода

istream& operator>>( istream& stream, Complex& a )
{
    char tmp[256];
    stream >> a.Re >> a.Im >> tmp;
    return stream;
}

ostream& operator<<( ostream& stream, Complex& a )
{
    stream << a.Re;
    if ( !( a.Im < 0 ) )
        stream << '+';
    stream << a.Im << 'i';
    return stream;
}

// Дружественные арифметические операторы (вещественное число слева)

Complex operator+( const double& aLval, const Complex& aRval )
{
    Complex Result;
    Result.Re = aLval + aRval.Re;
    Result.Im = aRval.Im;
    return Result;
}

Complex operator-( const double& aLval, const Complex& aRval )
{
    Complex Result;
    Result.Re = aLval - aRval.Re;
    Result.Im = -aRval.Im;
    return Result;
}

Complex operator*( const double& aLval, const Complex& a )
{
    Complex r;
    r.Re = aLval * a.Re;
    r.Im = aLval * a.Im;
    return r;
}
