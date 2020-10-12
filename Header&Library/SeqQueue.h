//
// Created by 喻如辰 on 2020/10/11.
// (循环)顺序队列，Sequence_Queue
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_SEQQUEUE_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_SEQQUEUE_H

#define DEFAULT_SIZE 10

enum StatusCode {SUCCESS = 0, FAIL, UNDER_FLOW, OVER_FLOW,
    RANGE_ERROR, DUPLICATE_ERROR,NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED};

// 在开辟的数组中，少用一个元素空间，约定队头在队尾指针的下一位置时表示队满
template <class DataType>
class SeqQueue {
protected:
    int         front, rear;                                // 队伍a1、队尾an
    int         maxSize;                                    // 队列最大存储元素个数
    DataType*   array;                                      // 元素存储空间

    // 辅助函数
    bool Full() const;                                      // 判断队列是否已满
    void Init(int size);                                    // 初始化队列
public:
    SeqQueue(int size = DEFAULT_SIZE);                      // 构造函数
    virtual ~SeqQueue();                                    // 析构函数

    int     Length() const;                                 // 求队列的长度(元素个数)

    // todo: Empty();
    bool    Empty() const;                                  // 判断队列是否为空
};

template <class DataType>
bool SeqQueue<DataType>::Full () const {
    return (Length() == maxSize - 1);
}

template <class DataType>
void SeqQueue<DataType>::Init (int size) {
    maxSize = size;
    if(array != nullptr) delete []array;
    array = new DataType[maxSize];
    rear = front = 0;
}

template <class DataType>
SeqQueue<DataType>::SeqQueue (int size) {
    array = nullptr;
    Init(size);
}

template <class DataType>
SeqQueue<DataType>::~SeqQueue () {
    delete []array;
}

template <class DataType>
int SeqQueue<DataType>::Length () const {
    return ((rear - front + maxSize) % maxSize);
}

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_SEQQUEUE_H
