#pragma once
#include "ShapeCreatorInterface.h"
#include "CCircleShape.h"
#include <regex>
#include "stdafx.h"

// Фабрика для создания окружностей
class CircleCreator : public ShapeCreatorInterface {
public:
    static CircleCreator& GetInstance() {
        static CircleCreator instance;
        return instance;
    }

    IShapePtr CreateShape(const std::string& info) const override {
        float centerX, centerY, radius;

        std::regex pattern(R"(CIRCLE:\s*C=(\d+),(\d+);\s*R=(\d+))");
        std::smatch matches;

        if (!std::regex_search(info, matches, pattern)) {
            throw std::invalid_argument(ERROR_FORMAT_CIRCLE);
        }

        centerX = std::stoi(matches[1].str());
        centerY = std::stoi(matches[2].str());
        radius = std::stoi(matches[3].str());

        return std::make_shared<CCircleShape>(
            sf::Vector2f(centerX, centerY),
            radius
        );
    }

private:
    CircleCreator() = default;
};
