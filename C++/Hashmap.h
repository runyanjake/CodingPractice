/*
 * @author Jake Runyan
 * Hashmap.h
 * @desc <int,int> Hashmap implementation in C++
 */

#ifndef HASHMAP_H
#define HASHMAP_H

#include <vector>

#define STARTING_BUCKET_SIZE 25
#define STARTING_NUM_BUCKETS 10

class Hashmap {
private:
    int bucket_size;
    int num_buckets;
    float load_factor;
    std::vector<std::vector<std::pair<int,int>>>* map;
public:
    //Constructor to create a new Hashmap
    Hashmap(){
        bucket_size = STARTING_BUCKET_SIZE;
        num_buckets = STARTING_NUM_BUCKETS;
        load_factor = 0.0;
        map = new std::vector<std::vector<std::pair<int,int>>>();
        for(int a=0; a<num_buckets; ++a){
            std::vector<std::pair<int,int>> buck = std::vector<std::pair<int,int>>();
            map->push_back(buck);
        }
    }
    //Deconstructor deletes any dynamically allocated memory.
    ~Hashmap(){
        delete map;
    }

    int insert(int key, int value){
        return 0;
    }
    int remove(int key){
        return 0;
    }
    int get(int key){
        return 0;
    }
    bool exists(int key){
        return 0;
    }

};

#endif