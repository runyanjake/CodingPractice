/*
 * @author Jake Runyan
 * Stack.cpp
 * @desc String stack implementation in C++
 */

#include <iostream>
#include "Stack.h"

Stack::Stack(){
    numItems = 0;
    stackSize = STACK_RESIZE_FACTOR;
    std::string strs[stackSize];
    items = strs;
}

Stack::~Stack(){

}

void Stack::resize(){

}

int Stack::push(std::string str){

}

std::string Stack::pop(){

}

int Stack::size(){

}

void Stack::print(){

}

