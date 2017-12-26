//
// Created by Michael Urban on 25/12/2017.
//

#include "../headers/MyStack.h"

// constructor

MyStack::MyStack() {
    top = NULL;
    size = 0;
}

// destructor

MyStack::~MyStack() {
    while (top != NULL) {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}

// methods

bool MyStack::push(int key) {
    Node *temp = new Node;
    temp->key = key;
    temp->next = top;
    top = temp;
    size++;
    return true;
}

int MyStack::pop() {
    if (size != 0) {
        int temp = top->key;
        size--;
        top = top->next;
        return temp;
    }
    throw std::invalid_argument("stack is empty");
}

bool MyStack::isEmpty() {
    return size == 0;
}

int MyStack::peek() {
    if (size != 0) {
        return top->key;
    }

    throw std::invalid_argument("stack is empty");

}

void MyStack::clear() {
    top = NULL;
    size = 0;
}