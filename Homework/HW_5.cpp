//
// Created by 喻如辰 on 2020/11/3.
// 若在矩阵An×n中存在一个元素ai-1,j-1满足ai-1,j-1是第i行元素中最小值且又是第j列元素中的最大值，则称此元素为该矩阵的一个马鞍点。假设以二维数组存储矩阵An×n，试设计一个求该矩阵所有马鞍点的算法。
//

#include <iostream>
#include "../Header&Library/clk_tri_node.h"
using namespace std;

#define SIZE 5

int main () {
    int matrix[SIZE][SIZE] ={{0, 0, 0, 0, 0,},
                            {0, 0, 2, 6, 7,},
                            {0, 0, 2, 9, 1,},
                            {0, 1, 2, 3, 1,},
                            {0, 0, 4, 5, 7}};               // 4*4 Matrix

    int *rowMin = new int[SIZE];
    for(int i = 1; i < SIZE; ++i) {
        int min = matrix[i][1];
        for(int j = 2; j < SIZE; j++) {
            min = matrix[i][j] < min ? matrix[i][j] : min;
        }
        rowMin[i] = min;
    }

    for(int j = 1; j < SIZE; ++j) {
        int max = matrix[1][j];
        for(int i = 2; i < SIZE; ++i) {
            max = matrix[i][j] > max ? matrix[i][j] : max;
        }
        for(int i = 1; i < SIZE; ++i) {
            if(matrix[i][j] == rowMin[i] && matrix[i][j] == max) cout << "(" << i << ", " << j << ") = " << max << ";\n";
        }
    }

    return 0;
}