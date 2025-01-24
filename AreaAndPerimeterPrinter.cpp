#include "AreaAndPerimeterPrinter.h"
#include "CTriangleShape.h"
#include "CRectangleShape.h"
#include "CCircleShape.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void AreaAndPerimeterPrinter::VisitTriangle(const CTriangleShape& triangle) {
    auto a = triangle.GetFirstVertex();
    auto b = triangle.GetSecondVertex();
    auto c = triangle.GetThirdVertex();

    auto Distance = [](const sf::Vector2f& p1, const sf::Vector2f& p2) {
        return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
        };

    float ab = Distance(a, b);
    float bc = Distance(b, c);
    float ca = Distance(c, a);

    float perimeter = ab + bc + ca;
    float s = perimeter / 2;
    float area = std::sqrt(s * (s - ab) * (s - bc) * (s - ca));

    m_output << "TRIANGLE: P=" << perimeter << "; S=" << area << std::endl;
}

void AreaAndPerimeterPrinter::VisitRectangle(const CRectangleShape& rectangle) {
    float width = rectangle.GetWidth();
    float height = rectangle.GetHeight();

    float perimeter = 2 * (width + height);
    float area = width * height;

    m_output << "RECTANGLE: P=" << perimeter << "; S=" << area << std::endl;
}

void AreaAndPerimeterPrinter::VisitCircle(const CCircleShape& circle) {
    float radius = circle.GetRadius();

    float perimeter = 2 * M_PI * radius;
    float area = M_PI * std::pow(radius, 2);

    m_output << "CIRCLE: P=" << perimeter << "; S=" << area << std::endl;
}
