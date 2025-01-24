#pragma once
#include "ShapeCreatorInterface.h"
#include "CRectangleShape.h"
#include <regex>

// Фабрика для создания прямоугольников
class RectangleCreator : public ShapeCreatorInterface {
public:
    static RectangleCreator& GetInstance() {
        static RectangleCreator instance;
        return instance;
    }

    IShapePtr CreateShape(const std::string& info) const override {
        float x1, y1, x2, y2;

        std::regex pattern(R"(RECTANGLE:\s*P1=(\d+),(\d+);\s*P2=(\d+),(\d+);)");
        std::smatch matches;

        if (!std::regex_search(info, matches, pattern)) {
            throw std::invalid_argument(ERROR_FORMAT_RECTANGLE);
        }

        x1 = std::stoi(matches[1].str());
        y1 = std::stoi(matches[2].str());
        x2 = std::stoi(matches[3].str());
        y2 = std::stoi(matches[4].str());

        return std::make_shared<CRectangleShape>(
            sf::Vector2f(x1, y1),
            sf::Vector2f(x2, y2)
        );
    }

private:
    RectangleCreator() = default;
};
