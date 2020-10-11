//
// Created by 喻如辰 on 2020/10/11.
// 顺序栈 SequenceStack
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_SEQSTACK_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_SEQSTACK_H

#define DEFAULT_SIZE 10

enum StatusCode {SUCCESS = 0, FAIL, UNDER_FLOW, OVER_FLOW,
    RANGE_ERROR, DUPLICATE_ERROR,NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED};

template <class DataType>
class SeqStack {
protected:
    DataType*   array;                                                  // 元素的存储空间
    int         count;                                                  // 元素的个数
    int         maxSize;                                                // 栈能存储的元素最大个数

    // 辅助函数
    bool Full() const;                                                  // 判断栈是否已满
    void Init(int size);                                                // 初始化一个最大能存储size个元素的栈
public:
    SeqStack (int size = DEFAULT_SIZE);                                 // 构造函数
    SeqStack (const SeqStack<DataType>& copy);                          // 深复制，复制构造函数
    SeqStack (int maxSize, const DataType* a, int from, int to);        // 直接用一个数组初始化

    virtual ~SeqStack();                                                // 析构函数

    int     Length() const;                                             // 返回栈的长度
    bool    Empty() const;                                              // 判断栈是否为空
    void    Clear();                                                    // 清空栈

    void Traverse (int from, int to) const;                             // 遍历

    StatusCode Push(const DataType& d);                                 // d压入栈顶
    StatusCode Top(DataType& d);                                        // 将栈顶元素存储到d中
    StatusCode Pop(DataType& d);                                        // 出栈栈顶元素，并保存到d中

    SeqStack<DataType>& operator = (const SeqStack<DataType>& copy);    // 重载操作符=
};

template <class DataType>
bool SeqStack<DataType>::Full () const {
    return (count == maxSize);
}

template <class DataType>
void SeqStack<DataType>::Init (int size) {
    this -> maxSize = size;
    if(array != nullptr) delete []array;
    array = new DataType[maxSize];
    count = 0;
}

template <class DataType>
SeqStack<DataType>::SeqStack (int size) {
    array = nullptr;
    Init(size);
}

template <class DataType>
SeqStack<DataType>::SeqStack (const SeqStack<DataType>& copy) {
    // 深复制
    array = nullptr;
    Init(copy.maxSize);
    this -> count = copy.count;
    for(int i = 1; i <= count; ++i) {
        array[i - 1] = copy.array[i - 1];
    }
}

template <class DataType>
SeqStack<DataType>::SeqStack (int maxSize, const DataType* a, int from, int to) {
    array = nullptr;
    Init(maxSize);
    this -> count = 0;
    for(int i = from; i <= to; ++i) {
        array[i - 1] = a[i - 1];
        count++;
    }
}

template <class DataType>
SeqStack<DataType>::~SeqStack () {
    maxSize = 0;
    count = 0;
    delete [] array;
}

template <class DataType>
int SeqStack<DataType>::Length () const {
    return count;
}

template <class DataType>
bool SeqStack<DataType>::Empty () const {
    return (count == 0);
}

template <class DataType>
void SeqStack<DataType>::Clear (){
    // 不删除内存块中存储的内容，记数为0，需要存储其它内容时候直接覆盖；
    count = 0;
}

template <class DataType>
void SeqStack<DataType>::Traverse (int from, int to) const {
    for(int i = from; i <= to; i++) {
        std::cout << array[i - 1] << " ";
    }
    std::cout << std::endl;
}

template <class DataType>
StatusCode SeqStack<DataType>::Push (const DataType& d) {
    if(Full()) {
        return OVER_FLOW;
    } else {
        array[count++] = d;
        return SUCCESS;
    }
}

template <class DataType>
StatusCode SeqStack<DataType>::Top (DataType& d) {
    if(Empty()) {
        return UNDER_FLOW;
    } else {
        d = array[count - 1];
        return SUCCESS;
    }
}

template <class DataType>
StatusCode SeqStack<DataType>::Pop (DataType& d) {
    if(Empty()) {
        return UNDER_FLOW;
    } else {
        d = array[--count];
        return SUCCESS;
    }
}

template <class DataType>
SeqStack<DataType>& SeqStack<DataType>::operator= (const SeqStack<DataType>& copy) {
    if(&copy != this) {
        Init(copy.maxSize);
        count = copy.count;
        for(int i = 0; i <= count; i++) {
            array[i - 1] = copy.array[i - 1];
        }
    }
    return *this;
}

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_SEQSTACK_H
