#include "CRectangleShape.h"
#include "IVisitor.h"
#include "ColorsGenerator.h" // Для генерации случайного цвета
#include <sstream>

const std::string CRectangleShape::NAME = "RECTANGLE"; // Определяем поле

CRectangleShape::CRectangleShape(const sf::Vector2f& topLeft, const sf::Vector2f& bottomRight) {
    m_rectangle.setPosition(topLeft);
    m_rectangle.setSize(sf::Vector2f(bottomRight.x - topLeft.x, bottomRight.y - topLeft.y));

    // Устанавливаем случайный цвет для прямоугольника
    ColorsGenerator colorGen;
    m_rectangle.setFillColor(colorGen.GetRandomColor());
}

void CRectangleShape::Accept(IVisitor& visitor) const {
    visitor.VisitRectangle(*this); // Передаём текущий объект посетителю
}

std::string CRectangleShape::ToString() const {
    return NAME;
}

void CRectangleShape::Draw(sf::RenderWindow& window) const {
    window.draw(m_rectangle);
}

float CRectangleShape::GetWidth() const {
    return m_rectangle.getSize().x;
}

float CRectangleShape::GetHeight() const {
    return m_rectangle.getSize().y;
}
