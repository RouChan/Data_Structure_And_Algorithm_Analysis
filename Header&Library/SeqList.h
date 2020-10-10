//
// Created by 喻如辰 on 2020/9/28.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_SEQLIST_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_SEQLIST_H

enum StatusCode {SUCCESS = 0, FAIL, UNDER_FLOW, OVER_FLOW,
    RANGE_ERROR, DUPLICATE_ERROR,NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED};


template <class DataType>
class SeqList {
protected:
    DataType*   array;                                      // 元素存储空间
    int         count;                                      // 元素个数
    int         maxSize;                                    // 最大元素个数

    bool        Full() const;                               // 判断顺序表是否已满
    void        Init(int size);                             // 初始化顺序表
public:
    SeqList(int size);                                      // 声明、定义一个顺序表
    virtual ~SeqList();                                     // 析构函数

    int     Length() const;                                 // 返回顺序表的长度
    bool    Empty() const;                                  // 判断顺序表是否为空
    void    Clear();                                        // 清空顺序表
    void    Traverse() const;                               // 遍历

    StatusCode GetElem(int position, DataType& d) const;    // 求指定位置的元素，并存储到d中
    StatusCode SetElem(int position, const DataType& d);    // 设定position位置的元素为d
    StatusCode Delete (int position, DataType& d);          // 删除position位置元素，并将的d赋值为被删除元素值
    StatusCode Insert (int position, DataType& d);          // 在position位置前插入元素d

    SeqList<DataType>& operator = (const SeqList<DataType>& copy);  // 重载操作符
};

template <class DataType>
bool SeqList<DataType>::Full() const {
    return (count == maxSize);
}

template <class DataType>
void SeqList<DataType>::Init(int size) {
    count = 0;
    maxSize = size;
    if(array != nullptr) {
        delete []array;
    }
    array = new DataType[size];
}

template <class DataType>
SeqList<DataType>::SeqList(int size) {
    array = nullptr;
    Init(size);
}

template <class DataType>
SeqList<DataType>::~SeqList(){
    delete []array;
    array = nullptr;
}

template <class DataType>
int SeqList<DataType>::Length() const {
    return count;
}

template <class DataType>
bool SeqList<DataType>::Empty() const {
    return (count == 0);
}

template <class DataType>
void SeqList<DataType>::Clear() {
    delete []array;
    array = nullptr;
    count = 0;
}

template <class DataType>
void SeqList<DataType>::Traverse() const {
    for(int i = 0; i < Length(); i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

template <class DataType>
StatusCode SeqList<DataType>::GetElem(int position, DataType &d) const{
    if(position < 1 || position > Length()) {
        return RANGE_ERROR;
    } else {
        d = array[position - 1];
        return SUCCESS;
    }
}

template <class DataType>
StatusCode SeqList<DataType>::SetElem(int position, const DataType &d) {
    if(position < 1 || position > Length()) {
        return RANGE_ERROR;
    } else {
        array[position - 1] = d;
        return SUCCESS;
    }
}

template <class DataType>
StatusCode SeqList<DataType>::Delete(int position, DataType &d) {
    if(position < 1 || position > Length()) {
        return RANGE_ERROR;
    } else {
        GetElem(position, d);

        DataType tmp;
        int len = Length();
        for(int curPosition = position + 1; curPosition <= len; curPosition++) {
            GetElem(curPosition, tmp);
            SetElem(curPosition - 1, tmp);
        }
        count--;
        return SUCCESS;
    }
}

template <class DataType>
StatusCode SeqList<DataType>::Insert(int position, DataType &d) {
    if(Full()) {
        return RANGE_ERROR;
    } else if(position < 1 || position > Length() + 1) {
        return RANGE_ERROR;
    } else {
        count++;

        int len = Length();
        for(int curPosition = len; curPosition >= position; curPosition--) {
            DataType tmp;
            GetElem(curPosition, tmp);
            SetElem(curPosition + 1, tmp);

            SetElem(position, d);
            return SUCCESS;
        }
    }
}

template <class DataType>
SeqList<DataType>& SeqList<DataType>::operator = (const SeqList<DataType> &copy) {
    if (&this != copy) {
        Insert(copy.maxSize);
        int len = copy.Length();

        for(int curPosition = 1; curPosition <= len; curPosition++) {
            DataType tmp;
            copy.GetElem(curPosition, tmp);
            Insert(Length() + 1, tmp);
        }
        return *this;
    }
}

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_SEQLIST_H
