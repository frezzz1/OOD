#pragma once
#include "IShape.h"
#include <SFML/Graphics.hpp>
#include <string>

class CRectangleShape : public IShape {
public:
    static const std::string NAME; 

    CRectangleShape(const sf::Vector2f& topLeft, const sf::Vector2f& bottomRight);

    std::string ToString() const override;
    void Draw(sf::RenderWindow& window) const override;
    void Accept(IVisitor& visitor) const override;

    float GetWidth() const;
    float GetHeight() const;

private:
    sf::RectangleShape m_rectangle;
};
