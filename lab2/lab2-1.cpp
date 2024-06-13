#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

struct Vector {
    double x, y;
};

// Функция для вычисления длины вектора
double length(const Vector& v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

// Функция для вычисления скалярного произведения векторов
double dotProduct(const Vector& v1, const Vector& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

// Функция для вычисления угла между векторами
double angleBetween(const Vector& v1, const Vector& v2) {
    double cosTheta = dotProduct(v1, v2) / (length(v1) * length(v2));
    return acos(cosTheta);
}

// Функция для суммы векторов
Vector add(const Vector& v1, const Vector& v2) {
    return {v1.x + v2.x, v1.y + v2.y};
}

// Функция для разности векторов
Vector subtract(const Vector& v1, const Vector& v2) {
    return {v1.x - v2.x, v1.y - v2.y};
}

// Функция для проверки параллельности векторов
bool areParallel(const Vector& v1, const Vector& v2) {
    return (v1.x * v2.y - v1.y * v2.x) == 0;
}

int main() {
    std::srand(std::time(0));
    Vector v1 = {std::rand() % 100 - 50, std::rand() % 100 - 50};
    Vector v2 = {std::rand() % 100 - 50, std::rand() % 100 - 50};
    Vector v3 = {std::rand() % 100 - 50, std::rand() % 100 - 50};

    std::cout << "Vector 1: (" << v1.x << ", " << v1.y << ")\n";
    std::cout << "Vector 2: (" << v2.x << ", " << v2.y << ")\n";
    std::cout << "Vector 3: (" << v3.x << ", " << v3.y << ")\n";

    std::cout << "Length of Vector 1: " << length(v1) << "\n";
    std::cout << "Length of Vector 2: " << length(v2) << "\n";
    std::cout << "Length of Vector 3: " << length(v3) << "\n";

    std::cout << "Angle between Vector 1 and Vector 2: " << angleBetween(v1, v2) * 180 / M_PI << " degrees\n";
    std::cout << "Angle between Vector 1 and Vector 3: " << angleBetween(v1, v3) * 180 / M_PI << " degrees\n";
    std::cout << "Angle between Vector 2 and Vector 3: " << angleBetween(v2, v3) * 180 / M_PI << " degrees\n";

    Vector sum12 = add(v1, v2);
    Vector sum13 = add(v1, v3);
    Vector sum23 = add(v2, v3);

    std::cout << "Sum of Vector 1 and Vector 2: (" << sum12.x << ", " << sum12.y << ")\n";
    std::cout << "Sum of Vector 1 and Vector 3: (" << sum13.x << ", " << sum13.y << ")\n";
    std::cout << "Sum of Vector 2 and Vector 3: (" << sum23.x << ", " << sum23.y << ")\n";

    Vector diff12 = subtract(v1, v2);
    Vector diff13 = subtract(v1, v3);
    Vector diff23 = subtract(v2, v3);

    std::cout << "Difference of Vector 1 and Vector 2: (" << diff12.x << ", " << diff12.y << ")\n";
    std::cout << "Difference of Vector 1 and Vector 3: (" << diff13.x << ", " << diff13.y << ")\n";
    std::cout << "Difference of Vector 2 and Vector 3: (" << diff23.x << ", " << diff23.y << ")\n";

    std::cout << "Are Vector 1 and Vector 2 parallel? " << (areParallel(v1, v2) ? "Yes" : "No") << "\n";
    std::cout << "Are Vector 1 and Vector 3 parallel? " << (areParallel(v1, v3) ? "Yes" : "No") << "\n";
    std::cout << "Are Vector 2 and Vector 3 parallel? " << (areParallel(v2, v3) ? "Yes" : "No") << "\n";

    return 0;
}
