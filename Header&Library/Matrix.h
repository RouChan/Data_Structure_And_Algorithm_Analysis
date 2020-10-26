//
// Created by 喻如辰 on 2020/10/25.
// 特殊矩阵类，包括对称矩阵、三角矩阵，由基类Matrix衍生
//

#include <iostream>
#include <iomanip>

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_MATRIX_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_MATRIX_H
#define DEFAULT_SIZE 5

enum StatusCode {SUCCESS = 0, FAIL, UNDER_FLOW, OVER_FLOW,
    RANGE_ERROR, DUPLICATE_ERROR,NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED};

template <class DataType>
class Matrix {                                                      // 基类
protected:
    DataType    *data;                                              // 储存矩阵元素
    int         size;                                               // 阶数
public:
    Matrix(const int type, const int size = DEFAULT_SIZE);          // 构造函数，type区分对称矩阵、三角矩阵
    ~Matrix();                                                      // 析构函数

    int         GetSize() const;                                    // 返回阶数
    virtual DataType&   operator() (const int i, const int j) const = 0;
                                                                    // 返回[i, j]下标的元素
    virtual void        Traverse() const = 0;                       // 遍历
};

template <class DataType>
Matrix<DataType>::Matrix(const int type, const int size) {
    this -> size = size;
    if(type == 0) {                                                 // 对称矩阵
        data = new DataType[size * (size + 1) / 2];
        for(int i = 0; i < size * (size + 1) / 2; ++i) {
            data[i] = 0;
        }
    } else {                                                        // 三角矩阵
        data = new DataType[size * (size + 1) / 2 + 1];             // 0号位置存储常数
        for(int i = 0; i < size * (size + 1) / 2 + 1; ++i) {
            data[i] = 0;
        }
    }
}

template <class DataType>
Matrix<DataType>::~Matrix () {
    if(data != nullptr) delete []data;
}

template <class DataType>
int Matrix<DataType>::GetSize () const {
    return size;
}


template <class DataType>
class SymmetryMatrix : public Matrix<DataType> {                     // 对称矩阵
public:
    SymmetryMatrix(int size = DEFAULT_SIZE) : Matrix<DataType>(0, size){};
    DataType&   operator() (const int i, const int j) const;        // 返回[i, j]下标的元素
    void        Traverse() const;                                   // 遍历
};

template <class DataType>
DataType& SymmetryMatrix<DataType>::operator() (const int i, const int j) const {
    if(i <= j) {
        return Matrix<DataType>::data[(i - 1) * (2 * Matrix<DataType>::size - i + 2) / 2 + j - i];
    } else {
        return Matrix<DataType>::data[(j - 1) * (2 * Matrix<DataType>::size - j + 2) / 2 + i - j];
    }
}

template <class DataType>
void SymmetryMatrix<DataType>::Traverse () const {
    for(int i = 1; i <= Matrix<DataType>::size; ++i) {
        for(int j = 1; j <= Matrix<DataType>::size; ++j) {
            std::cout << std::setw(4) << (*this)(i, j);
        }
        std::cout << std::endl;
    }
}

template <class DataType>
class TriDiagonalMatrix : public Matrix<DataType> {                 // 三角矩阵
protected:
    int type;                                                       // 0下三角 1上三角
public:
    TriDiagonalMatrix(int size = DEFAULT_SIZE, int type = 1) : Matrix<DataType>(1, size), type(type){};
    DataType&   operator() (const int i, const int j) const;        // 返回[i, j]下标的元素
    void        Traverse() const;                                   // 遍历
};

template <class DataType>
DataType& TriDiagonalMatrix<DataType>::operator() (const int i, const int j) const {
    if(!((i <= j) ^ type)) {
        return Matrix<DataType>::data[(i - 1) * (2 * Matrix<DataType>::size - i + 2) / 2 + j - i + 1];
    } else {
        return Matrix<DataType>::data[0];
    }

}

template <class DataType>
void TriDiagonalMatrix<DataType>::Traverse () const {
    for(int i = 1; i <= Matrix<DataType>::size; ++i) {
        for(int j = 1; j <= Matrix<DataType>::size; ++j) {
            std::cout << std::setw(4) << (*this)(i, j);
        }
        std::cout << std::endl;
    }
}

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_MATRIX_H
