/*
 * @author Jake Runyan
 * Hashmap.h
 * @desc <int,int> Hashmap implementation in C++
 */

#ifndef HASHMAP_H
#define HASHMAP_H

#include <vector>
#include <iostream>

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
    //Constructor to create a new Hashmap
    Hashmap(){
        bucket_size = STARTING_BUCKET_SIZE;
        num_buckets = STARTING_NUM_BUCKETS;
        load_factor = 0.0;
        filled = 0;
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
        return key % num_buckets;
    }

    //resize and rehashes the table by increasing the table dimensions by a factor of RESIZE_FACTOR
    //this is SLOW so try not to do it often
    int rehash(){
        bucket_size *= RESIZE_FACTOR;
        num_buckets *= RESIZE_FACTOR;
        std::vector<std::pair<int,int>>* allPairs = new std::vector<std::pair<int,int>>();
        for(auto buck_itor = map->begin(); buck_itor != map->end(); ++buck_itor){
            std::vector<std::pair<int,int>> bucket = *buck_itor;
            auto itor = bucket.begin();
            while(itor != bucket.end()){
                allPairs->push_back(*itor);
                bucket.erase(itor);
            }
        }
        while(map->size() < num_buckets){
            std::vector<std::pair<int,int>>* buck = new std::vector<std::pair<int,int>>();
            map->push_back(*buck);
        }
        for(std::pair<int,int> p : *allPairs){
            insert(p.first,p.second);
        }
        load_factor = (float)filled / (bucket_size * num_buckets);
        delete allPairs;
        allPairs = nullptr;

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
        ++filled;
        load_factor = (float)filled / (bucket_size * num_buckets);
        if(load_factor > 0.75){
            rehash(); //should make insertion into the index possible (change idx)
        }
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
        printf("Load Factor: %.4f (%lld/%lld)\n", load_factor, filled, (bucket_size*num_buckets));
    }

    void printInternals(){
        int buck = 0;
        for(auto buck_itor = map->begin(); buck_itor != map->end(); ++buck_itor){
            std::vector<std::pair<int,int>> bucket = *buck_itor;
            // printf("Bucket %d filled %lu/%lld\n", buck, bucket.size(), bucket_size);
            printf("Bucket %d: ", buck);
            for(auto itor = bucket.begin(); itor != bucket.end(); ++itor){
                std::pair<int,int> p = *itor;
                printf("(%d, %d) ", p.first, p.second);
            }
            printf("\n");
            ++buck;
        }
    }

};

#endif