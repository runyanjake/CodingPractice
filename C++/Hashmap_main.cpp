/*
 * @author Jake Runyan
 * hashmap.cpp
 * @desc Hashmap implementation in C++
 */

#include <vector>
using namespace std;

#include "Hashmap.h"

int main(int argc, char** argv){
    printf("Creating hashmap... ");
    Hashmap* h = new Hashmap; 
    printf("Done\n");

    h->insert(1,3);

    delete h;
    return 0;
}