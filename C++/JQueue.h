/*
 * @author Jake Runyan
 * JQueue.h
 * @desc String queue implementation in C++
 */


#ifndef JQUEUE_H
#define JQUEUE_H

#include <string>

#define DEFAULT_QUEUE_LENGTH 2
#define QUEUE_RESIZE_FACTOR 2

class JQueue{
private:
    int numItems;
    int queueLength;
    int begin;
    int end;
    std::string* items;
public:
    JQueue();
    ~JQueue();
    void resize();
    int enqueue(std::string str);
    std::string dequeue();
    int length();
    void print();
};

#endif