//
// Created by 喻如辰 on 2020/10/16.
// 串 utility of string.h
//

#include <iostream>
#include "../Header&Library/string.h"
using namespace std;

int main () {
//    char a[] = "Hello";
    String s;

    cin >> s;
    cout << s << endl;

    int *Next = new int[s.Length()];
    s.GetNext(Next);
    for(int i = 0; i < s.Length(); i++) {
        cout << Next[i];
    }
    cout << endl;
//    cout << s << endl;

    return 0;
}
