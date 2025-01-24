#include "CTriangleShape.h"
#include "IVisitor.h"
#include "ColorsGenerator.h" // Для генерации случайного цвета
#include <sstream>

// Определение статического поля
const std::string CTriangleShape::NAME = "TRIANGLE";

CTriangleShape::CTriangleShape(const sf::Vector2f& vertex1, const sf::Vector2f& vertex2, const sf::Vector2f& vertex3) {
    m_triangle.setPointCount(3);
    m_triangle.setPoint(0, vertex1);
    m_triangle.setPoint(1, vertex2);
    m_triangle.setPoint(2, vertex3);

    // Устанавливаем случайный цвет
    ColorsGenerator colorGen;
    m_triangle.setFillColor(colorGen.GetRandomColor());
}

std::string CTriangleShape::ToString() const {
    return NAME;
}

void CTriangleShape::Draw(sf::RenderWindow& window) const {
    window.draw(m_triangle);
}

void CTriangleShape::Accept(IVisitor& visitor) const {
    visitor.VisitTriangle(*this);
}

sf::Vector2f CTriangleShape::GetFirstVertex() const {
    return m_triangle.getPoint(0);
}

sf::Vector2f CTriangleShape::GetSecondVertex() const {
    return m_triangle.getPoint(1);
}

sf::Vector2f CTriangleShape::GetThirdVertex() const {
    return m_triangle.getPoint(2);
}
