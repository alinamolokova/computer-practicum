import numpy as np

def f(x):
    return np.exp(-2 * x) * np.sin(9 * x)

def rectangle_method(f, a, b, n):
    h = (b - a) / n
    integral = 0
    for i in range(n):
        integral += f(a + i * h)
    integral *= h
    return integral

a = 0
b = 10  # большое число, приближающееся к бесконечности
n = 1000  # количество прямоугольников
result_rectangle = rectangle_method(f, a, b, n)
print("Метод прямоугольников:", result_rectangle)


def trapezoidal_method(f, a, b, n):
    h = (b - a) / n
    integral = (f(a) + f(b)) / 2
    for i in range(1, n):
        integral += f(a + i * h)
    integral *= h
    return integral

result_trapezoidal = trapezoidal_method(f, a, b, n)
print("Метод трапеций:", result_trapezoidal)


def simpsons_method(f, a, b, n):
    h = (b - a) / n
    integral = f(a) + f(b)
    for i in range(1, n, 2):
        integral += 4 * f(a + i * h)
    for i in range(2, n - 1, 2):
        integral += 2 * f(a + i * h)
    integral *= h / 3
    return integral

result_simpsons = simpsons_method(f, a, b, n)
print("Метод Симпсона:", result_simpsons)
