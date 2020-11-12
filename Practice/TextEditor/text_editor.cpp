//
// Created by 喻如辰 on 2020/11/12.
// 文件编辑器
//

#include <iostream>
#include "../../Header&Library/string.h"
#include <fstream>
using namespace std;

int main () {
    //todo: complete
    char ptr[] = "text12.txt";

    FILE *fPointer = fopen(ptr, "w+");
    fclose(fPointer);
    return 0;
}