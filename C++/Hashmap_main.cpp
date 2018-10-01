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

    for(long long a=-4;a<15;++a){
        h->insert(7,a*2);
    }
    h->remove(4);
    h->remove(0);
    h->remove(-1);
    h->remove(15);

    h->print();
    printf("%d\n", h->get(7));
    h->update(7, 5555);
    printf("%d\n", h->get(7));

    delete h;
    return 0;
}