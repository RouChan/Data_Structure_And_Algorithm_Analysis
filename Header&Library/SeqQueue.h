//
// Created by 喻如辰 on 2020/10/11.
// (循环)顺序队列，Sequence_Queue
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_SEQQUEUE_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_SEQQUEUE_H

#define DEFAULT_SIZE 10

enum StatusCode {SUCCESS = 0, FAIL, UNDER_FLOW, OVER_FLOW,
    RANGE_ERROR, DUPLICATE_ERROR,NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED};

// 在开辟的数组中，少用一个元素空间，在Push()函数前先调用Full()，
// 避免队满和队空时rear==front同时成立的情况；
template <class DataType>
class SeqQueue {
protected:
    int         front, rear;                                        // 队伍a1、队尾an。其中front、rear直接为从0开始的数组下标
    int         maxSize;                                            // 队列最大存储元素个数
    DataType*   array;                                              // 元素存储空间

    // 辅助函数
    bool Full() const;                                              // 判断队列是否已满
    void Init(int size);                                            // 初始化队列
public:
    SeqQueue(int size = DEFAULT_SIZE);                              // 构造函数
    SeqQueue(const SeqQueue<DataType>& copy);                       // 复制构造函数
    virtual ~SeqQueue();                                            // 析构函数

    int     Length() const;                                         // 求队列的长度(元素个数)
    bool    Empty() const;                                          // 判断队列是否为空
    void    Clear();                                                // 清空队列
    void    Traverse() const;                                       // 遍历

    StatusCode Pop(DataType& d);                                    // 弹出队列第一个元素
    StatusCode Front(DataType& d) const;                            // 取队列第一个元素的值
    StatusCode Push(const DataType& d);                             // 元素入栈

    SeqQueue<DataType>& operator= (const SeqQueue<DataType>& copy); // =操作符重载
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
SeqQueue<DataType>::SeqQueue (const SeqQueue<DataType>& copy) {
    array = nullptr;
    Init(copy.maxSize);
    front = copy.front;
    rear = copy.rear;
    for(int i = front; i < rear; i = (i + 1) % maxSize) {
        array[i] = copy.array[i];
    }
}


template <class DataType>
SeqQueue<DataType>::~SeqQueue () {
    delete []array;
}

template <class DataType>
int SeqQueue<DataType>::Length () const {
    return ((rear - front + maxSize) % maxSize);
}

template <class DataType>
bool SeqQueue<DataType>::Empty () const {
    return (rear == front);
}

template <class DataType>
void SeqQueue<DataType>::Clear () {
    delete []array;
    array = nullptr;
    maxSize = rear = front = 0;
}

template <class DataType>
void SeqQueue<DataType>::Traverse () const {
    for (int i = front; i < rear; i = (i + 1) % maxSize) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template <class DataType>
StatusCode SeqQueue<DataType>::Pop (DataType& d) {
    if(!Empty()) {
        d = array[front];
        front = (front + 1) % maxSize;
        return SUCCESS;
    } else {
        return UNDER_FLOW;
    }
}

template <class DataType>
StatusCode SeqQueue<DataType>::Front (DataType& d) const {
    if(!Empty()) {
        d = array[front];
        return SUCCESS;
    } else {
        return RANGE_ERROR;
    }
}

template <class DataType>
StatusCode SeqQueue<DataType>::Push (const DataType& d) {
    if(Full()) {
        return OVER_FLOW;
    } else {
        array[rear] = d;
        rear = (rear + 1) % maxSize;
        return SUCCESS;
    }
}

template <class DataType>
SeqQueue<DataType>& SeqQueue<DataType>::operator= (const SeqQueue<DataType>& copy) {
    if(&copy != this) {
        Init(copy.maxSize);
        front = copy.front;
        rear = copy.rear;
        for(int i = front; i < rear; i = (i + 1) % maxSize) {
            array[i] = copy.array[i];
        }
    }
    return *this;
}

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_SEQQUEUE_H
