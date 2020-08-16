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
    T* const operator[](int index) throw (const char *);
    bool operator==(const List<T> &list);


    bool add(T* e);
    void add(int index, T* e) throw (const char *);
    bool addAll(const List<T> &list);
    bool addAll(int index, const List<T> &list)  throw (const char *);
    void clear();
    bool contains(void* object_pointer);
    bool containsAll(const List<T> &list);
    int indexOf(void* object_pointer);
    bool isEmpty();
    bool remove(void* object_pointer);
    T* remove(int index) throw (const char *);
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
T* const List<T>::operator[](int index) throw (const char *){
    if(index >= elements_num)
        throw "Exception : Array Index Out Of Bounds Exception";

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

    if(first == nullptr){
        first = new Node<T>(e);
        last = first;
        elements_num++;
        return true;
    }

    try {
        last->setNext(new Node<T>(e));
        last = last->getNext();
        elements_num++;
        return true;
    } catch (...) {
        return false;
    }
}

template<class T>
void List<T>::add(int index, T* e)throw (const char *){
    Node<T> *new_first;
    Node<T> *element;

    switch (index) {

        case 0:
            new_first = new Node<T>(e);
            new_first->setNext(first);
            first = new_first;
            if(last == nullptr)
                last = first;

            elements_num++;
            return;

        case 1:
            if(first == nullptr)
                throw "Exception : Array Index Out Of Bounds Exception";

            element = first->getNext();
            first->setNext(new Node<T>(e, element));
            if(first == last)
                last = first->getNext();
            elements_num++;
            return;

        default:
            Node<T> *chain = first, *broken;
            for (int i = 0; i < index - 2; i++)
                chain = chain->getNext();

            broken = chain->getNext();
            chain->setNext(new Node<T>(e, broken));
            if(broken == nullptr)
                last = chain->getNext();

            elements_num++;

            break;

    }

}

template<class T>
bool List<T>::addAll(const List<T> &list){

    if(first == nullptr){
        first = list.first;
        last =  list.last;
        elements_num = list.elements_num;
        return true;
    }

    try {
        last->setNext(list.first);
        last = list.last;
        elements_num += list.elements_num;
        return true;
    } catch (...) {
        return false;
    }
}

template<class T>
bool List<T>::addAll(int index, const List<T> &list) throw (const char *){
    if(list.elements_num == 0) return true;

    if(index >= elements_num)
        throw "Exception : Array Index Out Of Bounds Exception";

    Node<T> *broke_node;
    try {
        if (index == 0) {
            broke_node = first;
            first = list.first;
            list.last->setNext(broke_node);
            elements_num += list.elements_num;
            return true;
        }

        Node<T> *this_list_pointer = first;
        for (int i = 0; i < index - 1; ++i)
            this_list_pointer = this_list_pointer->getNext();

        /*
         * Saving the current desire index element for connect it to the rest of the chain later
         */
        broke_node = this_list_pointer->getNext();

        /*
         * Connecting the other list in the desire index
         */
        this_list_pointer->setNext(list.first);
        list.last->setNext(broke_node);
        elements_num += list.elements_num;

        if (index == elements_num - 1) last = list.last;
        return true;
    }
    catch(...){
        return false;
    }
}

template<class T>
void List<T>::clear(){
    delete first;
    first = nullptr;
    last = nullptr;
    elements_num = 0;
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
bool List<T>::containsAll(const List<T> &list){
    if(list.elements_num == 0) return true;

    if(elements_num == 0) return false;

    Node<T> *this_list_pointer = first, *other_list_pointer = list.first;
    while (this_list_pointer != nullptr){
        bool one_equality = false;
        while (other_list_pointer != nullptr){
            if(other_list_pointer->getValue() == this_list_pointer->getValue())
                one_equality = true;

            other_list_pointer = other_list_pointer->getNext();
        }
        if(one_equality == false) return false;

        other_list_pointer = list.first;
        this_list_pointer = this_list_pointer->getNext();
    }
    return true;
}

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
    if(first == nullptr) return false;

    Node<T> *broke_element; /* A pointer for the element after the one we want to remove for connecting the chain. */

    /* Case of removing the first element */
    if(first->getValue() == object_pointer){
        broke_element = first->getNext();
        first->setNext(nullptr);
        delete first;
        first = broke_element;

        /* if element has been detected as the only one */
        if(first == nullptr) last = nullptr;

        --elements_num;
        return true;
    }

    Node<T> chain = first;
    while(chain != nullptr){
        if(chain.getNext() == nullptr) return false;

        Node<T> *possible_target;
        possible_target = chain.getNext();
        if(possible_target->getValue() == object_pointer){
            chain.setNext(possible_target->getNext());

            /* cleaning up detected target */
            possible_target->setNext(nullptr);
            delete possible_target;
            return true;
        }

        chain = chain.getNext();
    }

    return false;
}

template<class T>
T* List<T>::remove(int index) throw (const char *){

    if(index >= elements_num)
        throw "Exception : Array Index Out Of Bounds Exception";

    if(index == 0){
        Node<T> *element;
        T *value = first->getValue();

        /*
         * Erasing the first node without destroying the whole node chain.
         */
        element = first->getNext();
        first->setNext(nullptr);
        delete first;
        first = element;
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
    delete element;
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
