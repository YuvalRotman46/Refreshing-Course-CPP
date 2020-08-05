//
// Created by yuval on 05/08/2020.
//

#ifndef REFRESHING_PROJECT_SIAMI_CAT_H
#define REFRESHING_PROJECT_SIAMI_CAT_H
#include "cat.h"


class SiamiCat: virtual public Cat{
protected:
    char *fav_food;

public:
    SiamiCat(const char* name, const char* color, double mus_length, const char *fav_food);
    SiamiCat(const SiamiCat &other);
    SiamiCat(SiamiCat &&other);
    ~SiamiCat();

    const SiamiCat& operator=(const SiamiCat& other);
    const SiamiCat& operator=(SiamiCat&& other);
    void show() const;

    const char* getFavoriteFood() const;
    void setFavoriteFood(char* fav_food);
};

#endif //REFRESHING_PROJECT_SIAMI_CAT_H
