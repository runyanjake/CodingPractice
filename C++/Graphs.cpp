/*
 * @author Jake Runyan
 * Graphs.cpp
 * @desc Graph/UndirectedGraph + common alg implementation in C++
 */

#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include "Graphs.h"

Graph::Graph(){
    edge_set = new std::vector<std::tuple<int,int,int,int>>;
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

int Graph::addEdge(int src, int dst, int weight){
    int numEdges = vertex_set->size();
    if(src>numEdges || dst > numEdges || src<0 || dst <0 || src==dst)
        return 1;
    edge_set->push_back(*(new std::tuple<int,int,int,int>(edge_set->size()+1, src, dst, weight)));
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
        printf("(%d,%d,%d,%d)\n", std::get<0>(*itor), std::get<1>(*itor), std::get<2>(*itor), std::get<3>(*itor));
    }
}

UndirectedGraph::UndirectedGraph() : Graph::Graph() {

}

UndirectedGraph::~UndirectedGraph() {
    
}

void UndirectedGraph::dijkstraAlgorithm(int startNode){
    for(auto itor = vertex_set->begin(); itor != vertex_set->end(); ++itor){
        if(std::get<0>(*itor) == startNode)
            std::get<1>(*itor) = 0;
        else
            std::get<1>(*itor) = INF;
    }

    std::queue<std::tuple<int,int>>* vertex_queue = new std::queue<std::tuple<int,int>>();
    std::unordered_map<int,bool>* visited = new std::unordered_map<int,bool>();
    vertex_queue->push(vertex_set->at(startNode-1));
    visited->insert({startNode-1, true});

    while(vertex_queue->size() > 0){
        std::tuple<int,int> parent_ref = vertex_queue->back();
        vertex_queue->pop();
        int parent_idx = std::get<0>(parent_ref)-1;
        visited->insert({parent_idx, true});

        printf("Considering vertex %d.\n", parent_idx+1);
        for(std::tuple<int,int,int,int> edge : *edge_set){
            int child_idx = -1;
            int edge_src_idx = std::get<1>(edge)-1;
            int edge_dst_idx = std::get<2>(edge)-1;
            if(edge_src_idx == parent_idx)
                child_idx = edge_dst_idx;
            else if(edge_dst_idx == parent_idx)
                child_idx = edge_src_idx;
            else
                continue;

            printf("Vertex %d has child at %d.\n", parent_idx+1, child_idx+1);
            std::tuple<int,int>* child_ref = &vertex_set->at(child_idx);
            try{
                bool child_is_visited = visited->at(child_idx);
                printf("Vertex %d was visited already.\n", child_idx+1);
            }catch(std::out_of_range){
                int child_value = std::get<1>(*child_ref);
                int parent_value = std::get<1>(parent_ref);
                int edge_value = std::get<3>(edge);
                if(parent_value + edge_value < child_value){
                    std::get<1>(*child_ref) = parent_value + edge_value;
                    printf("Vertex %d's value was updated to %d.\n", child_idx+1, parent_value+edge_value);
                }else{
                    printf("Vertex %d's value was not updated.\n", child_idx+1);
                }
                vertex_queue->push(*child_ref);
            }
        }


    }

    delete vertex_queue;
    vertex_queue = nullptr;
    delete visited;
    visited = nullptr;
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
        printf("(%d,%d,%d,%d)\n", std::get<0>(*itor), std::get<1>(*itor), std::get<2>(*itor), std::get<3>(*itor));
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
        printf("(%d,%d,%d,%d)\n", std::get<0>(*itor), std::get<1>(*itor), std::get<2>(*itor), std::get<3>(*itor));
    }
}