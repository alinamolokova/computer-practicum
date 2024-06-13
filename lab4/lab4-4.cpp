#include <iostream>
#include <vector>

// Функция для решения СЛАУ методом прогонки
std::vector<double> solve_with_tridiagonal_matrix_algorithm(std::vector<std::vector<double>>& coefficients, std::vector<double>& constants) {
    int n = coefficients.size();
    std::vector<double> alpha(n), beta(n), solution(n);

    // Прямой ход прогонки
    alpha[0] = 0;
    beta[0] = constants[0] / coefficients[0][1];
    for (int i = 1; i < n - 1; ++i) {
        double m = coefficients[i][i + 1] / (coefficients[i][i] - coefficients[i][i - 1] * alpha[i - 1]);
        alpha[i] = -m * coefficients[i][i - 1];
        beta[i] = (constants[i] - coefficients[i][i - 1] * beta[i - 1]) / (coefficients[i][i] - coefficients[i][i - 1] * alpha[i - 1]);
    }
    beta[n - 1] = (constants[n - 1] - coefficients[n - 1][n - 2] * beta[n - 2]) / (coefficients[n - 1][n - 1] - coefficients[n - 1][n - 2] * alpha[n - 2]);

    // Обратный ход прогонки
    solution[n - 1] = beta[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        solution[i] = alpha[i] * solution[i + 1] + beta[i];
    }

    return solution;
}

// Главная функция
int main() {
    std::vector<std::vector<double>> coefficients = {{0, 6, 0, 0, 0},
                                                     {2, 10, -7, 0, 0},
                                                     {0, -8, 18, 9, 0},
                                                     {0, 0, 6, -17, -6},
                                                     {0, 0, 0, 9, 14}};
    std::vector<double> constants = {30, -31, 108, -114, 124};

    std::vector<double> solution = solve_with_tridiagonal_matrix_algorithm(coefficients, constants);
    std::cout << "Solution using tridiagonal matrix algorithm:" << std::endl;
    for (int i = 0; i < solution.size(); ++i) {
        std::cout << "x_" << i + 1 << " = " << solution[i] << std::endl;
    }

    return 0;
}
