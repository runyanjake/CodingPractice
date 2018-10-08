/*
 * @author Jake Runyan
 * JQueue.cpp
 * @desc String queue implementation in C++
 */

#include <iostream>
#include "JQueue.h"

JQueue::JQueue(){
    numItems = 0;
    begin = 0;
    end = 0;
    queueLength = DEFAULT_QUEUE_LENGTH;
    items = (std::string*)calloc(queueLength, sizeof(std::string));
}

JQueue::~JQueue(){
    free(items);
    items = nullptr;
}

void JQueue::resize(){
    int oldQueueLength = queueLength;
    queueLength *= QUEUE_RESIZE_FACTOR;
    std::string* newItems = (std::string*)calloc(queueLength, sizeof(std::string));
    for(int a = 0; a < numItems; ++a){
        newItems[a] = items[(begin + a) % oldQueueLength];
    }
    free(items);
    items = newItems;
    begin = 0;
    end = numItems-1;
}

int JQueue::enqueue(std::string str){
    if(numItems > 0 && (end + 1) % queueLength == begin){
        resize();
    }
    if(numItems > 0)
        end = (end + 1) % queueLength;
    items[end] = str;
    ++numItems;
    return 0;
}

std::string JQueue::dequeue(){
    if(numItems>0){
        std::string ret = items[begin];
        --numItems;
        if(begin == queueLength)
            begin = 0;
        else
            ++begin;
        return ret;
    }else{
        return "";
    }
}

int JQueue::length(){
    return numItems;
}

void JQueue::print(){
    printf("Queue contains: [");
    bool first = true;
    for(int a = 0; a < numItems; ++a){
        if(first){ printf("\"%s\"", items[(begin + a) % queueLength].c_str()); first = false; continue; }
        printf(" \"%s\"", items[(begin + a) % queueLength].c_str());
    }
    printf("].\n");
}

