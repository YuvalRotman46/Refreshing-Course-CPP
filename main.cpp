#include <iostream>
#include "cats_inheritance/siami_cat.h"

int main() {
    SiamiCat *c1 = new SiamiCat("Kitzi", "White", 3.33, "Mutzarela");
    ((Cat*)c1)->show();

    delete c1;

    return 0;
}
