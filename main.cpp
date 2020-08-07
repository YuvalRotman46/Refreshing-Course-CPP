#include <iostream>
#include "shapes/rect.h"

using std::cout, std::endl;


int main() {

    Rect *rect = new Rect(12,39, 100,13.5);
    rect->fill(Shapes::getColorName(Shapes::BLUE));
    rect->draw();

    cout << *rect << endl;

    return 0;
}
