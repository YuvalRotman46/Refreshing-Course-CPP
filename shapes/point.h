//
// Created by yuval on 08/08/2020.
//

#ifndef REFRESHING_PROJECT_POINT_H
#define REFRESHING_PROJECT_POINT_H

#include "shape.h"
#include <iostream>

class Point : public Shape{

protected:
    virtual const char* getShapeDoc() const override;

public:
    Point(double x, double y, const char* color = Shapes::getColorName(Shapes::BLACK));
    virtual void draw() const override;
    virtual void resize(float df) override;
    virtual void fill(const char* color) override;
    virtual double getArea() override{return 0;}

    Point operator+(const Point& point) const;
    Point operator+(int addition) const;
    const Point& operator+=(Point& point);
    const Point& operator+=(int addition);

    friend ostream& operator<<(ostream& os, const Point& point);


};

#endif //REFRESHING_PROJECT_POINT_H
