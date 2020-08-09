//
// Created by yuval on 09/08/2020.
//

#include "Node.h"

void* Node::getValue() const {
    return value;
}

void Node::setValue(void *value) {
    this->value = value;
}

Node *Node::getNext() const {
    return next;
}

void Node::setNext(Node *next) {
    this->next = next;
}
