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
    std::vector<std::tuple<int,int,int>>* edge_set; //(idx,src,dst)
    std::vector<std::tuple<int,int>>* vertex_set; //(idx,value)
public:
    Graph();
    ~Graph();
    int addVertex(int val=INF);
    int addEdge(int src, int dst);
    void print();
};

class UndirectedGraph : protected Graph {
protected:
    //edges and vertices are inherited
public:
    UndirectedGraph();
    ~UndirectedGraph();
    static void dijkstraAlgorithm();
    static void kruskalAlgorithm();
    static void primAlgorithm();
};

class DirectedGraph : protected Graph {
protected:
    //edges and vertices are inherited
public:
    DirectedGraph();
    ~DirectedGraph();
    static int maxFlow();
    static int minCut();
};

#endif