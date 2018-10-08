/*
 * @author Jake Runyan
 * Stack.h
 * @desc String stack implementation in C++
 */

#ifndef JSTACK_H
#define JSTACK_H

#include <string>

#define DEFAULT_STACK_SIZE 2
#define STACK_RESIZE_FACTOR 2

class JStack{
private:
    int numItems;
    int stackSize;
    std::string* items;
public:
    JStack();
    ~JStack();
    void resize();
    int push(std::string str);
    std::string pop();
    int size();
    void print();
};

#endif