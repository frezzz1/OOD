#pragma once
#include "ShapeCreatorInterface.h"
#include "CTriangleShape.h"
#include <regex>
#include "stdafx.h"


// ‘абрика дл€ создани€ треугольников
class TriangleCreator : public ShapeCreatorInterface {
public:
    // ћетод дл€ получени€ экземпл€ра синглтона
    static TriangleCreator& GetInstance() {
        static TriangleCreator instance;
        return instance;
    }

    // —оздание треугольника из строки
    IShapePtr CreateShape(const std::string& info) const override {
        float x1, y1, x2, y2, x3, y3;

        // –егул€рное выражение дл€ треугольника
        std::regex pattern(R"(TRIANGLE:\s*P1=(\d+),(\d+);\s*P2=(\d+),(\d+);\s*P3=(\d+),(\d+))");
        std::smatch matches;

        if (!std::regex_search(info, matches, pattern)) {
            throw std::invalid_argument(ERROR_FORMAT_TRIANGLE);
        }

        // »звлечение данных
        x1 = std::stoi(matches[1].str());
        y1 = std::stoi(matches[2].str());
        x2 = std::stoi(matches[3].str());
        y2 = std::stoi(matches[4].str());
        x3 = std::stoi(matches[5].str());
        y3 = std::stoi(matches[6].str());

        return std::make_shared<CTriangleShape>(
            sf::Vector2f(x1, y1),
            sf::Vector2f(x2, y2),
            sf::Vector2f(x3, y3)
        );
    }


private:
    TriangleCreator() = default;
};
