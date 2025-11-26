#ifndef _MY_COMPLEX_H_
#define _MY_COMPLEX_H_
#include <iostream>
using namespace std;

// Класс Complex представляет комплексное число и основные операции над ним.
class Complex
{
private:
    double Re;
    double Im;

public:
    // Конструкторы и деструктор
    Complex( double aRe = 0, double aIm = 0 );
    Complex( const Complex& );
    ~Complex();

    // Методы класса
    void Set( double aRe, double aIm = 0 );
    operator double();
    double abs();

    // Операторы ввода-вывода
    friend istream& operator>>( istream&, Complex& );
    friend ostream& operator<<( ostream&, Complex& );

    // Арифметические операторы с комплексными числами
    Complex operator+( const Complex& );
    Complex operator-( const Complex& );
    Complex operator*( const Complex& );

    // Арифметические операторы с вещественными числами
    Complex operator+( const double& );
    Complex operator-( const double& );
    Complex operator*( const double& );
    Complex operator/( const double& );

    // Дружественные арифметические операторы
    friend Complex operator+( const double&, const Complex& );
    friend Complex operator-( const double&, const Complex& );
    friend Complex operator*( const double&, const Complex& );

    // Операторы присваивания с комплексными числами
    Complex& operator+=( const Complex& );
    Complex& operator-=( const Complex& );
    Complex& operator*=( const Complex& );

    // Операторы присваивания с вещественными числами
    Complex& operator+=( const double& );
    Complex& operator-=( const double& );
    Complex& operator*=( const double& );
    Complex& operator/=( const double& );

    // Операторы присваивания
    Complex& operator=( const Complex& );
    Complex& operator=( const double& );
};

#endif
