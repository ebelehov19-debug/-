#include <stdio.h>
#include <math.h>

typedef double (*IterFunc)(double);

// Метод простых итераций: x = g(x)
double fixed_point(IterFunc g, double x0, double eps, int max_iter) {
    double x = x0;
    for (int i = 0; i < max_iter; i++) {
        double x_new = g(x);
        if (fabs(x_new - x) < eps) {
            return x_new;
        }
        x = x_new;
    }
    return x; // последнее приближение
}

// Исходная функция для проверки
double f(double x) {
    return x * x - 2.0;
}

// Итерационная функция: x = 0.5*(x + 2/x)
double g(double x) {
    return 0.5 * (x + 2.0 / x);
}

// Пример использования
int main() {
    double root = fixed_point(g, 1.0, 1e-12, 50);
    printf("=== Метод простых итераций ===\n");
    printf("Корень: %.12f\n", root);
    printf("f(корень): %.2e\n\n", f(root));
    return 0;
}
