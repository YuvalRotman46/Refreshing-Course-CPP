//
// Created by yuval on 05/08/2020.
//

#include "siami_street_cat.h"
#include <iostream>

using namespace std;


SiamiStreetCat::SiamiStreetCat(const char* name, const char* color, double mus_length,
               int battles, const char *fav_food): Cat(name, color, mus_length),
               SiamiCat(name, color, mus_length, fav_food)
               , StreetCat(name, color, mus_length, battles){}

void SiamiStreetCat::show() const{
    cout<<endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@ Siami Street Cat @@@@@@@@@@@@@@@@@@@@@@@@@@" <<endl;
    StreetCat::show();
    SiamiCat::show();
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@ Siami Street Cat End @@@@@@@@@@@@@@@@@@@@@@@@" <<endl;
    cout<<endl;
}
