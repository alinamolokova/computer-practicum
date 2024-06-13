import numpy as np

# Определение функции
def f(x1, x2):
    return x1 + 2 * x2 + 4 * np.sqrt(1 + x1**2 + x2**2)

# Определение градиента функции
def grad_f(x1, x2):
    df_dx1 = 1 + (4 * x1) / np.sqrt(1 + x1**2 + x2**2)
    df_dx2 = 2 + (4 * x2) / np.sqrt(1 + x1**2 + x2**2)
    return np.array([df_dx1, df_dx2])

# Инициализация
x = np.array([0.0, 0.0])  # Начальная точка
alpha = 0.01  # Шаг обучения
tolerance = 1e-6  # Критерий остановки
max_iter = 10000  # Максимальное количество итераций

# Метод градиентного спуска
for i in range(max_iter):
    grad = grad_f(x[0], x[1])
    new_x = x - alpha * grad
    
    # Проверка критерия остановки
    if np.linalg.norm(new_x - x) < tolerance:
        break
    
    x = new_x

print(f"Minimum found at: ({x[0]}, {x[1]})")
print(f"Function value at minimum: {f(x[0], x[1])}")
