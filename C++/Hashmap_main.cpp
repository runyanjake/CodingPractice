/*
 * @author Jake Runyan
 * hashmap.cpp
 * @desc Hashmap implementation in C++
 */

#include <vector>
#include <cmath>
using namespace std;

#include "Hashmap.h"

int main(int argc, char** argv){
    printf("Creating hashmap... ");
    Hashmap* h = new Hashmap; 
    printf("Done\n");

    for(long long a=0;a<1000;++a){
        h->insert(rand() % 1000,a);
        // h->print();
        // h->printInternals();
    }

    delete h;
    return 0;
}