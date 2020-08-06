//
// Created by yuval on 05/08/2020.
//

#include "siami_cat.h"
#include<string.h>
#include <iostream>

using namespace std;

SiamiCat::SiamiCat(const char* name, const char* color, double mus_length, const char *fav_food):Cat(
        name, color, mus_length){
    this->fav_food = strdup(fav_food);
}
SiamiCat::SiamiCat(const SiamiCat &other):Cat(other){
    this->fav_food = strdup(other.fav_food);
}
SiamiCat::SiamiCat(SiamiCat &&other):Cat(other){
    this->fav_food = other.fav_food;
    other.fav_food = nullptr;
}
SiamiCat::~SiamiCat(){
    delete []fav_food;
}

const SiamiCat& SiamiCat::operator=(const SiamiCat& other){
    name = strdup(other.name);
    color = strdup(other.color);
    fav_food = strdup(fav_food);
    mus_length = other.mus_length;
    return *this;
}
const SiamiCat& SiamiCat::operator=(SiamiCat&& other){
    name = other.name;
    other.name = nullptr;
    color = other.color;
    other.color = nullptr;
    fav_food = other.fav_food;
    other.fav_food = nullptr;
    mus_length = other.mus_length;
    return *this;
}
void SiamiCat::show() const{
    cout << "$$$$$$$$$$$$$$$$$$$$$$$ Siami Cat $$$$$$$$$$$$$$$$$$$$$$$" <<endl;
    cout<<"Favorite food : " << fav_food<<endl;
    Cat::show();
    cout << "$$$$$$$$$$$$$$$$$$$$$ Siami Cat End $$$$$$$$$$$$$$$$$$$$$" <<endl;
}

const char* SiamiCat::getFavoriteFood() const{
    return fav_food;
}
void SiamiCat::setFavoriteFood(char* fav_food){
    this->fav_food = strdup(fav_food);
}