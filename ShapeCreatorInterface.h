#pragma once
#include "IShape.h"

// Интерфейс для фабрик фигур
class ShapeCreatorInterface {
public:
    virtual IShapePtr CreateShape(const std::string& info) const = 0;
    virtual ~ShapeCreatorInterface() = default;
};
