//
// Created by 喻如辰 on 2020/11/12.
// 文件编辑器
//

#include <iostream>
#include "text_editor.h"
#include <fstream>
using namespace std;

int main () {
    // 打开要编辑的原文件，名字为patternfile.txt
    fstream iFile;
    iFile.open("patternfile.txt", ios::in);

    File patternFile;
    if(iFile.is_open()) {
        patternFile.LoadFromFile(iFile);
    } else {
        cerr << "Open Failed!" << endl;
    }

    cout << "请输入操作命令以换行符结束，0遍历 1添加行 2删除行 3输出某一行 4保存编辑结果并退出" << endl;
    char order;

    while(cin >> order) {
        switch (order) {
            case '0': {
                patternFile.Traverse();
                break;
            }
            case '1': {
                cout << "输入数字n，表示在第n行前添加行" << endl;
                int n;
                cin >> n;
                cout << "输入要添加行的内容" << endl;
                String tmp;
                cin.ignore();
                cin >> tmp;
                patternFile.Insert(n, tmp);
                break;
            }
            case '2': {
                cout << "输入数字n，表示删除第n行" << endl;
                int n;
                cin >> n;
                String tmp;
                patternFile.Delete(n, tmp);
                break;
            }
            case '3': {
                cout << "输入数字n，表示输出第n行" << endl;
                int n;
                cin >> n;
                String tmp;
                patternFile.GetNode(n, tmp);
                cout << "第n行内容为：" << tmp << endl;
                break;
            }
            case '4': {
                ofstream oFile;
                oFile.open("targetfile.txt", ios::out);
                if (oFile.is_open()) {
                    for (int i = 1; i <= patternFile.Length(); ++i) {
                        String tmp;
                        patternFile.GetNode(i, tmp);
                        oFile << tmp << endl;
                    }
                }
                iFile.close();
                oFile.close();
                break;
            }

        }
    }

    return 0;
}