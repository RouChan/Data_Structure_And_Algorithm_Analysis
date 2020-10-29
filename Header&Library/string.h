//
// Created by 喻如辰 on 2020/10/16.
// 串_顺序表
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_STRING_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_STRING_H

#include "SinglyLinkedList.h"

// 判断a、b之前的count个字符是否相同（不包括a、b本身的比较）
bool Cmp(char *a, char *b, int count) {
    bool trueVal = true;
    for(char *aStart = a - count, *bStart = b - count; aStart != a; aStart++, bStart++) {
        if(*aStart != *bStart) {
            trueVal = false;
            break;
        }
    }
    return trueVal;
}

class String {
protected:
    char    *str;
    int     length;                                                         // 可以存放的字符数
public:
    String();                                                               // 无参构造函数
    String(const char *copy, int from, int to);                             // 使用字符串构造函数
    String(const String& copy);                                             // 复制构造函数
    virtual ~String();                                                      // 析构函数
    
    int     Length() const;                                                 // 求字符串长度
    bool    Empty() const;                                                  // 判断是否为空
    void    Traverse() const;                                               // 遍历
    void    GetNext(int *next) const;                                       // 求Next数组
    int     KMPIndex(char *T, int TLength, int *next) const;                // KMP查找
    char*   GetPtr() const;                                                 // 获取头指针


    String& operator= (const String& copy);                                 // =操作符重载
    String operator+(const String& oprand);                                 // +操作符重载，达到补全字符出

    friend std::ostream& operator<<(std::ostream& out, const String& s);    // 操作符<<重载
    friend std::istream& operator>>(std::istream& in, String& s);           // 操作符>>重载
};

String::String () {
    length = 0;
    str = nullptr;
}

String::String (const char *copy, int from, int to) {
    length = to - from + 1;
    str = new char[length + 1];
    for(int i = 0; i < length; i++) {
        str[i] = copy[i + from];
    }
    str[length] = 0;
}

String::String (const String& copy) {
    length = copy.length;
    str = new char[length + 1];
    for(int i = 0; i <= length; i++) {
        str[i] = copy.str[i];
    }
}

String::~String () {
    length = 0;
    delete []str;
    str = nullptr;
}

int String::Length () const {
    return length;
}

bool String::Empty () const {
    return (length == 0);
}

void String::Traverse () const {
    for(int i = 0; i < length && str[i] != 0; i++) {
        std::cout << str[i];
    }
    std::cout << std::endl;
}

void String::GetNext (int *next) const {
    for(int j = 0; j < length; j++) {
        if(j == 0) {
            next[j] = -1;
            continue;
        } else {
            int k = j - 1;
            while(k > 0) {
                if(Cmp(str + j, str + k, k)) {
                    break;
                }
                k--;
            }
            next[j] = k;
        }
    }
}

int String::KMPIndex (char *T, int TLength, int *next) const {
    for(int i = 0, j = 0; i <= TLength; ) {
        if(j == -1) {
            i++;
            j++;
        } else if (j == length) {
            return (i - length);
        } else if(T[i] == str[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    return -1;                                                                  // 未查找到
}

char* String::GetPtr () const {
    return str;
}

String& String::operator= (const String& copy) {
    if(&copy != this) {
        delete []str;
        str = nullptr;
        length = copy.length;
        str = new char[length + 1];
        for(int i = 0; i <= length; i++) {
            str[i] = copy.str[i];
        }
    }
    return *this;
}

String String::operator+ (const String& oprand) {
    String sum;
    sum.length = this -> length + oprand.length;
    sum.str = new char[sum.length + 1];
    sum.str[sum.length] = 0;

    for(int i = 0; i < (this -> length); ++i) {
        sum.str[i] = this -> str[i];
    }
    for(int i = 0; i < sum.length; ++i) {
        sum.str[length + i] = oprand.str[i];
    }

    return sum;
}

std::ostream& operator<< (std::ostream& out, const String& s) {
    for(int i = 0; i < s.length && s.str[i] != 0; i++) {
        out << s.str[i];
    }
    return out;
}

std::istream& operator>>(std::istream& in, String& s) {
    List<char> tmp;
    while(in.peek() != '\n' && in.peek() != EOF) {
        tmp.Insert(tmp.Length() + 1, in.get());
    }
    in.get();

    s.length = tmp.Length();
    if(s.str != nullptr) delete []s.str;
    s.str = new char[s.length + 1];

    for(int i = 0; i < s.length; ++i) {
        tmp.GetNode(i + 1, s.str[i]);
    }
    s.str[s.length] = 0;
    return in;
}

#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_STRING_H
