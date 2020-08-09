//
// Created by yuval on 09/08/2020.
//

#ifndef REFRESHING_PROJECT_NODE_H
#define REFRESHING_PROJECT_NODE_H

#include<iostream>

using std::ostream;


class Node {
private:
    void* value;
    Node* next;

public:
    Node(void* value, Node* next);
    Node(void* value);
    Node(const Node& other) = delete;
    Node(Node &&other);
    ~Node();

    void* getValue() const;

    void setValue(void *value);

    Node* getNext() const;

    void setNext(Node *next);

    friend ostream& operator<<(ostream& os, const Node& node);
};


#endif //REFRESHING_PROJECT_NODE_H
