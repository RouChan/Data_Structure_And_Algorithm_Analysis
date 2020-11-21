//
// Created by 喻如辰 on 2020/11/20.
// 无向图邻接表
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_ADJ_UNDIRECTED_GRAPH_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_ADJ_UNDIRECTED_GRAPH_H

#include "SinglyLinkedList.h"
#include "vertex.h"
#include "global.h"
#include "LkQueue.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

template <class DataType>
class AdjUndirGraph {
protected:
    int                 vexNum;                                         // amounts of vertexes
    Vertex<DataType>    *vexTable;                                      // list of vertexes
    List<int>           *adjRelation;                                   // relations between vertexes

    void    MarkHelp();                                                 // mark IsVisited of every vertex false
    void    DFSearchHelp(int v) const;                                  // assistant function for depth first search
    void    BFSearchHelp() const;                                       // assistant function for breadth first search
public:
    AdjUndirGraph(DataType *V, int number);                             // constructor
    ~AdjUndirGraph();                                                   // destructor

    int     GetVertexNum() const;                                       // return amounts of vertexes
    void    ShowAdjVertex(int num) const;                               // show adjacent vertexes of certain one
    void    InsertEdge(int v1, int v2);                                 // establish relation between v1&v2
    void    DeleteEdge(int v1, int v2);                                 // delete relation between v1&v2
    void    DFSearch();                                                 // depth first search
    void    BFSearch();                                                 // breadth first search
    void    Clear();                                                    // clear the graph

    StatusCode GetVertex(int num, DataType& d) const;                   // get certain vertex
    StatusCode SetVertex(int num, const DataType& d);                   // set certain vertex
};

template <class DataType>
AdjUndirGraph<DataType>::AdjUndirGraph (DataType *V, int number) {
    vexNum      = number;
    vexTable    = new Vertex<DataType>[vexNum];
    adjRelation = new List<int>[vexNum];
    for(int i = 0; i < vexNum; ++i) {
        vexTable[i].data = V[i];
    }
}

template <class DataType>
AdjUndirGraph<DataType>::~AdjUndirGraph () {
   Clear();
}

template <class DataType>
void AdjUndirGraph<DataType>::MarkHelp () {
    for(int i = 0; i < vexNum; ++i) {
        vexTable[i].IsVisited = false;
    }
}

template <class DataType>
void AdjUndirGraph<DataType>::DFSearchHelp (int v) const {
    if(vexTable[v].IsVisited) {
        return ;
    } else {
        vexTable[v].IsVisited = true;
        cout << vexTable[v].data << " ";
        int adjNum = adjRelation[v].Length();
        for(int i = 1; i <= adjNum; ++i) {
            int tmpAdj;
            adjRelation[v].GetNode(i, tmpAdj);
            DFSearchHelp(tmpAdj);
        }
        return ;
    }
}

template <class DataType>
void AdjUndirGraph<DataType>::BFSearchHelp () const {
    LinkQueue<int> searchOrder;
    searchOrder.Push(0);

    while(!searchOrder.Empty()) {
        int tmpAdj;
        searchOrder.Front(tmpAdj);

        if(vexTable[tmpAdj].IsVisited == false) {
            vexTable[tmpAdj].IsVisited = true;
            cout << vexTable[tmpAdj].data << " ";
            int adjNum = adjRelation[tmpAdj].Length();
            for(int i = 1; i <= adjNum; ++i) {
                int t;
                adjRelation[tmpAdj].GetNode(i, t);
                searchOrder.Push(t);
            }
        }
        searchOrder.Pop(tmpAdj);
    }
    cout << endl;
}

template <class DataType>
int AdjUndirGraph<DataType>::GetVertexNum () const {
    return vexNum;
}

template <class DataType>
void AdjUndirGraph<DataType>::ShowAdjVertex (int num) const {
    int adjNum = adjRelation[num].Length();
    for(int i = 1; i <= adjNum; ++i) {
        int tmp;
        adjRelation[num].GetNode(i, tmp);
        cout << vexTable[tmp].data << " ";
    }
    cout << endl;
}

template <class DataType>
void AdjUndirGraph<DataType>::InsertEdge (int v1, int v2) {
    if((v1 < 0 || v1 >= vexNum) || (v1 == v2) || (v2 < 0 || v2 >= vexNum)) {
        return ;
    } else {
        int tmpLen = adjRelation[v1].Length();
        for(int i = 1; i <= tmpLen; ++i) {
            int tmp;
            adjRelation[v1].GetNode(i, tmp);
            if(tmp == v2) return ;
        }
        adjRelation[v1].Insert(tmpLen + 1, v2);
        adjRelation[v2].Insert(adjRelation[v2].Length() + 1, v1);
    }
}

template <class DataType>
void AdjUndirGraph<DataType>::DeleteEdge (int v1, int v2) {
    if((v1 < 0 || v1 >= vexNum) || (v1 == v2) || (v2 < 0 || v2 >= vexNum)) {
        return ;
    } else {
        int tmpLen = adjRelation[v1].Length();
        int i = 1;
        for(; i <= tmpLen; ++i) {
            int tmp;
            adjRelation[v1].GetNode(i, tmp);
            if(tmp == v2) {
                adjRelation[v1].Delete(i, tmp);
                break ;
            }
        }
        tmpLen = adjRelation[v2].Length();
        for(i = 1; i <= tmpLen; ++i) {
            int tmp;
            adjRelation[v2].GetNode(i, tmp);
            if(tmp == v1) {
                adjRelation[v2].Delete(i, tmp);
                break ;
            }
        }
        return ;
    }
}

template <class DataType>
void AdjUndirGraph<DataType>::DFSearch () {
    MarkHelp();
    DFSearchHelp(0);
}

template <class DataType>
void AdjUndirGraph<DataType>::BFSearch () {
    MarkHelp();
    BFSearchHelp();
}

template <class DataType>
void AdjUndirGraph<DataType>::Clear () {
    delete []vexTable;
    for(int i = 0; i < vexNum; ++i) {
        adjRelation[i].Clear();
    }
    delete []adjRelation;
}

template <class DataType>
StatusCode AdjUndirGraph<DataType>::GetVertex (int num, DataType& d) const {
    if(num >= vexNum) {
        return FAIL;
    } else {
        d = vexTable[num].data;
        return SUCCESS;
    }
}

template <class DataType>
StatusCode AdjUndirGraph<DataType>::SetVertex (int num, const DataType& d) {
    if(num >= vexNum) {
        return FAIL;
    } else {
        vexTable[num].data = d;
        return SUCCESS;
    }
}

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_ADJ_UNDIRECTED_GRAPH_H
