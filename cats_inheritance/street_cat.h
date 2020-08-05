//
// Created by yuval on 05/08/2020.
//

#ifndef REFRESHING_PROJECT_STREET_CAT_H
#define REFRESHING_PROJECT_STREET_CAT_H

#include "cat.h"

class StreetCat : virtual public Cat{
protected:
    int battles;

public:
    StreetCat(const char* name, const char* color, double mus_length, int battles);

    void show() const;
    int getBattles() const;

    void setBattles(int battles);

};

#endif //REFRESHING_PROJECT_STREET_CAT_H
