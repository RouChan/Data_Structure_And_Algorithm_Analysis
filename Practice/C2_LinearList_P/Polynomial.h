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
    if(s.coef >= 0) {
        out << s.coef << " * x^" << "{" << s.expo <<  "}" << " ";
    } else if(s.coef < 0) {
        out << "(" << s.coef << ")" << " * x^" << "{" << s.expo <<  "}" << " ";
    }
    return out;
}

PolyItem::PolyItem() {
    expo = -1;
}

PolyItem::PolyItem(double coef, int expo) {
    this -> coef = coef;
    this -> expo = expo;
}

class Polynomial : public List<PolyItem> {
public:
    Polynomial() {};                                        // 无参构造函数
    ~Polynomial() {};                                       // 析构函数

    bool IsZero() const;                                    // 判断多项式是否为0
    void SetZero();                                         // 将多项式设置为0
    int  GetCurPos(const int& expo) const;                  // 寻找expo为指数的项应该插入的位置，返回指数小于等于expo的最大指数项位置编号
    void Plus(const PolyItem& it);                          // 有序添加项（从小到大排列）

    void Traverse(int from, int to) const;                  // 遍历

    Polynomial operator + (const Polynomial& p) const;      // +重载
};

int Polynomial::GetCurPos(const int& ex) const {
    if(IsZero()) {
        return 0;
    } else {
        for(int i = 1; i <= Length(); i++) {
            PolyItem tmp;
            GetNode(i, tmp);
            if(tmp.expo > ex) {
                return (i - 1);
            }
        }
        return Length();
    }
}

bool Polynomial::IsZero() const {
    return Empty();
}

void Polynomial::SetZero() {
    Clear();
}

void Polynomial::Plus(const PolyItem &it) {
    int expoPlus = it.expo;
    int pos = GetCurPos(expoPlus);

    PolyItem tmp;
    GetNode(pos, tmp);
    if(tmp.expo == it.expo) {
        tmp.coef += it.coef;
        SetNode(pos, tmp);
        tmp.coef += it.coef;
    } else {

        Insert(pos + 1, it);
    }
}

void Polynomial::Traverse(int from, int to) const {
    PolyItem tmp;

    for(int i = from; i < to; i++) {
        GetNode(i, tmp);
        std::cout << tmp << " + ";
    }
    GetNode(to, tmp);
    std::cout << tmp << std::endl;
}

Polynomial Polynomial::operator + (const Polynomial& p) const {

}

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_POLYNOMIAL_H
