//
// Created by 喻如辰 on 2020/11/20.
// 图&网的结点类 vertex，主要功能添加tag标示是否被访问
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_VERTEX_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_VERTEX_H

template <class DataType>
struct Vertex{
    DataType    data;                   // 结点数据
    bool        IsVisited;              // 是否被访问过的标记

    Vertex();                           // 构造函数
    Vertex(DataType &d);
};

template <class DataType>
Vertex<DataType>::Vertex() {
    IsVisited = false;
}

template <class DataType>
Vertex<DataType>::Vertex (DataType& d) {
    data = d;
    IsVisited = false;
}

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_VERTEX_H
