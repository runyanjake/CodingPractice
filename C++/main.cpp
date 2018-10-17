//Jake Runyan

/* MANTRA FOR SOLVING CODING PROBLEMS
 * 1) Read/Listen to Problem. 
 * 2) General Problem Notes: Note important info. Write an example.
 * 3) Brute Force Solution: Note complexity.
 * 4) Better Solution (BUD Optimized: Bottlenecks, Unnecessary & Duplicate work.
 * 5) Walk through approach. Whiteboard it.
 * 6) Write the code.
 *      Assume helper methods, fill in later. 
 *      TODO error checks, maybe fill in later.
 *      Meaningful var names.
 * 7) Test  a) Conceptual
 *          b) Unusual/Non-std code
 *          c) Hot spots for arithmetic/null nodes
 *          d) Small test cases
 *          e) Special/Edge cases)
 */

#include <iostream>

#include "Graphs.h"
#include "Hashmap.h"
#include "HelloWorld.h"
#include "Generic_Hashmap.h"
#include "JQueue.h"
#include "JStack.h"

using namespace std;

int main(int argc, char* argv[]){
    HelloWorld *hw = new HelloWorld();
    delete hw;
    hw = nullptr;

    Hashmap *h = new Hashmap();
    delete h;
    h = nullptr;

    Generic_Hashmap<std::string,std::string> *gh = new Generic_Hashmap<std::string,std::string>();
    delete gh;
    gh = nullptr;

    JStack *s = new JStack();
    delete s;
    s = nullptr;

    JQueue *q = new JQueue();
    delete q;
    q = nullptr;

    UndirectedGraph *g = new UndirectedGraph();
    // for(int a=0;a<10;++a)
    //     g->addVertex();
    // for(int a=0;a<10;++a)
    //     g->addEdge(a+1,a+2,INF);
    for(int a=0;a<6;++a)
        g->addVertex();
    g->addEdge(1,2,1);
    g->addEdge(1,4,1);
    g->addEdge(2,4,2);
    g->addEdge(2,3,2);
    g->addEdge(4,3,3);
    g->addEdge(3,5,4);
    g->addEdge(4,5,2);
    g->addEdge(4,6,1);
    g->addEdge(5,6,5);
    printf("Before Dijkstra:\n");
    g->print();
    g->dijkstraAlgorithm(1);
    printf("\nAfter Dijkstra:\n");
    g->print();
    delete g;
    g = nullptr;
}