//
// Created by yuval on 06/08/2020.
//

#include "rect.h"
#include <string.h>
#include <iostream>
#include <sstream>

using std::cout, std::endl, std::ostream, std::ostringstream;

Rect::Rect(int x, int y, double width, double high, const char *color) : Shape(x,y,color),
    width(width), high(high){}

const char* Rect::getShapeDoc() const{
    ostringstream os;
    os << "Rect:{" << "cords:("<<x<<", "<<y<<"), width: "<<width<<", high: "<<high
    <<", color: "<< color<< "}";

    return strdup(os.str().c_str());
}

void Rect::draw() const{
    cout << "Haahhaaa I draw a "<< color << " rectangle in {"<<
    x<<", "<<y<<"} ."<<endl;
}
void Rect::resize(float df){
    width *= df;
    high *= df;
}

void Rect::fill(const char* color){
    cout<< "Rectangle was filled with "<<color<< " ."<<endl;
    delete [] this->color;
    this->color = strdup(color);
}

double Rect::getArea() {
    return width*high;
}


ostream& operator<<(ostream& os, const Rect& rect){
    const char* doc = rect.getShapeDoc();
    os << doc;
    delete [] doc;
    return os;
}