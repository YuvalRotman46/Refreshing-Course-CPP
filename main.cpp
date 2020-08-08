#include <iostream>
#include "shapes/rect.h"
#include "shapes/circle.h"
#include "shapes/point.h"
#include "shapes/line.h"
#include <math.h>

using std::cout, std::endl;
using namespace Shapes;

int main() {

    Shape* objects[] = {
            new Rect(12,39, 100,13.5, getColorName(BLUE)),
            new Circle(12,41, 12),
            new Point(0,0)
    };
    for (auto o: objects)
      o->draw();

    cout<<endl;

    for(auto o:objects)
        cout << *o<<endl;

    cout<<endl;

    Line *line = new Line(1,1,3,3,Shapes::getColorName(Shapes::RED));
    cout<<"Line length is : " << line->getLength()<<endl;
    cout<< *line <<endl;
    line->draw();

    line->resize(sqrt(2));
    cout<< *line <<endl;
    line->draw();

    return 0;
}
