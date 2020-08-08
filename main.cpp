#include <iostream>
#include "shapes/rect.h"
#include "shapes/circle.h"
#include "shapes/point.h"

using std::cout, std::endl;
using namespace Shapes;

int main() {

    Shape* objects[] = {
            new Rect(12,39, 100,13.5, getColorName(BLUE)),
            new Circle(12,41, 12),
            new Point(0,0)
    };
    for (auto o: objects) {
      o->draw();
    }

    return 0;
}
