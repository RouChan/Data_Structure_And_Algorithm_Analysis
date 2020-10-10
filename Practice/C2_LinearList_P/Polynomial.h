//
// Created by 喻如辰 on 2020/10/10.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_POLYNOMIAL_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_POLYNOMIAL_H

#include "/Users/yu_ruchen/Library/Mobile Documents/com~apple~CloudDocs/Programming/Data_Structure_And_Algorithm_Analysis/Header&Library/SinglyLinkedList.h"

struct PolyItem {
    double  coef;                                                           // 系数
    int     expo;                                                           // 指数

    PolyItem();
    PolyItem(double coef, int expo);

    friend std::ostream& operator<<(std::ostream& out, PolyItem const s);   // 操作符<<重载
};

std::ostream& operator<<(std::ostream& out, PolyItem const s) {
    out << s.coef << "x^" << "{" << s.expo <<  "}" << std::endl;
    return out;
}

PolyItem::PolyItem() {
    expo = -1;
}

PolyItem::PolyItem(double coef, int expo) {
    this -> coef = coef;
    this -> expo = expo;
}

template <class DataType>
class Polynomial : public List<DataType> {
public:
    Polynomial();
};


#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_POLYNOMIAL_H
