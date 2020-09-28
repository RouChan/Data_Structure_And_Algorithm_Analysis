//
// Created by 喻如辰 on 2020/9/17.
// 第一章-线性表（顺序结构实现）
//

#include <iostream>
#include <string>
#include "../Header&Library/SeqList.h"
using namespace std;

int main () {
    SeqList<int> stuAge(5);

    for(int i = 0; i < 3; i++) {
        stuAge.Insert(stuAge.Length() + 1, i);
    }

    stuAge.Traverse();

    return 0;
}