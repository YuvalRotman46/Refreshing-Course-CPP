//
// Created by yuval on 09/08/2020.
//

#ifndef REFRESHING_PROJECT_FUNCS_H
#define REFRESHING_PROJECT_FUNCS_H
#include <iostream>

template<class T>
void mySwap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
void print(const T& t){
    std::cout << t << std::endl;
}

template<class T>
T getMin(T* array, int arr_length){
    T min_value;
    for (int i = 0; i < arr_length; i++) {
        if(i == 0)
            min_value = array[i];

        if(array[i] < min_value)
            min_value = array[i];
    }

    return min_value;
}

template<class T>
class Wrapper{
public:
        T* el;
        Wrapper(T* el){
            this->el = el;
        }

        void printEllement(){
            print(*el);
        }
        };

#endif //REFRESHING_PROJECT_FUNCS_H
