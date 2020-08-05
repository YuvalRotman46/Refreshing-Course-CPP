#include <iostream>
#include "cats_inheritance/cat.h"
#include "cats_inheritance/siami_street_cat.h"
#include "cats_inheritance/street_cat.h"
#include "cats_inheritance/siami_cat.h"


using std::cout, std::endl;

int main() {

    SiamiStreetCat ssc("Mitzi", "Brown", 2.35, 4, "Pizza");
    StreetCat *sc = new StreetCat((StreetCat&) ssc);
    sc->show();

    delete sc;

    return 0;
}
