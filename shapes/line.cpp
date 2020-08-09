//
// Created by yuval on 08/08/2020.
//

#include <iostream>
#include <sstream>
#include <string.h>
#include<math.h>
#include "line.h"

using std::cout, std::endl, std::ostream, std::ostringstream;


const char* Line::getShapeDoc() const{
    ostringstream os;
    os << "Point:{" << "start cords:("<<x<<", "<<y<<"); end cords: ("<<end->getX()<<", "<<end->getY()<<"), color: "<<color<<" }";
    return strdup(os.str().c_str());
}

Line::Line(double x, double y, double ex, double ey, const char* color): Shape(x,y,color){
    this->end = new Point(ex, ey, color);
}

Line::Line(const Line &other): Shape(other){
    this->end = new Point(*(other.end));
}
Line::Line(Line &&other): Shape(other){
    end = other.end;
    other.end = nullptr;
}
Line::~Line(){
    delete end;
}

const Line& Line::operator=(const Line& other){
    Shape::operator=(other);
    delete end;
    end = new Point(*(other.end));

    return *this;
}
const Line& Line::operator=(Line &&other){
    Shape::operator=(other);
    delete end;
    end = other.end;
    other.end = nullptr;

    return *this;
}

void Line::move(double dx, double dy){
    x+=dx;
    y+=dy;
    end->move(dx, dy);
}
void Line::draw() const {
    cout << "Haahhaaa I draw a "<< color << " line and it's length is : "<< getLength() <<endl;
}
void Line::resize(float df) {
    double nex, ney;
    nex = df*end->getX() - (df-1)*x;
    ney = df*end->getY() - (df-1)*y;

    end->setX(nex);
    end->setY(ney);
}
void Line::fill(const char* color){
    delete [] color;
    this->color = strdup(color);
    cout<< "Line was filled with "<<color<< "."<<endl;
}

double Line::getLength() const {
    double powedPit = pow(x-end->getX(), 2)+ pow(y-end->getY(),2);
    return sqrt(powedPit);
}

ostream& operator<<(ostream & os, const Line& line){
    const char* doc = line.getShapeDoc();
    os<<doc;
    delete [] doc;

    return os;
}