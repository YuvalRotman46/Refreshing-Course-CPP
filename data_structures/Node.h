//
// Created by yuval on 09/08/2020.
//

#ifndef REFRESHING_PROJECT_NODE_H
#define REFRESHING_PROJECT_NODE_H

#include<iostream>

using std::ostream;

template<class T>
class Node {
private:
    T* value;
    Node* next;

public:
    Node(T* value, Node* next){ this->value = value;
        this->next = next;}

    Node(T* value):Node(value, nullptr){}

    Node(const Node& other) = delete;
    Node(Node &&other):Node(other.value, other.next){}
    ~Node(){
        // recursive destructor, deleting the whole node chain.
        // not taking responsibility on value cleaning from heap.
        delete next;
    }

    T* getValue() const{return value;}
    void setValue(T *value){
        // not taking responsibility on former value cleaning from heap.
        this->value;
    }
    Node* getNext() const{return next;}
    void setNext(Node *next){ this->next = next;}

    friend ostream& operator<<(ostream& os, const Node& node){
        os<< "Node("<<*node.value<<")";

        if(node.getNext() == nullptr) return os;

        os<<" ->";
        operator<<(os, *node.getNext());
    }
};


#endif //REFRESHING_PROJECT_NODE_H
