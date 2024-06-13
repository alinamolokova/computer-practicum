import numpy as np

def gauss_seidel(coefficients, constants, initial_guess, tolerance=1e-6, max_iterations=1000):
    n = len(coefficients)
    x = initial_guess[:]
    for _ in range(max_iterations):
        x_new = np.zeros(n)
        for i in range(n):
            x_new[i] = constants[i]
            for j in range(n):
                if j != i:
                    x_new[i] -= coefficients[i][j] * x_new[j]
            x_new[i] /= coefficients[i][i]
        if np.allclose(x, x_new, atol=tolerance):
            return x_new
        x = x_new
    raise ValueError("Gauss-Seidel method did not converge within the maximum number of iterations")

coefficients = [[10, -1, -2, 5],
                [4, 28, 7, 9],
                [6, 5, -23, 4],
                [1, 4, 5, -15]]
constants = [-99, 0, 67, 58]
initial_guess = [0, 0, 0, 0]

solution = gauss_seidel(coefficients, constants, initial_guess)
print("Solution using Gauss-Seidel method:", solution)
