#include <iostream>
#include "data_structures/Node.h"

using namespace std;

int main(){

    double x = 23.4;
    double y = 72.123;
    double z = 912.7;

    Node<double> *root = new Node<double>(&x, new Node<double>(&y, new Node<double>(&z)));
    cout<<*root<<endl;

    delete root;
    return 0;
}
