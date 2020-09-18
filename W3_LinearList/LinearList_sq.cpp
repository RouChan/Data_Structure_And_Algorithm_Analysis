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
    int count;                                      // 当前元素个数&最后一个元素后一个数组位置编号
    int maxSize;                                    // 初始化预留的最大顺序表元素个数
    Student* stu;
public:
    SqList(int size = DEFAULT_SIZE);                // 声明和定义分离，避免野指针
    void Init(int size);                            // 设置顺序表元素内容
    ~SqList() {delete[] stu;};                      // 析构函数

    void Clear();                                   // 清空顺序表
    void AddStu(string name, int age);              // 在末尾添加元素
    void SetStu(int loc, string name, int age);     // 修改特定位置元素

    int Length() {return count;};                   // 返回顺序表元素个数
    bool IsEmpty() {return count;};                 // 判断顺序表是否为空

    void GetStu(int loc);                           // 取元素信息
    void Traverse();                                // 遍历
};

SqList::SqList(int size) {
    stu = nullptr;
    Init(size);
}

void SqList::Init(int size) {
    maxSize = size;
    if(stu != nullptr) delete[] stu;
    stu = new Student[size];
    count = 0;
}

void SqList::Clear() {
    count = 0;
    maxSize = 0;
    if(stu != nullptr) {
        delete[] stu;
        stu = nullptr;
    }
}

void SqList::Traverse() {
    for(int i = 0; i < count; ++i) {
        GetStu(i);
    }
    cout << endl;
}

void SqList::AddStu(string name, int age)  {
    if(count >= maxSize) {
        cerr << "插入失败，超过最大容量限制!" << endl;
//        exit(1);
        return ;
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
    CS_1.AddStu("Wang", 20);

    CS_1.Traverse();

    return 0;
}