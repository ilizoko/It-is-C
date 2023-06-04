#include <iostream>
#include <ctime>
using namespace std;

// поиск прямой на которой лежит  максимальное число точек. 
#define X 0
#define Y 1

// y=kx+b
double Calc_K(double x1, double y1, double x2, double y2)
{
    return (y1 - y2) / (x1 - x2);
}

// y=kx+b
double Calc_B(double x1, double y1, double x2, double y2)
{
    return (y2 * x1 - y1 * x2) / (x1 - x2);
}

int main()
{

    double k, b, finder[2][2];
    int counter, temp = -1, n;

    cout << "Enter number points( n>2 ): ";
    
    cin >> n;
    while (n <= 2) {
        cout << "\nWrong number. n must be more than 2, try again.";
        cin >> n;
    }

    //Создаем координаты точек. 
    srand(time(0));
    double** points = new  double* [n];
    for (int i = 0; i < n; i++)
    {
        points[i] = new double[2];
        //cout << "Enter pair[" << i + 1 << "]:\nx: "; cin >> Points[i][X];
        //cout << "y: ";                                                 cin >> Points[i][Y];
        points[i][X] = rand() % 10 + 1;
        points[i][Y] = rand() % 10 + 1;
    }

    for (int i = 1; i < n; i++)
    {
        //Вычисление коэффициентов k и b
        k = Calc_K(points[i - 1][X], points[i - 1][Y], points[i][X], points[i][Y]);
        b = Calc_B(points[i - 1][X], points[i - 1][Y], points[i][X], points[i][Y]);
        counter = 2;
        for (int j = i + 1; j < n; j++)
        {
            if (points[j][Y] == k * points[j][X] + b) ++counter;
        }
        if (counter > temp)
        {
            temp = counter;
            finder[0][X] = points[i - 1][X]; finder[1][X] = points[i][X];
            finder[0][Y] = points[i - 1][Y]; finder[1][Y] = points[i][Y];
        }
    }
    temp = n - temp;

    cout << "Min points: " << temp << "\n line:: x1: " << finder[0][X] << " y1: " << finder[0][Y]
        << "\n        x2: " << finder[1][X] << " y2: " << finder[1][Y] << endl;

    //Чистим память.
    for (int i = 0; i < n; i++)
        delete[] points[i];
    delete[] points;
}
