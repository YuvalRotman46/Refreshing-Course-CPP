//
// Created by yuval on 06/08/2020.
//

#ifndef REFRESHING_PROJECT_SHAPE_H
#define REFRESHING_PROJECT_SHAPE_H

#include<iostream>
using std::ostream;

namespace Shapes{
    enum Color{BLACK, WHITE, YELLOW, BLUE, RED, BROWN};
    const char* getColorName(Color c);
}


class Shape{
protected:
    double x;
    double y;
    char *color;

    virtual const char* getShapeDoc() const = 0;

public:
    Shape(double x, double y, const char* color = Shapes::getColorName(Shapes::BLACK));
    Shape(const Shape &other);

    Shape(Shape &&other);
    virtual ~Shape();

    const Shape& operator=(const Shape &other);
    const Shape& operator=(Shape &&other);

    virtual void move(double dx, double dy);
    virtual void draw() const = 0;
    virtual void resize(float df) = 0;
    virtual void fill(const char* color) = 0;
    virtual double getArea() = 0;

    double getX() const;
    void setX(double x);
    double getY() const;
    void setY(double y);
    const char *getColor() const;
    void setColor(const char *color);

    friend ostream& operator<<(ostream& os, const Shape& shape);


};

#endif //REFRESHING_PROJECT_SHAPE_H
