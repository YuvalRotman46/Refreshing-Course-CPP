//
// Created by yuval on 07/08/2020.
//

#include "circle.h"
#include <iostream>
#include <sstream>
#include<string.h>
#include<math.h>

using std::cout, std::endl, std::ostringstream;

Circle::Circle(int x, int y, double radius, const char* color): Shape(x, y, color), radius(radius){}

const char * Circle::getShapeDoc() const {
    ostringstream os;
    os << "Circle:{" << "cords:("<<x<<", "<<y<<") radius: "<<radius<<", color: "<< color <<"}";

    return strdup(os.str().c_str());
}

void Circle::draw() const {
    cout << "Haahhaaa I draw a "<< color << " circle in {"<<
         x<<", "<<y<<"} ."<<endl;
}
void Circle::resize(float df){
    radius *= df;
}
void Circle::fill(const char* color){
    delete []this->color;
    this->color = strdup(color);
    cout<< "Circle was filled with "<<color<< "."<<endl;
}
double Circle::getArea(){
    return pow(radius,2)*PI;
}

ostream& operator<<(ostream& os, const Circle& circle){
    const char* doc = circle.getShapeDoc();
    os << doc;
    delete [] doc;
    return os;
}