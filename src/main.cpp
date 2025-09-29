#include "vector3d.h"
#include <iostream>

int main() {
    std::cout << "=== Test Vector3D ===\n";

    // Создание объекта
    Vector3D v1(3.0, 4.0, 5.0);
    std::cout << "v1: ";
    v1.print();

    // Тест копирования
    Vector3D v2 = v1;
    std::cout << "v2 (copy of v1): ";
    v2.print();

    // Тест перемещения
    Vector3D v3 = std::move(v1);
    std::cout << "v3 (moved from v1): ";
    v3.print();

    // v1 теперь в неопределенном состоянии, не используем его

    // Тест shared_ptr
    auto shared_v = std::make_shared<Vector3D>(6.0, 8.0, 10.0);
    std::cout << "Shared vector: ";
    shared_v->print();

    normalizeVector(shared_v);

    // Тест перемещения в unique_ptr
    std::unique_ptr<Vector3D> unique_v = std::make_unique<Vector3D>(1.0, 2.0, 3.0);
    std::cout << "Unique vector: ";
    unique_v->print();

    return 0;
}