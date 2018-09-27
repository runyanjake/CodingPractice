/*
 * @author Jake Runyan
 * Hashmap.h
 * @desc Hashmap implementation in C++
 * @note Implementation MUST be done in the .h file for generic classes
 *     because of the way compilation around template classes is done.
 */

#ifndef HASHMAP_H
#define HASHMAP_H

#include <vector>

#define STARTING_BUCKET_SIZE = 25
#define STARTING_NUM_BUCKETS = 10

template<class K, class V>
class Hashmap {
private:
    int bucket_size;
    int num_buckets;
    float load_factor;
    std::vector<std::vector<std::pair<K,V>>>* map;
public:
    Hashmap(){
        printf("Hashmap Constructor\n");
    }
    ~Hashmap(){
        printf("Hashmap Deconstructor\n");
    }

    int insert(K key, V value){
        return 0;
    }
    V remove(K key){
        return 0;
    }
    V get(K key){
        return 0;
    }
    bool exists(K key){
        return 0;
    }

};

#endif