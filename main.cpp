#include <iostream>
#include "cats_inheritance/siami_street_cat.h"

int main() {
    SiamiStreetCat *c = new SiamiStreetCat("Mitzi", "Brown", 12.37, 7
                                           , "Pizza");

    c->show();

    delete c;
    return 0;
}
