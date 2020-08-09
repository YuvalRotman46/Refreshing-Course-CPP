#include <iostream>
#include "templates/funcs.h"

using namespace std;

int main(){

    double arr[] = {3.1 ,4.9 ,5,21,-0.7,-19.3};
    print(getMin(&arr[0], sizeof(arr)/sizeof(double)));

    long latte = 78657473567;
    Wrapper<long> w(&latte);
    w.printEllement();

    return 0;
}
