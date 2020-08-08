#include <iostream>
#include "shapes/rect.h"
#include "shapes/circle.h"
#include "shapes/point.h"

using std::cout, std::endl;
using namespace Shapes;

int main() {

    Rect *rect = new Rect(12,39, 100,13.5, getColorName(BLUE));
    rect->draw();
    cout << *rect << endl;
    delete rect;

    cout<<endl;


    Circle *c = new Circle(12,41, 12);
    cout<< "The circle area is : "<< c->getArea()<<endl;
    cout<< *c <<endl;
    c->fill(getColorName(RED));
    cout<< *c <<endl;
    delete c;

    cout<<endl;

    Point *point = new Point(0,0);
    point->draw();
    cout<< *point <<endl;

    return 0;
}
