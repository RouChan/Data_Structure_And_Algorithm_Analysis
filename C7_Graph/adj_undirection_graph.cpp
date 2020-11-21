//
// Created by 喻如辰 on 2020/11/20.
// 无向图 邻接表 头文件调用 utility of adj_undirected_graph.h
//

#include <iostream>
#include "../Header&Library/adj_undirected_graph.h"
using namespace std;

int main () {
    int V[] = {21, 22, 23, 24, 25};
    AdjUndirGraph<int> Graph(V, 5);

    Graph.InsertEdge(0, 1);
    Graph.InsertEdge(1, 3);
//    Graph.InsertEdge(3, 4);
    Graph.InsertEdge(0, 2);
    Graph.InsertEdge(2, 4);

    Graph.BFSearch();
//    Graph.DFSearch();
    return 0;
}