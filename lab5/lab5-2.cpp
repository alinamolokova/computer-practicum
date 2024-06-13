#include <iostream>
#include <vector>
#include <cmath>

// Функция для вычисления значения интерполяционного многочлена Ньютона в точке x
double newton_interpolation(double x, const std::vector<double>& xi, const std::vector<double>& yi) {
    int n = xi.size();
    double result = 0;
    for (int i = 0; i < n; ++i) {
        double term = yi[i];
        for (int j = 0; j < i; ++j) {
            term *= (x - xi[j]);
        }
        for (int j = 0; j < i; ++j) {
            term /= (xi[i] - xi[j]);
        }
        result += term;
    }
    return result;
}

// Функция для вычисления погрешности интерполяции в точке x
double interpolation_error(double x, const std::vector<double>& xi, const std::vector<double>& yi) {
    double true_value = std::cos(x);
    double interpolated_value = newton_interpolation(x, xi, yi);
    return std::abs(true_value - interpolated_value);
}

int main() {
    // Заданные значения xi и yi
    std::vector<double> xi = {0.1 * M_PI, 0.2 * M_PI, 0.3 * M_PI, 0.4 * M_PI};
    std::vector<double> yi;
    for (double x : xi) {
        yi.push_back(std::cos(x));
    }

    // Точка, в которой вычисляется погрешность интерполяции
    double x = 0.25 * M_PI;

    // Вычисление значения интерполяционного многочлена Ньютона
    double interpolated_value = newton_interpolation(x, xi, yi);
    std::cout << "Interpolated value at x = " << x << ": " << interpolated_value << std::endl;

    // Вычисление погрешности интерполяции
    double error = interpolation_error(x, xi, yi);
    std::cout << "Interpolation error at x = " << x << ": " << error << std::endl;

    return 0;
}
