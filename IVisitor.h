#pragma once


class CTriangleShape;
class CRectangleShape;
class CCircleShape;

class IVisitor {
public:
    virtual void VisitTriangle(const CTriangleShape& triangle) = 0;
    virtual void VisitRectangle(const CRectangleShape& rectangle) = 0;
    virtual void VisitCircle(const CCircleShape& circle) = 0;
    virtual ~IVisitor() = default;
};