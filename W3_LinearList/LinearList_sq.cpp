//
// Created by 喻如辰 on 2020/9/17.
// 第一章-线性表（顺序结构实现）
//

#include <iostream>
#include <string>

#define DEFAULT_SIZE 10
using namespace std;

struct Student {
    string name;
    int age;
};

class SqList{
protected:
    int count;
    int maxSize;
    Student* stu = NULL;
public:
    SqList(int size = DEFAULT_SIZE);
    ~SqList() {delete[] stu;};
    void AddStu(string name, int age);              // 在末尾添加元素
    void SetStu(int loc, string name, int age);     // 修改特定位置元素

    void GetStu(int loc);                           // 取元素信息
    void Traversal();                               // 遍历
};

SqList::SqList(int size) {
    maxSize = size;
    stu = new Student[size];
    count = 0;
}

void SqList::Traversal() {
    for(int i = 0; i < count; ++i) {
        GetStu(i);
    }
    cout << endl;
}

void SqList::AddStu(string name, int age)  {
    if(count >= maxSize) {
        cerr << "超过最大容量限制!" << endl;
        exit(1);
    } else {
        stu[count].name = name;
        stu[count].age = age;
        count++;
        return;
    }
}


void SqList::SetStu(int loc, string name, int age) {
    stu[loc].name = name;
    stu[loc].age = age;
    return ;
}

void SqList::GetStu(int i) {
    cout << stu[i].name << " " << stu[i].age << endl;
}

int main () {
    SqList CS_1(5);
    CS_1.AddStu("Liu_Da", 19);
    CS_1.AddStu("Wang", 18);

    CS_1.Traversal();

    return 0;
}