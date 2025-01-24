#pragma once
#include "IVisitor.h"
#include <ostream> 
#include <iostream>

class AreaAndPerimeterPrinter : public IVisitor {
public:
    AreaAndPerimeterPrinter(std::ostream& output = std::cout) : m_output(output) {}

    void VisitTriangle(const CTriangleShape& triangle) override;
    void VisitRectangle(const CRectangleShape& rectangle) override;
    void VisitCircle(const CCircleShape& circle) override;

private:
    std::ostream& m_output; 
};
