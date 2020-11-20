//
// Created by 喻如辰 on 2020/11/20.
// 无向图邻接表
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_ADJ_UNDIRECTED_GRAPH_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_ADJ_UNDIRECTED_GRAPH_H

#include "SeqList.h"
#include "SinglyLinkedList.h"
#include "vertex.h"

template <class DataType>
class AdjUndirGraph {
protected:
    int                         vexNum;                                                 // amounts of vertexes
    SeqList<Vertex<DataType> >  *vexTable;                                              // list of vertexes
    SeqList<List<DataType*> >   **adjRelation;                                          // relations between vertexes
};

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_ADJ_UNDIRECTED_GRAPH_H
