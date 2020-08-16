#include <iostream>
#include "data_structures/List.h"

using namespace std;

int main(){
    int arr[] = {12, 42, 79, 16, 4, 193, 51};
    List<int> *list = new List<int>();

    for(int i = 0; i< sizeof(arr)/sizeof(int); i++){
        list->add(&arr[i]);
    }

    cout << *list << endl;

    delete list;

}
