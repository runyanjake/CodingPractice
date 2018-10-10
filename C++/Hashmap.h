/*
 * @author Jake Runyan
 * Hashmap.h
 * @desc <int,int> Hashmap implementation in C++
 */

#ifndef HASHMAP_H
#define HASHMAP_H

#include <vector>
#include <iostream>
#include <cmath>

#define STARTING_BUCKET_SIZE 2
#define STARTING_NUM_BUCKETS 2
#define RESIZE_FACTOR 2

class Hashmap {
private:
    long long bucket_size;
    long long num_buckets;
    float load_factor;
    long long filled;
    std::vector<std::vector<std::pair<int,int>>>* map;
public:
    Hashmap();
    ~Hashmap();
    int hash(int key);
    int rehash();
    int insert(int key, int value);
    int remove(int key);
    int get(int key);
    int update(int key, int val);
    bool exists(int key);
    void print();
    void printInternals();

};

#endif