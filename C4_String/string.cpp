//
// Created by 喻如辰 on 2020/10/16.
// 串 utility of string.h
// call for KMPIndex();
//

#include <iostream>
#include <string>
#include "../Header&Library/string.h"
using namespace std;

int main () {

    String p, t;
    while(cin >> p >> t) {
        cout << p << endl;
        cout << t << endl;

        int *next = new int[p.Length()];
        p.GetNext(next);

        cout << p.KMPIndex(t.GetPtr(), t.Length(), next) << endl;
    }

    return 0;
}
