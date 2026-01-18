#include <stdio.h>
#include <math.h>

typedef double (*Func)(double);

// Метод дихотомии
// Возвращает корень или NAN, если f(a)*f(b) >= 0
double bisection(Func f, double a, double b, double eps, int max_iter) {
    if (f(a) * f(b) >= 0) {
        return NAN;
    }

    double c;
    for (int i = 0; i < max_iter; i++) {
        c = (a + b) / 2.0;
        if (fabs(b - a) < eps) {
            return c;
        }
        if (f(a) * f(c) < 0) {
            b = c;
        }
        else {
            a = c;
        }
    }
    return c; // возвращаем последнее приближение
}

// Пример функции
double f(double x) {
    return x + powl(x, 0.5) + powl(x,0.333)-2.5;
}

// Пример использования
int main() {
    double root = bisection(f, 0.4, 1.0, 1e-12, 100);
    if (isnan(root)) {
        printf("Дихотомия: ошибка — нет смены знака.\n");
    }
    else {
        printf("=== ===\n");
        printf("%.12f\n", root);
        
    }
    return 0;
}
