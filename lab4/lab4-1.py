import numpy as np

def inverse_matrix(coefficients):
    return np.linalg.inv(coefficients)

def gaussian_elimination(coefficients, constants):
    n = len(coefficients)
    for i in range(n):
        max_index = i
        for j in range(i + 1, n):
            if abs(coefficients[j][i]) > abs(coefficients[max_index][i]):
                max_index = j
        coefficients[i], coefficients[max_index] = coefficients[max_index], coefficients[i]
        constants[i], constants[max_index] = constants[max_index], constants[i]
        for j in range(i + 1, n):
            factor = coefficients[j][i] / coefficients[i][i]
            for k in range(i, n):
                coefficients[j][k] -= factor * coefficients[i][k]
            constants[j] -= factor * constants[i]
    solution = [0] * n
    for i in range(n - 1, -1, -1):
        solution[i] = constants[i] / coefficients[i][i]
        for j in range(i - 1, -1, -1):
            constants[j] -= coefficients[j][i] * solution[i]
    return solution


coefficients = [[7, 8, 4, -6],
                 [-1, 6, -2, -6],
                 [2, 9, 6, -4],
                 [5, 9, 1, 1]]
constants = [-126, -42, -115, -67]

# Решение методом обратной матрицы
inverse = inverse_matrix(coefficients)
solution_inverse = np.dot(inverse, constants)
print("Solution using inverse matrix method:", solution_inverse)

# Решение методом Гаусса
solution_gaussian = gaussian_elimination(coefficients, constants)
print("Solution using Gaussian elimination method:", solution_gaussian)
