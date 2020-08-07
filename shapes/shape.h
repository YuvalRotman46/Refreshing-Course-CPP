//
// Created by yuval on 06/08/2020.
//

#ifndef REFRESHING_PROJECT_SHAPE_H
#define REFRESHING_PROJECT_SHAPE_H

#include<iostream>
using std::ostream;

namespace Shapes{
    enum Color{BLACK, WHITE, YELLOW, BLUE, RED, BROWN};
    static const char* colors[] = {"Black", "White", "Yellow", "Blue", "Red", "Brown"};

    inline const char* getColorName(Color c){
        return colors[c];
    }
}


class Shape{
protected:
    int x;
    int y;
    char *color;

    virtual const char* getShapeDoc() const = 0;

public:
    Shape(int x, int y, const char* color = Shapes::getColorName(Shapes::BLACK));
    Shape(const Shape &other);

    Shape(Shape &&other);
    virtual ~Shape();

    const Shape& operator=(const Shape &other);
    const Shape& operator=(Shape &&other);

    virtual void move(int dx, int dy);
    virtual void draw() const = 0;
    virtual void resize(float df) = 0;
    virtual void fill(const char* color) = 0;
    virtual double getArea() = 0;

    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    const char *getColor() const;
    void setColor(const char *color);

};

#endif //REFRESHING_PROJECT_SHAPE_H
