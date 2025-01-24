#pragma once
#include "TriangleCreator.h"
#include "RectangleCreator.h"
#include "CircleCreator.h"

class ShapeCreator {
public:
    static IShapePtr CreateShape(const std::string& line);
};
