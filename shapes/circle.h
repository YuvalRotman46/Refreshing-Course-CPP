//
// Created by yuval on 07/08/2020.
//

#ifndef REFRESHING_PROJECT_CIRCLE_H
#define REFRESHING_PROJECT_CIRCLE_H

#include "shape.h"


class Circle: public Shape{
private:
    double radius;

protected:
    virtual const char *getShapeDoc() const override;

public:

    static constexpr double PI = 3.14;

    Circle(int x, int y, double radius, const char* color = Shapes::getColorName(Shapes::BLACK));

    virtual void draw() const override;
    virtual void resize(float df) override;
    virtual void fill(const char* color) override;
    virtual double getArea() override;

    friend ostream& operator<<(ostream& os, const Circle& circle);
};

#endif //REFRESHING_PROJECT_CIRCLE_H
