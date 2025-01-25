#pragma once
#include "IShape.h"
#include <SFML/Graphics.hpp>
#include <string>

class CCircleShape : public IShape {
public:
    static const std::string NAME; 

    CCircleShape(const sf::Vector2f& center, float radius);

    std::string ToString() const override;
    void Draw(sf::RenderWindow& window) const override;
    void Accept(IVisitor& visitor) const override;

    float GetRadius() const;
    sf::Vector2f GetCenter() const;

private:
    sf::CircleShape m_circle;
};
