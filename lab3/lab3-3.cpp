#include <iostream>
#include <cmath>

double series_term(int k) {
    return 9.0 / std::pow(2, k - 1) + std::pow(-1, k - 1) / (2 * std::pow(3, k - 1));
}

double numerical_series_sum(double epsilon) {
    double sum = 0;
    int k = 1;
    double term = series_term(k);
    while (std::abs(term) >= epsilon) {
        sum += term;
        k++;
        term = series_term(k);
    }
    return sum;
}

int main() {
    double epsilon = 1e-6; // Требуемая точность
    double sum = numerical_series_sum(epsilon);
    std::cout << "Сумма числового ряда: " << sum << std::endl;
    return 0;
}
