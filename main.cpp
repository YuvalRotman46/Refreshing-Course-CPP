#include <iostream>
#include "cats_inheritance/cat.h"

int main() {
    Cat *c1 = new Cat(Cat("Kitzi", "White", 3.33));
    c1->show();

    delete c1;

    return 0;
}
