#pragma once
#include "IShape.h"

// Интерфейс для фабрик фигур
class ShapeCreatorInterface {
public:
    // Метод для создания фигуры из строки с параметрами
    virtual IShapePtr CreateShape(const std::string& info) const = 0;
    virtual ~ShapeCreatorInterface() = default;
};
