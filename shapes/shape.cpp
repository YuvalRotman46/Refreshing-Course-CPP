//
// Created by yuval on 06/08/2020.
//

#include "shape.h"
#include <string.h>

namespace Shapes{
    const char* colors[] = {"Black", "White", "Yellow", "Blue", "Red", "Brown"};

    const char* getColorName(Color c){
        return colors[c];
    }
}

Shape::Shape(int x, int y, const char* color): x(x), y(y){
    this->color = strdup(color);
}

Shape::Shape(const Shape &other): x(other.x), y(other.y) {
    color = strdup(other.color);
}

Shape::Shape(Shape &&other): x(other.x), y(other.y) {
    color = other.color;
    other.color = nullptr;
}

Shape::~Shape() {
    delete [] color;
}

const Shape& Shape::operator=(const Shape &other) {
    x = other.x;
    y = other.y;
    color = strdup(other.color);

    return *this;
}

const Shape & Shape::operator=(Shape &&other) {
    x = other.x;
    y = other.y;

    delete [] color;
    color = other.color;
    other.color = nullptr;

    return *this;
}

void Shape::move(int dx, int dy) {
    x += dx;
    y += dy;
}

int Shape::getX() const {
    return x;
}

void Shape::setX(int x) {
    Shape::x = x;
}

int Shape::getY() const {
    return y;
}

void Shape::setY(int y) {
    Shape::y = y;
}

const char *Shape::getColor() const {
    return color;
}

void Shape::setColor(const char *color) {
    this->color = strdup(color);
}

ostream& operator<<(ostream& os, const Shape& shape){
    const char* doc = shape.getShapeDoc();
    os << doc;
    delete [] doc;
    return os;
}