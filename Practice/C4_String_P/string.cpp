//
// Created by 喻如辰 on 2020/10/16.
// 串 utility of string.h
// call for KMPIndex();
//

#include <iostream>
#include <string>
#include "../../Header&Library/string.h"
using namespace std;

int main () {
    // 分别输入Pattern串、Target串
    String p, t;
    while(cin >> p >> t) {
        cout << "P: " << p << endl;
        cout << "T: " << t << endl;
        // 操作符+重载：
        cout << "P + T = " << p + t << ";" << endl;

        // 测试KMP查找
        int *next = new int[p.Length()];
        p.GetNext(next);
        int loc = p.KMPIndex(t.GetPtr(), t.Length(), next);

        cout << loc << endl;

        cout << t << endl;
        for(int i = 0; i < loc; ++i) {
            cout << ".";
        }
        cout << p << endl;
    }

    return 0;
}
