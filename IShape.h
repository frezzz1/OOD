#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class IVisitor;

class IShape {
public:
    virtual std::string ToString() const = 0; 
    virtual void Accept(IVisitor& visitor) const = 0;
    virtual void Draw(sf::RenderWindow& window) const = 0;
    virtual ~IShape() = default;
};

using IShapePtr = std::shared_ptr<IShape>;
