//
// Created by yuval on 08/08/2020.
//
#include <iostream>
#include <sstream>
#include <string.h>
#include "point.h"

using std::cout, std::endl, std::ostringstream;

const char* Point::getShapeDoc() const {
    ostringstream os;
    os << "Point:{" << "cords:("<<x<<", "<<y<<")}";

    return strdup(os.str().c_str());
}

Point::Point(int x, int y, const char *color): Shape(x, y, color) {}

void Point::draw() const{
    cout << "Haahhaaa I draw a "<< color << " point in {"<<
         x<<", "<<y<<"} ."<<endl;
}
void Point::resize(float df) {
    return;
}
void Point::fill(const char* color){
    cout<< "Point was filled with "<<color<< "."<<endl;
    delete [] this->color;
    this->color = strdup(color);
}

Point Point::operator+(const Point& point) const{
    return Point(x+point.x, y+point.y, Shapes::getColorName(Shapes::BLACK));
}
Point Point::operator+(int addition) const{
    return Point(x+addition, y+addition, Shapes::getColorName(Shapes::BLACK));
}
const Point& Point::operator+=(Point& point){
    x+=point.x;
    y+=point.y;

    return *this;
}
const Point& Point::operator+=(int addition){
    x+=addition;
    y+=addition;

    return *this;
}

ostream& operator<<(ostream& os, const Point& point){
    const char* doc = point.getShapeDoc();
    os << doc;
    delete [] doc;
    return os;
}