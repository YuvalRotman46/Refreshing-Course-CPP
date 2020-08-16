#include <iostream>
#include "shapes/shapes.h"
#include "data_structures/List.h"

using namespace std;

int main(){
    List<Shape> *list = new List<Shape>();

    list->add(new Circle(0,0,1));
    list->add(new Rect(100, -100, 50, 50, Shapes::getColorName(Shapes::YELLOW)));
    list->add(new Line(5,5, 120, 145, Shapes::getColorName(Shapes::RED)));

    for (int i = 0; i < list->size(); ++i) {
        if(typeid(*(*list)[i]) == typeid(Line))
            cout << "this ls a line with length : " << ((Line*)(*list)[i])->getLength() << endl;
    }

    Shape *removed_shape = (list->remove(2));

    cout << *removed_shape <<endl;
    delete removed_shape;

    cout << list->size() <<endl;



    list->deleteValuesAllocations();
    delete list;

    return 0;
}
