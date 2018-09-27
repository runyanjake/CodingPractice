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
    Hashmap<int,int> h; //still calls ctor
    printf("Done\n");
    return 0;
}