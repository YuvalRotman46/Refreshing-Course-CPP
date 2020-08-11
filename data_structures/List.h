//
// Created by yuval on 10/08/2020.
//

#ifndef REFRESHING_PROJECT_LIST_H
#define REFRESHING_PROJECT_LIST_H

#include "Node.h"

template<class T>
class List{
private:
    Node<T> *first;
    Node<T> *last;
    int elements_num;

public:
    List();
    List(const List<T> &other) = delete;
    List(List<T> &&other);
    virtual ~List();

    void deleteValuesAllocations();

    const List<T>& operator=(const List<T>& other) = delete;
    const List<T>& operator=(List<T> &&other);
    const List<T>& operator+=(T* e);
    T* const operator[](int index);
    bool operator==(const List<T> &list);


    bool add(T* e);
    void add(int index, T* e);
    bool addAll(const List<T> &list);
    bool addAll(int index, const List<T> &list);
    void clear();
    bool contains(void* object_pointer);
    bool containsAll(const List<T> &list);
    int indexOf(void* object_pointer);
    bool isEmpty();
    bool remove(void* object_pointer);
    T* remove(int index);
    bool removeAll(const List<T> &list);
    bool set(int index, T* e);
    int size();
    T** toArray();


    friend ostream& operator<<(ostream& os, const List<T>& list){
        Node<T> *chain = list.first;
        os<<"List[ ";
        while(chain != nullptr){
            os<< *chain->getValue();
            if(chain != list.last)
                os<<",";

            chain = chain->getNext();
        }
        os<<" ]";
        return os;
    }

};

template<class T>
List<T>::List(){
    first = last = nullptr;
    elements_num = 0;
}

template<class T>
List<T>::List(List<T> &&other): first(other.first), last(other.last), elements_num(0){}

template<class T>
List<T>::~List(){
    delete first;
}

template<class T>
void List<T>::deleteValuesAllocations(){
    Node<T> *chain = first;
    while (chain != nullptr){
        delete chain->getValue();

        chain = chain->getNext();
    }
}

template<class T>
const List<T>& List<T>::operator=(List<T> &&other){
    first = other.first;
    last = other.last;
    elements_num = other.elements_num;
}

template<class T>
const List<T>& List<T>::operator+=(T* e){
    this->add(e);
    elements_num++;
    return *this;
}

template<class T>
T* const List<T>::operator[](int index){
    Node<T> *element = first;
    for(int i = 0; i < index; i++)
        element = element->getNext();

    return element->getValue();
}

template<class T>
bool List<T>::operator==(const List<T> &list){
    return elements_num == list.elements_num && first == list.first && last == list.last;
}

template<class T>
bool List<T>::add(T* e){
    try {
        last->setNext(new Node<T>(e));
        last = last->getNext();
        return true;
    } catch (...) {
        return false;
    }
}

template<class T>
void List<T>::add(int index, T* e){
    Node<T> *chain = first, *broken;
    for (int i = 0; i < index - 2; i++)
        chain = chain->getNext();

    broken = chain->getNext();
    chain->setValue(new Node<T>(e, broken));
}

template<class T>
bool List<T>::addAll(const List<T> &list){

    last->setNext(list.first);
    last = list.last;

    return true;
}

template<class T>
bool List<T>::addAll(int index, const List<T> &list);

template<class T>
void List<T>::clear(){
    delete first;
    first = nullptr;
    last = nullptr;
}

template<class T>
bool List<T>::contains(void* object_pointer){
    Node<T> *chain = first;
    while(chain != nullptr){
        if(chain->getValue() == object_pointer)
            return true;

        chain = chain->getNext();
    }
    return false;
}

template<class T>
bool List<T>::containsAll(const List<T> &list);

template<class T>
int List<T>::indexOf(void* object_pointer){
    Node<T> *chain = first;
    int index = 0;
    while(chain != nullptr){
        if(chain->getValue() == object_pointer)
            return index;

        index++;
        chain = chain->getNext();
    }
    return -1;
}

template<class T>
bool List<T>::isEmpty(){
    return first == nullptr && last == nullptr;
}

template<class T>
bool List<T>::remove(void* object_pointer){

    if(first == object_pointer){
        delete first;
        first = nullptr;
        last = nullptr;
    }

    Node<T> *chain = first;
    Node<T> *element;

    while(chain != nullptr){
        if(chain->getNext() != nullptr){
            if(chain->getNext()->getValue() == object_pointer){
                element = chain->getNext();
                chain->setNext(element->getNext());

                //Cleaning up
                element->setNext(nullptr);
                delete element;
                elements_num--;
                return true;
            }
        }

        chain = chain->getNext();
    }

    return false;
}

template<class T>
T* List<T>::remove(int index){

    if(index == 0){
        T *value = first->getValue();
        delete first;
        first = last = nullptr;
        elements_num = 0;
        return value;
    }

    Node<T> *chain = first, *element;
    T *value;
    for (int i = 0; i < index-1; i++)
        chain = chain->getNext();

    element = chain->getNext();
    value = element->getValue();
    chain->setNext(element->getNext());
    element->setNext(nullptr);
    delete elementl;
    elements_num--;
    return value;

}

template<class T>
bool List<T>::removeAll(const List<T> &list){
    Node<T> *chain = list.first;
    while (chain != nullptr){
        this->remove(chain->getValue());

        chain = chain->getNext();
    }
    return true;
}

template<class T>
bool List<T>::set(int index, T* e){
    Node<T> *chain = first;
    for (int i = 0; i < index; ++i)
        chain = chain->getNext();
    chain->setValue(e);

    return true;
}

template<class T>
int List<T>::size(){
    return elements_num;
}

template<class T>
T** List<T>::toArray(){
    T** allocated_array = new T*[elements_num];
    Node<T> chain = first;
    for(int i = 0; i < elements_num; i++){
        allocated_array[i] = chain.getValue();
    }
    return allocated_array;
}


#endif //REFRESHING_PROJECT_LIST_H
