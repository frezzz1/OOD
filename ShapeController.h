#pragma once
#include <vector>
#include <memory>
#include "IShape.h"
#include <SFML/Graphics.hpp>
#include"stdafx.h"

class ShapeController {
public:
    void ReadShapes(const std::string& fileName);
    void DrawShapes();
    void PrintShapesInfo(const std::string& fileName);

private:
    std::vector<IShapePtr> m_shapes;
    sf::RenderWindow m_window = sf::RenderWindow(sf::VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), TITLE_WINDOW, sf::Style::Default);
    IShapePtr ConstructShape(const std::string& line);
};
