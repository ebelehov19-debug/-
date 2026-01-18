#include <stdio.h>
#include <math.h>

typedef double (*Func)(double);
typedef double (*DerivFunc)(double);

// Метод Ньютона
double newton(Func f, DerivFunc df, double x0, double eps, int max_iter) {
    double x = x0;
    for (int i = 0; i < max_iter; i++) {
        double fx = f(x);
        double dfx = df(x);
        if (fabs(dfx) < 1e-14) {
            return NAN; // производная ~ 0 — остановка
        }
        double x_new = x - fx / dfx;
        if (fabs(x_new - x) < eps) {
            return x_new;
        }
        x = x_new;
    }
    return x; // последнее приближение
}

// Пример: f(x) = x^2 - 2
double f(double x) { return 0.1*x * x - x*log(x); }
double df(double x) { return 0.2 * log(x) - 1; }

// Пример использования
int main() {
    double root = newton(f, df, 2, 1e-12, 20);
    if (isnan(root)) {
        printf("Ньютон: ошибка — производная близка к нулю.\n");
    }
    else {
        printf("===  ===\n");
        printf("Корень: %.12f\n", root);
    }
    return 0;
}
