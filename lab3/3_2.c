#include <iostream>
#include<cmath>
using namespace std;


double func(double x)
{
    return x * x - 4 * x + 6;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    double left = 0;
    double right = 10;
    double target_len = 1;

    int iter = 0;

    double fi = (sqrt(5) - 1) / 2;
    double y = left + (1 - fi) * (right - left);
    double z = left + fi * (right - left);
    //double y = left + 0.382 * (right - left);
    //double z = left + right - y;

    double fy = func(y);
    double fz = func(z);

    while (right - left >= target_len)
    {
        cout << "итерация: " << iter << endl;
        cout << "left = " << left << ", right = " << right << endl;
        cout << "y = " << y << ", f(y) = " << fy << endl;
        cout << "z = " << z << ", f(z) = " << fz << endl;

        if (fy <= fz)
        {

            right = z;
            z = y;
            fz = fy;
            y = left + right - z;
            fy = func(y);
        }
        else
        {
            left = y;
            y = z;
            fy = fz;
            z = left + right - y;
            fz = func(z);
        }

        cout << "Новый интервал: [" << left << "; " << right << "]" << endl;
        cout << "Длина интервала: " << right - left << endl;
        cout << endl;

        iter++;
    }

    double xmin = (left + right) / 2;
    double fmin = func(xmin);
    double R = pow(0.618, iter);

    cout << "Результат:" << endl;
    cout << "Интервал минимума: [" << left << "; " << right << "]" << endl;
    cout << "Приближённая точка минимума x = " << xmin << endl;
    cout << "Минимальное значение функции f(x) = " << fmin << endl;
    cout << "Сходимость R =  " << R << endl;

    return 0;
}
