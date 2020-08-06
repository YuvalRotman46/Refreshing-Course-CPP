#include <iostream>
#include "cats_inheritance/cat.h"
#include "cats_inheritance/siami_street_cat.h"
#include "cats_inheritance/street_cat.h"
#include "cats_inheritance/siami_cat.h"


using std::cout, std::endl;

int main() {

    SiamiStreetCat ssc("Mitzi", "Brown", 2.35, 4, "Pizza");
    StreetCat sc("Mitzi", "Brown", 2.35, 4);
    const StreetCat *c = &(sc=ssc);
    c->show();



    return 0;
}
