//
// Created by 喻如辰 on 2020/10/18.
// Ackerman函数的递归与非递归实现方式
//

#include <iostream>
using namespace std;

int AckermanRec(int m, int n) {
    cout << "m: " << m << ", n: " << n << endl;
    if(m == 0) {
        return (n + 1);
    } else if(n == 0) {
        return AckermanRec(m - 1, n);
    } else {
        return AckermanRec(m - 1, AckermanRec(m, n - 1));
    }
}
//todo: without recursion
//int Ackerman(int m, int n) {
//
//}

int main () {
    cout << AckermanRec(1, 1) << endl;
    return 0;
}