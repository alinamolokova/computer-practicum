#include <iostream>
#include <cmath>

double series_term(int k, double x) {
    return std::pow(-1, k) / (std::sin(k * x) + 1 + std::pow(k, 2));
}

double numerical_series_sum(double epsilon, double x) {
    double sum = 0;
    int k = 1;
    double term = series_term(k, x);
    while (std::abs(term) >= epsilon) {
        sum += term;
        k++;
        term = series_term(k, x);
    }
    return sum;
}

int main() {
    double epsilon = 1e-6; // Требуемая точность
    double x = 1.0; // Значение x
    double sum = numerical_series_sum(epsilon, x);
    std::cout << "Сумма функционального ряда: " << sum << std::endl;
    return 0;
}
