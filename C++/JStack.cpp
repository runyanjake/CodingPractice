/*
 * @author Jake Runyan
 * JStack.cpp
 * @desc String JStack implementation in C++ 
 * using finite sized arrays and indices to 
 * simulate stack behavior.
 */

#include <iostream>
#include "JStack.h"

JStack::JStack(){
    numItems = 0;
    stackSize = DEFAULT_STACK_SIZE;
    items = (std::string*)calloc(stackSize, sizeof(std::string));
}

JStack::~JStack(){
    free(items);
    items = nullptr;
}

void JStack::resize(){
    stackSize *= STACK_RESIZE_FACTOR;
    std::string* newItems = (std::string*)calloc(stackSize, sizeof(std::string));
    for(int a = 0; a < numItems; ++a){
        newItems[a] = items[a];
    }
    free(items);
    items = newItems;
}

int JStack::push(std::string str){
    if(numItems >= stackSize){
        resize();
    }
    items[numItems] = str;
    ++numItems;
    return 0;
}

std::string JStack::pop(){
    if(numItems>0){
        --numItems;
        return items[numItems];
    }else{
        return "";
    }
}

int JStack::size(){
    return numItems;
}

void JStack::print(){
    printf("Stack contains: [");
    bool first = true;
    for(int a = 0; a < numItems; ++a){
        if(first){ printf("\"%s\"", items[a].c_str()); first = false; continue; }
        printf(" \"%s\"", items[a].c_str());
    }
    printf("].\n");
}

