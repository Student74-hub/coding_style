/**
 * @file mycomplex.h
 * @brief Объявление класса Complex для работы с комплексными числами.
 */

#ifndef _MY_COMPLEX_H_
#define _MY_COMPLEX_H_
#include <iostream>
using namespace std;

/**
 * @class Complex
 * @brief Класс комплексного числа.
 * @details Хранит действительную и мнимую части и реализует основные операции
 * сложения, вычитания, умножения, деления и вычисления модуля.
 */
class Complex
{
private:
    double Re; ///< Действительная часть комплексного числа
    double Im; ///< Мнимая часть комплексного числа

public:
    /**
     * @brief Создаёт комплексное число.
     * @param aRe Действительная часть (по умолчанию 0).
     * @param aIm Мнимая часть (по умолчанию 0).
     */
    Complex( double aRe = 0, double aIm = 0 );

    /**
     * @brief Конструктор копирования.
     * @param other Копируемое комплексное число.
     */
    Complex( const Complex& other );

    /**
     * @brief Деструктор класса Complex.
     */
    ~Complex();

    /**
     * @brief Устанавливает значения действительной и мнимой частей.
     * @param aRe Действительная часть.
     * @param aIm Мнимая часть (по умолчанию 0).
     */
    void Set( double aRe, double aIm = 0 );

    /**
     * @brief Оператор преобразования к типу double.
     * @return Модуль комплексного числа.
     */
    operator double();

    /**
     * @brief Вычисляет модуль комплексного числа.
     * @return Значение модуля.
     */
    double abs();

    /**
     * @brief Оператор ввода комплексного числа из потока.
     * @param stream Входной поток.
     * @param a Комплексное число для ввода.
     * @return Ссылка на входной поток.
     */
    friend istream& operator>>( istream& stream, Complex& a );

    /**
     * @brief Оператор вывода комплексного числа в поток.
     * @param stream Выходной поток.
     * @param a Комплексное число для вывода.
     * @return Ссылка на выходной поток.
     */
    friend ostream& operator<<( ostream& stream, Complex& a );

    /**
     * @brief Складывает текущее число с другим комплексным числом.
     * @param other Второе комплексное число.
     * @return Результат сложения двух комплексных чисел.
     */
    Complex operator+( const Complex& other );

    /**
     * @brief Вычитает из текущего числа другое комплексное число.
     * @param other Вычитаемое комплексное число.
     * @return Результат вычитания.
     */
    Complex operator-( const Complex& other );

    /**
     * @brief Умножает текущее число на другое комплексное число.
     * @param other Второй множитель.
     * @return Результат умножения.
     */
    Complex operator*( const Complex& other );

    /**
     * @brief Складывает комплексное число с вещественным.
     * @param value Вещественное число.
     * @return Результат сложения.
     */
    Complex operator+( const double& value );

    /**
     * @brief Вычитает из комплексного числа вещественное.
     * @param value Вычитаемое вещественное число.
     * @return Результат вычитания.
     */
    Complex operator-( const double& value );

    /**
     * @brief Умножает комплексное число на вещественное.
     * @param value Вещественный множитель.
     * @return Результат умножения.
     */
    Complex operator*( const double& value );

    /**
     * @brief Делит комплексное число на вещественное.
     * @param value Делитель (вещественное число).
     * @return Результат деления.
     */
    Complex operator/( const double& value );

    /**
     * @brief Складывает вещественное число с комплексным.
     * @param value Вещественное число (левый операнд).
     * @param other Комплексное число (правый операнд).
     * @return Результат сложения.
     */
    friend Complex operator+( const double& value, const Complex& other );

    /**
     * @brief Вычитает из вещественного числа комплексное.
     * @param value Вещественное число (уменьшаемое).
     * @param other Комплексное число (вычитаемое).
     * @return Результат вычитания.
     */
    friend Complex operator-( const double& value, const Complex& other );

    /**
     * @brief Умножает вещественное число на комплексное.
     * @param value Вещественное число (левый множитель).
     * @param other Комплексное число (правый множитель).
     * @return Результат умножения.
     */
    friend Complex operator*( const double& value, const Complex& other );

    /**
     * @brief Прибавляет к текущему числу другое комплексное число.
     * @param other Слагаемое.
     * @return Ссылка на текущий объект.
     */
    Complex& operator+=( const Complex& other );

    /**
     * @brief Вычитает из текущего числа другое комплексное число.
     * @param other Вычитаемое.
     * @return Ссылка на текущий объект.
     */
    Complex& operator-=( const Complex& other );

    /**
     * @brief Умножает текущее число на другое комплексное число.
     * @param other Множитель.
     * @return Ссылка на текущий объект.
     */
    Complex& operator*=( const Complex& other );

    /**
     * @brief Прибавляет к текущему числу вещественное число.
     * @param value Вещественное слагаемое.
     * @return Ссылка на текущий объект.
     */
    Complex& operator+=( const double& value );

    /**
     * @brief Вычитает из текущего числа вещественное число.
     * @param value Вещественное вычитаемое.
     * @return Ссылка на текущий объект.
     */
    Complex& operator-=( const double& value );

    /**
     * @brief Умножает текущее число на вещественное число.
     * @param value Вещественный множитель.
     * @return Ссылка на текущий объект.
     */
    Complex& operator*=( const double& value );

    /**
     * @brief Делит текущее число на вещественное число.
     * @param value Вещественный делитель.
     * @return Ссылка на текущий объект.
     */
    Complex& operator/=( const double& value );

    /**
     * @brief Присваивает текущему числу значение другого комплексного числа.
     * @param other Присваиваемое комплексное число.
     * @return Ссылка на текущий объект.
     */
    Complex& operator=( const Complex& other );

    /**
     * @brief Присваивает текущему числу вещественное значение.
     * @param value Вещественное число (мнимая часть обнуляется).
     * @return Ссылка на текущий объект.
     */
    Complex& operator=( const double& value );
};

#endif
