#include "ShapeCreator.h"
#include <regex>

IShapePtr ShapeCreator::CreateShape(const std::string& line) {
    std::regex pattern(R"(^(\w+):)");
    std::smatch matches;

    if (!std::regex_search(line, matches, pattern)) {
        throw std::invalid_argument(UNKNOWN_FORMAT_LINE);
    }

    std::string shapeName = matches[1];

    if (shapeName == CTriangleShape::NAME) {
        return TriangleCreator::GetInstance().CreateShape(line);
    }
    else if (shapeName == CRectangleShape::NAME) {
        return RectangleCreator::GetInstance().CreateShape(line);
    }
    else if (shapeName == CCircleShape::NAME) {
        return CircleCreator::GetInstance().CreateShape(line);
    }

    throw std::invalid_argument(UNKNOWN_TYPE_FIGURE + shapeName);
}
