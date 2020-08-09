//
// Created by yuval on 08/08/2020.
//

#ifndef REFRESHING_PROJECT_LINE_H
#define REFRESHING_PROJECT_LINE_H
#include "shape.h"
#include "point.h"

class Line : public Shape{

private:
    Point *end;

protected:
    virtual const char* getShapeDoc() const override;

public:
    Line(double x, double y, double ex, double ey, const char* color=Shapes::getColorName(Shapes::YELLOW));
    Line(const Line &other);
    Line(Line &&other);
    virtual ~Line() override;

    const Line& operator=(const Line& other);
    const Line& operator=(Line &&other);

    virtual void move(double dx, double dy) override;
    virtual void draw() const override;
    virtual void resize(float df) override;
    virtual void fill(const char* color) override;
    virtual double getLength() const;
    virtual double getArea() override{return 0;}

    friend ostream& operator<<(ostream & os, const Line& line);

};

#endif //REFRESHING_PROJECT_LINE_H
