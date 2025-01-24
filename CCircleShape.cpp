#include "CCircleShape.h"
#include "IVisitor.h"
#include "ColorsGenerator.h" 

const std::string CCircleShape::NAME = "CIRCLE"; 

CCircleShape::CCircleShape(const sf::Vector2f& center, float radius) {
    m_circle.setRadius(radius);
    m_circle.setPosition(center.x - radius, center.y - radius);

    ColorsGenerator colorGen;
    m_circle.setFillColor(colorGen.GetRandomColor());
}

std::string CCircleShape::ToString() const {
    return "Circle: Center=(" + std::to_string(GetCenter().x) + "," +
        std::to_string(GetCenter().y) + "), Radius=" + std::to_string(GetRadius());
}

void CCircleShape::Accept(IVisitor& visitor) const {
    visitor.VisitCircle(*this);
}

void CCircleShape::Draw(sf::RenderWindow& window) const {
    window.draw(m_circle);
}

float CCircleShape::GetRadius() const {
    return m_circle.getRadius();
}

sf::Vector2f CCircleShape::GetCenter() const {
    return sf::Vector2f(
        m_circle.getPosition().x + m_circle.getRadius(),
        m_circle.getPosition().y + m_circle.getRadius()
    );
}
