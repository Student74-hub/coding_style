#include <iostream>
#include "mycomplex.h"
using namespace std;

// Тестирование класса комплексных чисел
int main()
{
    // Создание комплексных чисел
    Complex A, B( -4 ), C( 23.0, 45.9 );
    cout << A << "," << B << "," << C << endl;

    // Сложение комплексных чисел
    A = B + C;
    cout << "A=B+C,A=" << A << endl;

    // Арифметические операции
    Complex M = B - C;
    cout << "M = B - C, M = " << M << endl;
    cout << "M*A=" << M * A << endl;
    cout << "M/4.45=" << M / 4.45 << endl;

    // Ввод комплексного числа с клавиатуры
    Complex D;
    cout << "Enter complex number D = ";
    cin >> D;

    // Операция присваивания с добавлением
    A += C + D;
    cout << "D = " << D << "\nA = " << A << endl;

    return 0;
}
