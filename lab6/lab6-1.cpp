#include <iostream>
#include <cmath>
#include <vector>

double f(double x1, double x2) {
    return x1 + 5 * x2 + std::exp(x1 * x1 + x2 * x2);
}

double df_dx1(double x1, double x2) {
    return 1 + 2 * x1 * std::exp(x1 * x1 + x2 * x2);
}

double df_dx2(double x1, double x2) {
    return 5 + 2 * x2 * std::exp(x1 * x1 + x2 * x2);
}

int main() {
    double x1 = 0.0, x2 = 0.0; // Начальная точка
    double alpha = 0.01; // Шаг обучения
    double tolerance = 1e-6; // Критерий остановки
    int max_iter = 10000; // Максимальное количество итераций
    int iter = 0;

    while (iter < max_iter) {
        // Обновление x1, фиксируя x2
        double grad1 = df_dx1(x1, x2);
        double new_x1 = x1 - alpha * grad1;

        // Обновление x2, фиксируя x1
        double grad2 = df_dx2(new_x1, x2);
        double new_x2 = x2 - alpha * grad2;

        // Проверка критерия остановки
        if (std::abs(new_x1 - x1) < tolerance && std::abs(new_x2 - x2) < tolerance) {
            break;
        }

        x1 = new_x1;
        x2 = new_x2;
        iter++;
    }

    std::cout << "Minimum found at: (" << x1 << ", " << x2 << ")" << std::endl;
    std::cout << "Function value at minimum: " << f(x1, x2) << std::endl;

    return 0;
}
