////метод Ньютона
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//// Наша функция
//double f(double x1, double x2) {
//    return x1 * x1 + 5 * x2 * x2 + x1 * x2 + x1;
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//
//    // Начальная точка и параметры
//    double x1 = 1.0, x2 = 1.0;
//    double eps1 = 0.1, eps2 = 0.15;
//    int M = 10;
//    int iter_count = 0;
//
//    cout << "k\t x1\t\t x2\t\t f(x)\n";
//
//    for (int k = 0; k <= M; k++) {
//        // Шаг 3: Градиент
//        double g1 = 2 * x1 + x2 + 1;
//        double g2 = x1 + 10 * x2;
//
//        // Шаг 4: Проверка остановки по градиенту
//        double norm_g = sqrt(g1 * g1 + g2 * g2);
//        if (norm_g < eps1) {
//            cout << "\nОстановка по градиенту! Точка минимума найдена.\n";
//            cout << "x* = (" << x1 << "; " << x2 << ")\n";
//            cout << "f(x*) = " << f(x1, x2) << "\n";
//            cout << "Количество итераций = " << iter_count << endl;
//            break;
//        }
//
//        // Шаг 5: Проверка лимита итераций
//        if (k == M) {
//            cout << "\nДостигнут лимит итераций.\n";
//            cout << "x* = (" << x1 << "; " << x2 << ")\n";
//            cout << "f(x*) = " << f(x1, x2) << "\n";
//            cout << "Количество итераций = " << iter_count << endl;
//            break;
//        }
//
//        // Шаги 6-7: Матрица Гессе и её обратная
//        double h11 = 2.0, h12 = 1.0, h21 = 1.0, h22 = 10.0;
//        double det = h11 * h22 - h12 * h21; // = 19
//
//        // Шаг 8: Проверка положительной определённости
//        bool positive = (h11 > 0 && det > 0);
//        if (!positive) {
//            cout << "Матрица Гессе не положительно определена! Выход.\n";
//            break;
//        }
//
//        // Шаг 9: Направление спуска d = -H^-1 * g
//        double d1 = -(h22 * g1 - h12 * g2) / det;
//        double d2 = -(-h21 * g1 + h11 * g2) / det;
//
//        // Шаг 10: Шаг t = 1
//        double t = 1.0;
//        double x1_new = x1 + t * d1;
//        double x2_new = x2 + t * d2;
//
//        // Шаг 11: Проверка условий остановки
//        double dist = sqrt((x1_new - x1) * (x1_new - x1) + (x2_new - x2) * (x2_new - x2));
//        double diff_f = abs(f(x1_new, x2_new) - f(x1, x2));
//
//        cout << k << "\t " << x1_new << "\t " << x2_new << "\t " << f(x1_new, x2_new) << "\n";
//        iter_count++;
//
//        if (dist < eps2 && diff_f < eps2) {
//            cout << "\nОба условия выполнены! Остановка.\n";
//            cout << "Точка минимума: x* = (" << x1_new << "; " << x2_new << ")\n";
//            cout << "f(x*) = " << f(x1_new, x2_new) << "\n";
//            cout << "Количество итераций = " << iter_count << endl;
//            break;
//        }
//
//        // Переход к следующей точке
//        x1 = x1_new;
//        x2 = x2_new;
//    }
//
//    return 0;
//}

