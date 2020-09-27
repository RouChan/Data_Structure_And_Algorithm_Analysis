//
// Created by 喻如辰 on 2020/9/27.
// 作业1，实现将输入的三个整数x，y，z按从小到大的顺序排列起来。
//

#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int const& a, int const& b) {
    if(a < b)   return true;
    else        return false;
}

class Sort {
protected:
    int* array;
public:
    Sort();
    ~Sort() {delete [] array;};

    void Init();
    void Set(int x[3]);
    void Traverse();
    void Order() {
        sort(array, array + 3, cmp);
    }
};

Sort::Sort() {
    array = nullptr;
    Init();
}

void Sort::Init() {
    if(array != nullptr) {
        delete []array;
        array = nullptr;
    }

    array = new int[3];
}

void Sort::Set(int *x) {
    array[0] = x[0];
    array[1] = x[1];
    array[2] = x[2];
}

void Sort::Traverse() {
    for(int i = 0; i < 3; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main () {
    Sort C1;

    int x[] = {99, 29, 93};

    C1.Set(x);
    C1.Order();
    C1.Traverse();

    return 0;
}