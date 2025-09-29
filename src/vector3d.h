#pragma once

#include <iostream>
#include <memory>
#include <cmath>
#include <algorithm>

class Vector3D {
private:
    std::unique_ptr<double[]> coords;  // Умный указатель на массив координат

public:
    // Конструктор
    explicit Vector3D(double x = 0.0, double y = 0.0, double z = 0.0);

    // Деструктор (не нужен, т.к. unique_ptr сам освобождает память)

    // Конструктор копирования
    Vector3D(const Vector3D& other);

    // Оператор присваивания копированием
    Vector3D& operator=(const Vector3D& other);

    // Конструктор перемещения
    Vector3D(Vector3D&& other) noexcept;

    // Оператор присваивания перемещением
    Vector3D& operator=(Vector3D&& other) noexcept;

    // Геттеры
    double x() const;
    double y() const;
    double z() const;

    // Нормализация вектора
    void normalize();

    // Вывод вектора
    void print() const;
};

// Функция, принимающая shared_ptr<Vector3D> и нормализующая вектор
void normalizeVector(std::shared_ptr<Vector3D> vec);