//метод Ньютона - Рафсона
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//double f(double x1, double x2) {
//    return x1 * x1 + 5 * x2 * x2 + x1 * x2 + x1;
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//
//    double x1 = 1.0, x2 = 1.0;
//    double eps1 = 0.1, eps2 = 0.15;
//    int M = 10;
//    int iter_count = 0;
//
//    cout << "k\t x1\t\t x2\t\t t\t\t f(x)\n";
//
//    for (int k = 0; k <= M; k++) {
//        double g1 = 2 * x1 + x2 + 1;
//        double g2 = x1 + 10 * x2;
//
//        double norm_g = sqrt(g1 * g1 + g2 * g2);
//        if (norm_g < eps1) {
//            cout << "\nОстановка по градиенту! Точка минимума найдена.\n";
//            cout << "x* = (" << x1 << "; " << x2 << ")\n";
//            cout << "f(x*) = " << f(x1, x2) << "\n";
//            cout << "Количество итераций = " << iter_count << endl;
//            break;
//        }
//
//        if (k == M) {
//            cout << "\nДостигнут лимит итераций.\n";
//            cout << "x* = (" << x1 << "; " << x2 << ")\n";
//            cout << "f(x*) = " << f(x1, x2) << "\n";
//            cout << "Количество итераций = " << iter_count << endl;
//            break;
//        }
//
//        double h11 = 2.0, h12 = 1.0, h21 = 1.0, h22 = 10.0;
//        double det = h11 * h22 - h12 * h21;
//
//        bool positive = (h11 > 0 && det > 0);
//
//        double d1, d2;
//        if (positive) {
//            d1 = -(h22 * g1 - h12 * g2) / det;
//            d2 = -(-h21 * g1 + h11 * g2) / det;
//        }
//        else {
//            d1 = -g1;
//            d2 = -g2;
//        }
//
//        // Подбор шага t
//        double t = 1.0;
//        double fx = f(x1, x2);
//        double x1_new, x2_new;
//
//        while (true) {
//            x1_new = x1 + t * d1;
//            x2_new = x2 + t * d2;
//            if (f(x1_new, x2_new) < fx) {
//                break;
//            }
//            t /= 2.0;
//            if (t < 1e-12) {
//                cout << "Не удалось подобрать шаг!\n";
//                break;
//            }
//        }
//
//        double dist = sqrt((x1_new - x1) * (x1_new - x1) + (x2_new - x2) * (x2_new - x2));
//        double diff_f = abs(f(x1_new, x2_new) - fx);
//
//        cout << k << "\t " << x1_new << "\t " << x2_new << "\t " << t << "\t " << f(x1_new, x2_new) << "\n";
//        iter_count++;
//
//        if (dist < eps2 && diff_f < eps2) {
//            cout << "\nОба условия выполнены! Остановка.\n";
//            cout << "Точка минимума: x* = (" << x1_new << "; " << x2_new << ")\n";
//            cout << "f(x*) = " << f(x1_new, x2_new) << "\n";
//            cout << "Количество итераций = " << iter_count << endl;
//            break;
//        }
//
//        x1 = x1_new;
//        x2 = x2_new;
//    }
//
//    return 0;
//}


