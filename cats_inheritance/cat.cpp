//
// Created by yuval on 05/08/2020.
//

#include "cat.h"
#include <iostream>
#include <string.h>

using namespace std;


Cat::Cat(const char* name, const char* color, double mus_length): mus_length(mus_length){
    this->name = strdup(name);
    this->color = strdup(color);
}
Cat::Cat(const Cat &other) : mus_length(other.mus_length){
    this->name = strdup(other.name);
    this->color = strdup(other.color);
}
Cat::Cat(Cat &&other) : mus_length(other.mus_length){
    this->name = other.name;
    this->color = other.color;

    other.color = nullptr;
    other.name = nullptr;

}
Cat::~Cat(){
    delete []name;
    delete []color;
}

const Cat& Cat::operator=(const Cat &other){
    this->mus_length = other.mus_length;
    this->name = strdup(other.name);
    this->color = strdup(other.color);

    return *this;
}
const Cat& Cat::operator=(Cat &&other){
    this->mus_length = other.mus_length;
    this->name = other.name;
    this->color = other.color;

    other.color = nullptr;
    other.name = nullptr;

    return *this;
}
void Cat::show() const{
    cout << "=================Cat==================" <<endl;

    cout << "Name : "<< name<<endl;
    cout << "Color : "<<color<<endl;
    cout << "Mustache : "<< mus_length <<endl;

    cout << "===============Cat End================" << endl;
}

const char* Cat::getName() const{
    return name;
}
const char* Cat::getColor() const{
    return color;
}
int Cat::getMusLength() const{
    return mus_length;
}

void Cat::setName(const char* name){
    this->name = strdup(name);
}
void Cat::setColor(const char* color){
    this->color = strdup(color);
}
void Cat::setMusLength(int mus_length){
    this->mus_length = mus_length;
}