/*
 * @author Jake Runyan
 * Hashmap.h
 * @desc Hashmap implementation in C++
 * @note Implementation MUST be done in the .h file for generic classes
 *     because of the way compilation around template classes is done.
 */

#ifndef GENERIC_HASHMAP_H
#define GENERIC_HASHMAP_H

#include <vector>

#define STARTING_BUCKET_SIZE 25
#define STARTING_NUM_BUCKETS 10

template<class K, class V>
class Hashmap {
private:
    int bucket_size;
    int num_buckets;
    float load_factor;
    std::vector<std::vector<std::pair<K,V>>>* map;
public:
    Hashmap(){
        bucket_size = STARTING_BUCKET_SIZE;
        num_buckets = STARTING_NUM_BUCKETS;
        load_factor = 0.0;
        std::vector<std::vector<std::pair<K,V>>> tmp = std::vector<std::vector<std::pair<K,V>>>();
        for(int a=0; a<num_buckets; ++a){
            std::vector<std::pair<K,V>> buck = std::vector<std::pair<K,V>>();
            tmp.push_back(buck);
        }

        map = &tmp;
    }
    ~Hashmap(){
        printf("Hashmap Deconstructor\n");
    }

    int insert(K key, V value){
        // map->at(0).push_back(std::pair<K,V>(key, value));


        for(auto outside_itor = map->begin(); outside_itor != map->end(); ++outside_itor){
            // for(auto itor = *outside_itor.begin(); itor != *outside_itor.end(); ++itor){
            //     std::cout << "(" << *itor[0] << ", " << *itor[1] << ")" << std::endl;
            // }
            print("length: %d\n", *outside_itor.size());
        }


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