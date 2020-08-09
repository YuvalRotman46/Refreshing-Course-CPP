//
// Created by yuval on 06/08/2020.
//

#ifndef REFRESHING_PROJECT_RECT_H
#define REFRESHING_PROJECT_RECT_H

#include "shape.h"


class Rect: public Shape{
private:
    double width;
    double high;

protected:
    virtual const char *getShapeDoc() const override;

public:
    Rect(double x, double y, double width, double high, const char* color = Shapes::getColorName(Shapes::BLACK));

    virtual void draw() const override;
    virtual void resize(float df) override;
    virtual void fill(const char* color) override;
    virtual double getArea() override;

    friend ostream& operator<<(ostream& os, const Rect& rect);
};

#endif //REFRESHING_PROJECT_RECT_H
