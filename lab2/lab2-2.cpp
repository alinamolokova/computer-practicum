#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

struct Point {
    double x, y, z;
};

struct Vector3D {
    double x, y, z;
};

// Прямая задана точкой и направляющим вектором
struct Line {
    Point p;
    Vector3D v;
};

// Плоскость задана уравнением Ax + By + Cz + D = 0
struct Plane {
    double A, B, C, D;
};

// Функция для вычисления длины вектора в 3D
double length(const Vector3D& v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

// Функция для вычисления скалярного произведения векторов в 3D
double dotProduct(const Vector3D& v1, const Vector3D& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// Функция для вычисления угла между прямой и плоскостью
double angleBetween(const Line& l, const Plane& p) {
    Vector3D normal = {p.A, p.B, p.C};
    double cosTheta = dotProduct(l.v, normal) / (length(l.v) * length(normal));
    return acos(cosTheta);
}

// Функция для проверки параллельности прямой и плоскости
bool areParallel(const Line& l, const Plane& p) {
    Vector3D normal = {p.A, p.B, p.C};
    return dotProduct(l.v, normal) == 0;
}

// Функция для вычисления расстояния между параллельной прямой и плоскостью
double distanceBetween(const Line& l, const Plane& p) {
    return fabs(p.A * l.p.x + p.B * l.p.y + p.C * l.p.z + p.D) / length({p.A, p.B, p.C});
}

// Функция для нахождения точки пересечения прямой и плоскости
Point intersection(const Line& l, const Plane& p) {
    Vector3D normal = {p.A, p.B, p.C};
    double t = -(dotProduct(normal, {l.p.x, l.p.y, l.p.z}) + p.D) / dotProduct(normal, l.v);
    return {l.p.x + l.v.x * t, l.p.y + l.v.y * t, l.p.z + l.v.z * t};
}

int main() {
    std::srand(std::time(0));
    Line l = {{static_cast<double>(std::rand() % 100 - 50), static_cast<double>(std::rand() % 100 - 50), static_cast<double>(std::rand() % 100 - 50)},
              {static_cast<double>(std::rand() % 100 - 50), static_cast<double>(std::rand() % 100 - 50), static_cast<double>(std::rand() % 100 - 50)}};
    Plane p = {static_cast<double>(std::rand() % 100 - 50), static_cast<double>(std::rand() % 100 - 50), static_cast<double>(std::rand() % 100 - 50), static_cast<double>(std::rand() % 100 - 50)};

    std::cout << "Line: Point (" << l.p.x << ", " << l.p.y << ", " << l.p.z << "), "
              << "Direction (" << l.v.x << ", " << l.v.y << ", " << l.v.z << ")\n";
    std::cout << "Plane: " << p.A << "x + " << p.B << "y + " << p.C << "z + " << p.D << " = 0\n";

    if (areParallel(l, p)) {
        std::cout << "The line and the plane are parallel.\n";
        std::cout << "Distance between the line and the plane: " << distanceBetween(l, p) << "\n";
    } else {
        std::cout << "The angle between the line and the plane: " << angleBetween(l, p) * 180 / M_PI << " degrees\n";
        Point intersectionPoint = intersection(l, p);
        std::cout << "Intersection point: (" << intersectionPoint.x << ", " << intersectionPoint.y << ", " << intersectionPoint.z << ")\n";
    }

    return 0;
}
