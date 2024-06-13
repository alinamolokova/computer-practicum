#include <iostream>
#include <vector>
#include <cmath>

// Функция для вычисления детерминанта матрицы 3x3
double determinant(std::vector<std::vector<double>>& matrix) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
           matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
           matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

// Функция для решения системы линейных уравнений методом Крамера
std::vector<double> solve_with_cramers_rule(std::vector<std::vector<double>>& coefficients, std::vector<double>& constants) {
    std::vector<double> solution;
    double detA = determinant(coefficients);
    if (detA == 0) {
        std::cerr << "Determinant of the coefficient matrix is zero. Cramer's rule cannot be applied." << std::endl;
        return solution;
    }
    int n = coefficients.size();
    for (int i = 0; i < n; ++i) {
        std::vector<std::vector<double>> temp_matrix = coefficients;
        for (int j = 0; j < n; ++j) {
            temp_matrix[j][i] = constants[j];
        }
        solution.push_back(determinant(temp_matrix) / detA);
    }
    return solution;
}

// Функция для проверки сходимости метода Якоби
bool is_convergent(std::vector<std::vector<double>>& coefficients) {
    int n = coefficients.size();
    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                sum += std::abs(coefficients[i][j]);
            }
        }
        if (std::abs(coefficients[i][i]) <= sum) {
            return false;
        }
    }
    return true;
}

// Функция для решения СЛАУ методом Якоби
std::vector<double> solve_with_jacobi_method(std::vector<std::vector<double>>& coefficients, std::vector<double>& constants, double epsilon = 1e-6) {
    std::vector<double> solution(coefficients.size(), 0);
    int n = coefficients.size();
    if (!is_convergent(coefficients)) {
        std::cerr << "The Jacobi method may not converge for this system." << std::endl;
        return solution;
    }
    std::vector<double> prev_solution(n, 0);
    double max_error = epsilon + 1;
    int iterations = 0;
    while (max_error > epsilon) {
        max_error = 0;
        for (int i = 0; i < n; ++i) {
            prev_solution[i] = solution[i];
            double sum = constants[i];
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    sum -= coefficients[i][j] * prev_solution[j];
                }
            }
            solution[i] = sum / coefficients[i][i];
            max_error = std::max(max_error, std::abs(solution[i] - prev_solution[i]));
        }
        iterations++;
    }
    std::cout << "Number of iterations: " << iterations << std::endl;
    return solution;
}

// Главная функция
int main() {
    std::vector<std::vector<double>> coefficients = {{7, -3, 2}, {1, -8, 1}, {6, -6, 2}};
    std::vector<double> constants = {1, 1, -1};

    // Решение с помощью метода Крамера
    std::vector<double> solution_cramer = solve_with_cramers_rule(coefficients, constants);
    if (!solution_cramer.empty()) {
        std::cout << "Solution using Cramer's rule:" << std::endl;
        for (int i = 0; i < solution_cramer.size(); ++i) {
            std::cout << "x_" << i + 1 << " = " << solution_cramer[i] << std::endl;
        }
    }
    std::cout << std::endl;

    // Решение с помощью метода Якоби
    std::vector<double> solution_jacobi = solve_with_jacobi_method(coefficients, constants);
    if (!solution_jacobi.empty()) {
        std::cout << "Solution using the Jacobi method:" << std::endl;
        for (int i = 0; i < solution_jacobi.size(); ++i) {
            std::cout << "x_" << i + 1 << " = " << solution_jacobi[i] << std::endl;
        }
    }

    return 0;
}
