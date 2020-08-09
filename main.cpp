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

    Line *line = new Line(0,0,0,3,Shapes::getColorName(Shapes::RED));
    cout<<"Line length is : " << line->getLength()<<endl;
    cout<< *line <<endl;
    line->draw();
    line->resize(2);
    line->draw();

    delete line;

    for(auto o:objects)
        delete o;



    return 0;
}
