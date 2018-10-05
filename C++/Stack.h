/*
 * @author Jake Runyan
 * Stack.h
 * @desc String stack implementation in C++
 */

#ifndef STACK_H
#define STACK_H

#include <string>

#define DEFAULT_STACK_SIZE 2
#define STACK_RESIZE_FACTOR 2

class Stack{
private:
    int numItems;
    int stackSize;
    std::string* items;
public:
    Stack();
    ~Stack();
    void resize();
    int push(std::string str);
    std::string pop();
    int size();
    void print();
};

#endif