////метод Флетчера- Ривса
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//// Наша функция
//double f(double x1, double x2) {
//    return x1 * x1 + 5 * x2 * x2 + x1 * x2 + x1;
//}
//
//// Вспомогательная функция phi(t) = f(x1 + t*d1, x2 + t*d2)
//double phi(double t, double x1, double x2, double d1, double d2) {
//    return f(x1 + t * d1, x2 + t * d2);
//}
//
//// 1. МЕТОД СВЕННА (поиск интервала [a, b])
//void swenn(double x1, double x2, double d1, double d2, double& a, double& b) {
//    double h = 0.1;
//    double t0 = 0;
//    double t1 = h;
//
//    // Идем вправо, пока функция убывает
//    if (phi(t1, x1, x2, d1, d2) < phi(t0, x1, x2, d1, d2)) {
//        double t2 = t1 + h;
//        while (phi(t2, x1, x2, d1, d2) < phi(t1, x1, x2, d1, d2)) {
//            t0 = t1;
//            t1 = t2;
//            t2 = t2 + h;
//        }
//        a = t0; b = t2;
//    }
//    else {
//        // Если сразу пошли вверх, идем влево
//        double t2 = t1 - h;
//        while (phi(t2, x1, x2, d1, d2) < phi(t1, x1, x2, d1, d2)) {
//            t0 = t1;
//            t1 = t2;
//            t2 = t2 - h;
//        }
//        a = t2; b = t0;
//    }
//}
//
//// 2. МЕТОД ЗОЛОТОГО СЕЧЕНИЯ (уточнение шага t)
//double golden(double a, double b, double x1, double x2, double d1, double d2, double eps_t) {
//    double phi_g = (1 + sqrt(5)) / 2;
//    double y = b - (b - a) / phi_g;
//    double z = a + (b - a) / phi_g;
//
//    while (abs(b - a) > eps_t) {
//        if (phi(y, x1, x2, d1, d2) < phi(z, x1, x2, d1, d2)) {
//            b = z;
//            z = y;
//            y = b - (b - a) / phi_g;
//        }
//        else {
//            a = y;
//            y = z;
//            z = a + (b - a) / phi_g;
//        }
//    }
//    return (a + b) / 2;
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//
//    double x1 = 1.0, x2 = 1.0;
//    double eps1 = 0.1, eps2 = 0.15;
//    int M = 10;
//    int iter_count = 0;
//    double eps_t = 0.000001;
//
//    // Для хранения предыдущих значений
//    double d1_prev = 0, d2_prev = 0;
//    double g1_prev = 0, g2_prev = 0;
//
//    cout << "k\t x1\t\t x2\t\t t\t\t f(x)\n";
//
//    for (int k = 0; k <= M; k++) {
//        // Шаг 3: Градиент
//        double g1 = 2 * x1 + x2 + 1;
//        double g2 = x1 + 10 * x2;
//
//        // Шаг 4: Проверка остановки по градиенту
//        double norm_g = sqrt(g1 * g1 + g2 * g2);
//        if (norm_g < eps1) {
//            cout << "\nОстановка по градиенту.\n";
//            cout << "x* = (" << x1 << "; " << x2 << ")\n";
//            cout << "f(x*) = " << f(x1, x2) << "\n";
//            cout << "Количество итераций = " << iter_count << endl;
//            break;
//        }
//
//        // Шаг 5: Проверка лимита итераций
//        if (k == M) {
//            cout << "\nДостигнут лимит итераций.\n";
//            break;
//        }
//
//        // Шаг 6-8: Выбор направления
//        double d1, d2;
//        if (k == 0) {
//            // Первая итерация: антиградиент
//            d1 = -g1;
//            d2 = -g2;
//        }
//        else {
//            // Вычисляем коэффициент beta
//            double beta = (g1 * g1 + g2 * g2) / (g1_prev * g1_prev + g2_prev * g2_prev);
//            // Новое направление
//            d1 = -g1 + beta * d1_prev;
//            d2 = -g2 + beta * d2_prev;
//            // Если направление не спускается, берем антиградиент
//            if (g1 * d1 + g2 * d2 >= 0) {
//                d1 = -g1;
//                d2 = -g2;
//            }
//        }
//
//        // Шаг 9: Поиск шага t через Свенна + золотое сечение
//        double a, b;
//        swenn(x1, x2, d1, d2, a, b);
//        double t = golden(a, b, x1, x2, d1, d2, eps_t);
//
//        // Шаг 10: Новая точка
//        double x1_new = x1 + t * d1;
//        double x2_new = x2 + t * d2;
//
//        // Шаг 11: Проверка условий остановки
//        double fx = f(x1, x2);
//        double f_new = f(x1_new, x2_new);
//        double dist = sqrt((x1_new - x1) * (x1_new - x1) + (x2_new - x2) * (x2_new - x2));
//        double diff_f = abs(f_new - fx);
//
//        cout << k << "\t " << x1_new << "\t " << x2_new << "\t " << t << "\t " << f_new << "\n";
//        iter_count++;
//
//        if (dist < eps2 && diff_f < eps2) {
//            cout << "\nОба условия выполнены. Остановка.\n";
//            cout << "Точка минимума: x* = (" << x1_new << "; " << x2_new << ")\n";
//            cout << "f(x*) = " << f_new << "\n";
//            cout << "Количество итераций = " << iter_count << endl;
//            break;
//        }
//
//        // Сохраняем предыдущие значения и переходим
//        g1_prev = g1;
//        g2_prev = g2;
//        d1_prev = d1;
//        d2_prev = d2;
//        x1 = x1_new;
//        x2 = x2_new;
//    }
//
//    return 0;
//}
