/*
 * @author Jake Runyan
 * Hashmap.h
 * @desc Hashmap implementation in C++
 */

#ifndef GENERIC_HASHMAP_H
#define GENERIC_HASHMAP_H

#include <vector>
#include <iostream>
#include <cmath>

#define STARTING_BUCKET_SIZE 2
#define STARTING_NUM_BUCKETS 2
#define RESIZE_FACTOR 2

template<class K, class V>
class Generic_Hashmap {
private:
    long long bucket_size;
    long long num_buckets;
    float load_factor;
    long long filled;
    std::vector<std::vector<std::pair<K,V>>>* map;
public:
    //Constructor to create a new Hashmap
    Generic_Hashmap(){
        bucket_size = STARTING_BUCKET_SIZE;
        num_buckets = STARTING_NUM_BUCKETS;
        load_factor = 0.0;
        filled = 0;
        map = new std::vector<std::vector<std::pair<K,V>>>();
        for(int a=0; a<num_buckets; ++a){
            std::vector<std::pair<K,V>>* buck = new std::vector<std::pair<K,V>>();
            map->push_back(*buck);
        }
    }
    //Deconstructor deletes any dynamically allocated memory.
    ~Generic_Hashmap(){
        delete map;
        map = nullptr;
    }

    //Hashes key to return the bucket to retrieve/place in.
    int hash(K key){
        // return abs(key) % num_buckets;
        return 0;
    }

    //resize and rehashes the table by increasing the table dimensions by a factor of RESIZE_FACTOR
    //this is SLOW so try not to do it often
    int rehash(){
        bucket_size *= RESIZE_FACTOR;
        num_buckets *= RESIZE_FACTOR;
        std::vector<std::pair<K,V>>* allPairs = new std::vector<std::pair<K,V>>();
        for(auto buck_itor = map->begin(); buck_itor != map->end(); ++buck_itor){
            auto itor = (*buck_itor).begin();
            while(itor != (*buck_itor).end()){
                allPairs->push_back(*itor);
                itor = (*buck_itor).erase(itor);
                --filled;
            }
        }
        while(map->size() < num_buckets){
            std::vector<std::pair<K,V>>* buck = new std::vector<std::pair<K,V>>();
            map->push_back(*buck);
        }
        for(std::pair<K,V> p : *allPairs){
            insert(p.first,p.second);
        }
        load_factor = (float)filled / (bucket_size * num_buckets);
        delete allPairs;
        allPairs = nullptr;

        return 0;
    }

    //Inserts a key/value pair into the hashtable. Returns 0 if unsuccessful
    int insert(K key, V value){
        if(exists(key)){
            return 1;
        }
        int insertion_index = hash(key);
        if(map->at(insertion_index).size() >= bucket_size){
            rehash(); 
        }
        std::pair<K,V>* p = new std::pair<K,V>;
        p->first = key;
        p->second = value;
        map->at(insertion_index).push_back(*p);
        ++filled;
        load_factor = (float)filled / (bucket_size * num_buckets);
        if(load_factor > 0.75){
            rehash();
        }
        return 0;
    }

    //Remove a key/value pair from the hashmap. Returns 1 if no such pair exists.
    int remove(K key){
        int insertion_index = hash(key);
        for(auto itor = map->at(insertion_index).begin(); itor != map->at(insertion_index).end(); ++itor){
            if(itor->first == key){
                map->at(insertion_index).erase(itor);
                return 0;
            }
        }
        return 1;
    }

    //Returns the value corresponding to the key in the hashmap. If not found, returns default constructor for value.
    V get(K key){
        int insertion_index = hash(key);
        for(auto itor = map->at(insertion_index).begin(); itor != map->at(insertion_index).end(); ++itor){
            if(itor->first == key){
                return itor->second;
            }
        }
        return V();
    }

    //Updates the value corresponding to the key in the hashmap to val. If not found, returns 1.
    int update(K key, V val){
        int insertion_index = hash(key);
        for(auto itor = map->at(insertion_index).begin(); itor != map->at(insertion_index).end(); ++itor){
            if(itor->first == key){
                itor->second = val;
                return 0;
            }
        }
        return 1;
    }

    bool exists(K key){
        int insertion_index = hash(key);
        for(auto itor = map->at(insertion_index).begin(); itor != map->at(insertion_index).end(); ++itor){
            if(itor->first == key){
                return 1;
            }
        }
        return 0;
    }

    void print(){
        for(auto buck_itor = map->begin(); buck_itor != map->end(); ++buck_itor){
            std::vector<std::pair<K,V>> bucket = *buck_itor;
            for(auto itor = bucket.begin(); itor != bucket.end(); ++itor){
                std::pair<K,V> p = *itor;
                // printf("(%d, %d)\n", p.first, p.second);
                std::cout << "(" << p.first << "," << p.second << ")" << std::endl;
            }
        }
        printf("Load Factor: %.4f (%lld/%lld)\n", load_factor, filled, (bucket_size*num_buckets));
    }

    void printInternals(){
        int buck = 0;
        for(auto buck_itor = map->begin(); buck_itor != map->end(); ++buck_itor){
            std::vector<std::pair<K,V>> bucket = *buck_itor;
            // printf("Bucket %d filled %lu/%lld\n", buck, bucket.size(), bucket_size);
            printf("Bucket %d: ", buck);
            std::cout << "Bucket " << buck << ": ";
            for(auto itor = bucket.begin(); itor != bucket.end(); ++itor){
                std::pair<K,V> p = *itor;
                // printf("(%d, %d) ", p.first, p.second);
                std::cout << "(" << p.first << "," << p.second << ") ";
            }
            // printf("\n");
            std::cout << std::endl;
            ++buck;
        }
    }

};

#endif