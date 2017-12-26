//
// Created by Michael Urban on 25/12/2017.
//

#ifndef FRACTION_MYSTACK_H
#define FRACTION_MYSTACK_H

#include <iostream>
#include <stdexcept>


template<class T>
class MyStack {
    struct Node { // node struct
        T key; // current value
        Node *next; // next node
    };
private:
    Node *top; // first element
    int size; // current stack size
public:
    MyStack() {
        top = NULL;
        size = 0;
    } // default constructor
    ~MyStack() {
        while (top != NULL) {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    } // destructor

    bool push(T key) {
        Node *temp = new Node;
        temp->key = key;
        temp->next = top;
        top = temp;
        size++;
        return true;
    } // push element to stack
    T pop() {
        if (size != 0) {
            T temp = top->key;
            size--;
            top = top->next;
            return temp;
        }
        throw std::invalid_argument("stack is empty");
    } // take and delete first element from stack
    bool isEmpty() {
        return size == 0;
    } // check if size equals 0
    T &peek() {
        if (size != 0) {
            return top->key;
        }

        throw std::invalid_argument("stack is empty");

    } // take first element from stack
    void clear() {
        top = NULL;
        size = 0;
    }// clear stack
};


#endif //FRACTION_MYSTACK_H