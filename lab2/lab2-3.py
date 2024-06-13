import random
import math

# Генерация случайных параметров эллипса и точки
a = random.uniform(1, 10)  # Длина большой полуоси
b = random.uniform(1, a)   # Длина малой полуоси
h = random.uniform(-5, 5)  # Смещение центра эллипса по оси x
k = random.uniform(-5, 5)  # Смещение центра эллипса по оси y
x = random.uniform(-10, 10)  # Координата точки x
y = random.uniform(-10, 10)  # Координата точки y

# Уравнение эллипса: ((x-h)^2 / a^2) + ((y-k)^2 / b^2) = 0
def is_point_on_ellipse(x, y, h, k, a, b):
    return ((x - h)**2 / a**2) + ((y - k)**2 / b**2) <= 1

# Координаты фокусов эллипса
def ellipse_foci(h, k, a, b):
    c = math.sqrt(a**2 - b**2)
    return (h + c, k), (h - c, k)

# Длина большой полуоси (a) и малой полуоси (b)
def semi_axes(a, b):
    return a, b

# Эксцентриситет эллипса
def eccentricity(a, b):
    c = math.sqrt(a**2 - b**2)
    return c / a

# Расстояние от директрис до центра эллипса
def directrix_distance(a, e):
    return a / e

# Проверка принадлежности точки эллипсу
belongs_to_ellipse = is_point_on_ellipse(x, y, h, k, a, b)

# Вычисления
foci = ellipse_foci(h, k, a, b)
semi_axes_lengths = semi_axes(a, b)
e = eccentricity(a, b)
directrix_dist = directrix_distance(a, e)

# Вывод результатов
print(f"Уравнение эллипса: ((x-{h})^2 / {a**2}) + ((y-{k})^2 / {b**2}) = 1")
print(f"Точка: ({x}, {y})")
print(f"Принадлежит ли точка эллипсу? {'Да' if belongs_to_ellipse else 'Нет'}")
print(f"Координаты фокусов эллипса: {foci}")
print(f"Длины полуосей эллипса: большая полуось = {semi_axes_lengths[0]}, малая полуось = {semi_axes_lengths[1]}")
print(f"Эксцентриситет эллипса: {e}")
print(f"Расстояние от директрис эллипса до его центра: {directrix_dist}")
