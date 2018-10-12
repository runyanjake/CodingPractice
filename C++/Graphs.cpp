/*
 * @author Jake Runyan
 * Graphs.cpp
 * @desc Graph/UndirectedGraph + common alg implementation in C++
 */

#include <vector>
#include <iostream>
#include "Graphs.h"

Graph::Graph(){
    edge_set = new std::vector<std::tuple<int,int,int>>;
    vertex_set = new std::vector<std::tuple<int,int>>;
}

Graph::~Graph(){
    delete edge_set;
    edge_set = nullptr;
    delete vertex_set;
    vertex_set = nullptr;
}

int Graph::addVertex(int val){
    vertex_set->push_back(*(new std::tuple<int,int>(vertex_set->size()+1, val)));
    return 0;
}

int Graph::addEdge(int src, int dst){
    int numEdges = vertex_set->size();
    if(src>numEdges || dst > numEdges || src<0 || dst <0 || src==dst)
        return 1;
    edge_set->push_back(*(new std::tuple<int,int,int>(edge_set->size()+1, src, dst)));
    return 0;
}

void Graph::print() {
    printf("Vertex Set: ");
    bool first = true;
    for(auto itor = vertex_set->begin(); itor != vertex_set->end(); ++itor){
        if(first)
            printf("(%d,%d)", std::get<0>(*itor), std::get<1>(*itor));
        else
            printf(" (%d,%d)", std::get<0>(*itor), std::get<1>(*itor));
    }
    printf("\nEdge Set:\n");
    for(auto itor = edge_set->begin(); itor != edge_set->end(); ++itor){
        printf("(%d,%d,%d)\n", std::get<0>(*itor), std::get<1>(*itor), std::get<2>(*itor));
    }
}

UndirectedGraph::UndirectedGraph(){

}

UndirectedGraph::~UndirectedGraph(){
    
}

static void dijkstraAlgorithm(){
}

static void kruskalAlgorithm(){
    
}

static void primAlgorithm(){
    
}

void UndirectedGraph::print(){
    printf("Vertex Set (Undirected): ");
    bool first = true;
    for(auto itor = vertex_set->begin(); itor != vertex_set->end(); ++itor){
        if(first)
            printf("(%d,%d)", std::get<0>(*itor), std::get<1>(*itor));
        else
            printf(" (%d,%d)", std::get<0>(*itor), std::get<1>(*itor));
    }
    printf("\nEdge Set (Undirected):\n");
    for(auto itor = edge_set->begin(); itor != edge_set->end(); ++itor){
        printf("(%d,%d,%d)\n", std::get<0>(*itor), std::get<1>(*itor), std::get<2>(*itor));
    }
}

DirectedGraph::DirectedGraph(){

}

DirectedGraph::~DirectedGraph(){

}

static int maxFlow(){
    return -1;
}

static int minCut(){
    return -1;
}

void DirectedGraph::print(){
    printf("Vertex Set (Directed): ");
    bool first = true;
    for(auto itor = vertex_set->begin(); itor != vertex_set->end(); ++itor){
        if(first)
            printf("(%d,%d)", std::get<0>(*itor), std::get<1>(*itor));
        else
            printf(" (%d,%d)", std::get<0>(*itor), std::get<1>(*itor));
    }
    printf("\nEdge Set(Directed):\n");
    for(auto itor = edge_set->begin(); itor != edge_set->end(); ++itor){
        printf("(%d,%d,%d)\n", std::get<0>(*itor), std::get<1>(*itor), std::get<2>(*itor));
    }
}