/*
 * @author Jake Runyan
 * Graphs.h
 * @desc Graph/UndirectedGraph + common alg implementation in C++
 */

#ifndef GRAPHS_H
#define GRAPHS_H

#include <vector>
#include <iostream>
#include <tuple>

#define INF INT_MAX
#define NINF INT_MIN

class Graph {
protected:
    std::vector<std::tuple<int,int,int,int>>* edge_set; //(idx,src,dst,weight)
    std::vector<std::tuple<int,int>>* vertex_set; //(idx,value)
public:
    Graph();
    ~Graph();
    int addVertex(int val=INF);
    int addEdge(int src, int dst, int weight);  
    virtual void print(); //is overridden by derived classes
};

class UndirectedGraph : public Graph {
private:
    //edges and vertices are accessed thru public calls inherited from Graph
public:
    UndirectedGraph();
    ~UndirectedGraph();
    void dijkstraAlgorithm(int startNode);
    void kruskalAlgorithm();
    void primAlgorithm();
    void print();
};

class DirectedGraph : public Graph {
private:
    //edges and vertices are accessed thru public calls inherited from Graph
public:
    DirectedGraph();
    ~DirectedGraph();
    int maxFlow();
    int minCut();
    void print();
};

#endif