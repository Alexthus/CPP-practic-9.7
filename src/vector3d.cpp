#include "vector3d.h"

    // Конструктор
Vector3D::Vector3D(double x, double y, double z) 
        : coords(std::make_unique<double[]>(3)) {
        coords[0] = x;
        coords[1] = y;
        coords[2] = z;
    }

    // Деструктор (не нужен, т.к. unique_ptr сам освобождает память)

    // Конструктор копирования
Vector3D::Vector3D(const Vector3D& other) 
        : coords(std::make_unique<double[]>(3)) {
        std::copy(other.coords.get(), other.coords.get() + 3, coords.get());
    }

    // Оператор присваивания копированием
Vector3D& Vector3D::operator=(const Vector3D& other) {
        if (this != &other) {
            coords = std::make_unique<double[]>(3);
            std::copy(other.coords.get(), other.coords.get() + 3, coords.get());
        }
        return *this;
    }

    // Конструктор перемещения
Vector3D::Vector3D(Vector3D&& other) noexcept 
        : coords(nullptr) {
        coords = std::move(other.coords);
    }

    // Оператор присваивания перемещением
Vector3D& Vector3D::operator=(Vector3D&& other) noexcept {
        if (this != &other) {
            coords = std::move(other.coords);
        }
        return *this;
    }

    // Геттеры
double Vector3D::x() const { return coords[0]; }
double Vector3D::y() const { return coords[1]; }
double Vector3D::z() const { return coords[2]; }

    // Нормализация вектора
void Vector3D::normalize() {
        double length = std::sqrt(coords[0] * coords[0] + coords[1] * coords[1] + coords[2] * coords[2]);
        if (length > 0) {
            coords[0] /= length;
            coords[1] /= length;
            coords[2] /= length;
        }
    }

    // Вывод вектора
void Vector3D::print() const {
        std::cout << "Vector3D(" << coords[0] << ", " << coords[1] << ", " << coords[2] << ")\n";
    }

// Функция, принимающая shared_ptr<Vector3D> и нормализующая вектор
void normalizeVector(std::shared_ptr<Vector3D> vec) {
    vec->normalize();
    std::cout << "Normalized vector: ";
    vec->print();
}
