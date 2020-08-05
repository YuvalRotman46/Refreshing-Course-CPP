//
// Created by yuval on 05/08/2020.
//

#ifndef REFRESHING_PROJECT_SIAMI_STREET_CAT_H
#define REFRESHING_PROJECT_SIAMI_STREET_CAT_H
#include "siami_cat.h"
#include "street_cat.h"

class SiamiStreetCat: public StreetCat, public SiamiCat{

public:
    SiamiStreetCat(const char* name, const char* color, double mus_length,
                   int battles, const char *fav_food);

    void show() const;
};


#endif //REFRESHING_PROJECT_SIAMI_STREET_CAT_H
