import random
import numpy as np

# Генерация случайных параметров эллипсоида, плоскости, прямой и точки
a = random.uniform(1, 10)
b = random.uniform(1, a)
c = random.uniform(1, b)
h = random.uniform(-5, 5)
k = random.uniform(-5, 5)
l = random.uniform(-5, 5)
x = random.uniform(-10, 10)
y = random.uniform(-10, 10)
z = random.uniform(-10, 10)
plane = (random.uniform(-5, 5), random.uniform(-5, 5), random.uniform(-5, 5), random.uniform(-5, 5))
line_point = (random.uniform(-10, 10), random.uniform(-10, 10), random.uniform(-10, 10))
line_dir = (random.uniform(-1, 1), random.uniform(-1, 1), random.uniform(-1, 1))

# Уравнение эллипсоида: ((x-h)^2 / a^2) + ((y-k)^2 / b^2) + ((z-l)^2 / c^2) = 1
def is_point_on_ellipsoid(x, y, z, h, k, l, a, b, c):
    return ((x - h)**2 / a**2) + ((y - k)**2 / b**2) + ((z - l)**2 / c**2) <= 1

# Проверка пересечения плоскости с эллипсоидом
def is_plane_intersect_ellipsoid(plane, h, k, l, a, b, c):
    A, B, C, D = plane
    A2 = A**2 / a**2
    B2 = B**2 / b**2
    C2 = C**2 / c**2
    D2 = (D + A*h + B*k + C*l)**2 / (a**2 * b**2 * c**2)
    return (A2 + B2 + C2) * (h**2 / a**2 + k**2 / b**2 + l**2 / c**2) >= D2

# Проверка пересечения прямой с эллипсоидом
def is_line_intersect_ellipsoid(line_point, line_dir, h, k, l, a, b, c):
    x0, y0, z0 = line_point
    dx, dy, dz = line_dir
    A = dx**2 / a**2 + dy**2 / b**2 + dz**2 / c**2
    B = 2 * ((x0 - h) * dx / a**2 + (y0 - k) * dy / b**2 + (z0 - l) * dz / c**2)
    C = (x0 - h)**2 / a**2 + (y0 - k)**2 / b**2 + (z0 - l)**2 / c**2 - 1
    D = B**2 - 4 * A * C
    return D >= 0

# Проверка принадлежности точки эллипсоиду
belongs_to_ellipsoid = is_point_on_ellipsoid(x, y, z, h, k, l, a, b, c)

# Проверка пересечения плоскости с эллипсоидом
plane_intersects_ellipsoid = is_plane_intersect_ellipsoid(plane, h, k, l, a, b, c)

# Проверка пересечения прямой с эллипсоидом
line_intersects_ellipsoid = is_line_intersect_ellipsoid(line_point, line_dir, h, k, l, a, b, c)

# Вывод результатов
print(f"Уравнение эллипсоида: ((x-{h})^2 / {a**2}) + ((y-{k})^2 / {b**2}) + ((z-{l})^2 / {c**2}) = 1")
print(f"Точка: ({x}, {y}, {z})")
print(f"Принадлежит ли точка эллипсоиду? {'Да' if belongs_to_ellipsoid else 'Нет'}")
print(f"Плоскость: {plane[0]}x + {plane[1]}y + {plane[2]}z + {plane[3]} = 0")
print(f"Пересекает ли плоскость эллипсоид? {'Да' if plane_intersects_ellipsoid else 'Нет'}")
print(f"Прямая: точка ({line_point[0]}, {line_point[1]}, {line_point[2]}), направление ({line_dir[0]}, {line_dir[1]}, {line_dir[2]})")
print(f"Пересекает ли прямая эллипсоид? {'Да' if line_intersects_ellipsoid else 'Нет'}")
