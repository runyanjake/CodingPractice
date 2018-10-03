/*
 * @author Jake Runyan
 * hashmap.cpp
 * @desc Hashmap implementation in C++
 */

#include <vector>
#include <cmath>
using namespace std;

#include "Hashmap.h"
#include "Generic_Hashmap.h"

int main(int argc, char** argv){

    // Generic_Hashmap<int,int>* h = new Generic_Hashmap<int,int>; 
    // for(long long a=-4;a<15;++a){ h->insert(7,a*2); }
    // h->remove(4); h->remove(0);
    // h->remove(-1); h->remove(15);
    // h->print();
    // printf("%d\n", h->get(7));
    // h->update(7, 5555);
    // printf("%d\n", h->get(9090));

    Generic_Hashmap<std::string,std::string>* h = new Generic_Hashmap<string,string>; 
    std::string key = "a", val = "b";
    for(long long a=-4;a<15;++a){ h->insert(key,val); key+="a"; val+="b"; }
    h->print();

    delete h;
    return 0;
}