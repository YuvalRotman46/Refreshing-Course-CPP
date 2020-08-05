//
// Created by yuval on 05/08/2020.
//

#include "street_cat.h"
#include <iostream>

using namespace std;

StreetCat::StreetCat(const char* name, const char* color, double mus_length, int battles): Cat(name, color,
                                                                                               mus_length),
                                                                                               battles(battles)
                                                                                               {}

void StreetCat::show() const{
    cout << "########################### Street Cat ###########################" <<endl;
    Cat::show();
    cout << "######################### Street Cat End #########################" <<endl;
}
int StreetCat::getBattles() const{
    return battles;
}

void StreetCat::setBattles(int battles){
    this->battles = battles;
}