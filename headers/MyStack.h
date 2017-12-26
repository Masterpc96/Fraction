//
// Created by Michael Urban on 25/12/2017.
//

#ifndef FRACTION_MYSTACK_H
#define FRACTION_MYSTACK_H

#include <iostream>
#include <stdexcept>

struct Node { // node struct
    int key; // current value
    Node *next; // next node
};

class MyStack {
private:
    Node *top; // first element
    int size; // current stack size
public:
    MyStack(); // default constructor
    ~MyStack(); // destructor

    bool push(int key); // push element to stack
    int pop(); // take and delete first element from stack
    bool isEmpty(); // check if size equals 0
    int peek(); // take first element from stack
    void clear(); // clear stack
};


#endif //FRACTION_MYSTACK_H