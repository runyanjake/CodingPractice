/*
 * @author Jake Runyan
 * Hashmap.h
 * @desc <int,int> Hashmap implementation in C++
 */

#ifndef HASHMAP_H
#define HASHMAP_H

#include <vector>
#include <iostream>

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
            std::vector<std::pair<int,int>>* buck = new std::vector<std::pair<int,int>>();
            map->push_back(*buck);
        }
    }
    //Deconstructor deletes any dynamically allocated memory.
    ~Hashmap(){
        delete map;
        map = nullptr;
    }

    int hash(int key){
        return 0;
    }

    int rehash(){
        std::cerr << "A Rehash was requested." << std::endl;
        exit(1);
        return 0;
    }

    int insert(int key, int value){
        int insertion_index = hash(key);
        if(map->at(insertion_index).size() >= bucket_size){
            rehash(); //should make insertion into the index possible (change idx)
        }
        std::pair<int,int>* p = new std::pair<int,int>;
        p->first = key;
        p->second = value;
        map->at(insertion_index).push_back(*p);
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

    void print(){
        for(auto buck_itor = map->begin(); buck_itor != map->end(); ++buck_itor){
            std::vector<std::pair<int,int>> bucket = *buck_itor;
            for(auto itor = bucket.begin(); itor != bucket.end(); ++itor){
                std::pair<int,int> p = *itor;
                printf("(%d, %d)\n", p.first, p.second);
            }
        }
    }

};

#endif