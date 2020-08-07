//
// Created by yuval on 06/08/2020.
//

#include "rect.h"
#include <string.h>
#include <iostream>

using std::cout, std::endl, std::ostream;

Rect::Rect(int x, int y, double width, double high, const char *color) : Shape(x,y,color),
    width(width), high(high){}

const char* Rect::getShapeDoc() const{
    char shape_details[] = " Rect";
    int buffer_size = strlen(this->getColor())+ strlen(shape_details)+1;
    char buffer[buffer_size];
    int i = 0;
    for(;i<strlen(this->getColor());i++)
        buffer[i] = this->getColor()[i];

    for(int j=0;j<strlen(shape_details);j++){
        buffer[i] = shape_details[j];
        i++;
    }
    buffer[i] = 0;

    return strdup(buffer);
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
    os << doc <<"\n";
    delete [] doc;
    return os;
}