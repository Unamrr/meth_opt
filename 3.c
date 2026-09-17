#include <iostream>
using namespace std;

// Наша функция
double func(double x)
{
    return x * x - 4 * x + 6;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    double left = 0;
    double right = 10;
    double eps = 0.2;
    double target_len = 1;

    int step = 0;

    while (right - left >= target_len)
    {
        double p1 = (left + right - eps) / 2;
        double p2 = (left + right + eps) / 2;

        double fp1 = func(p1);
        double fp2 = func(p2);

        cout << "Шаг " << step << endl;
        cout << "left = " << left << ", right = " << right << endl;
        cout << "p1 = " << p1 << ", f(p1) = " << fp1 << endl;
        cout << "p2 = " << p2 << ", f(p2) = " << fp2 << endl;

        if (fp1 < fp2)
        {
            right = p2;
        }
        else
        {
            left = p1;
        }

        cout << "Новый интервал: [" << left << "; " << right << "]" << endl;
        cout << "Длина интервала: " << right - left << endl;
        cout << endl;

        step++;
    }

    double xmin = (left + right) / 2;
    double fmin = func(xmin);

    cout << "Результат:" << endl;
    cout << "Интервал минимума: [" << left << "; " << right << "]" << endl;
    cout << "Приближённая точка минимума x = " << xmin << endl;
    cout << "Минимальное значение функции f(x) = " << fmin << endl;

    return 0;
}
