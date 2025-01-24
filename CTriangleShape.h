#pragma once
#include "IShape.h"
#include <SFML/Graphics.hpp>
#include <string>

class CTriangleShape : public IShape {
public:
    static const std::string NAME; 

    CTriangleShape(const sf::Vector2f& vertex1, const sf::Vector2f& vertex2, const sf::Vector2f& vertex3);

    std::string ToString() const override;
    void Draw(sf::RenderWindow& window) const override;
    void Accept(IVisitor& visitor) const override;

    sf::Vector2f GetFirstVertex() const;
    sf::Vector2f GetSecondVertex() const;
    sf::Vector2f GetThirdVertex() const;

private:
    sf::ConvexShape m_triangle;
};
