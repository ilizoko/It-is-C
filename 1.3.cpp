// task13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

//Функция isGeron проверяет, является ли треугольник треугольником Герона или нет.
bool isGeron(int a,int b,int c) {
    float sq, h, p;
    p = (a + b + c) / 2;
    sq = sqrt(p * (p - a) * (p - b) * (p - c));
    if (sq == round(sq) && sq != 0) {
        cout << "\nТреугольник со сторонами " << a << " " << b << " " << c << " является треугольником Герона. Площадь равна " << sq;
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    bool isTriangle = false; //является ли треугольником
    int a, b, c; //a, b, c - стороны треугольника. S - площадь.
    int n, counter = 0; //кол-во треугольников, которые нужно найти.
    cout << "Enter N ";
    cin >> n;

    srand( time(0) );

    while (counter < n) {

        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
        c = rand() % 10 + 1;

        if (a + b > c && a + c > b && b + c > a) {
            if (isGeron(a, b, c)) {
                counter++;
            }
        }
    }
}

