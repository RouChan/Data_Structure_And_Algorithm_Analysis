//
// Created by 喻如辰 on 2020/11/19.
//

#ifndef DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_TEXT_EDITOR_H
#define DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_TEXT_EDITOR_H

#include "../../Header&Library/string.h"
#include "../../Header&Library/SinglyLinkedList.h"

class File: public List<String> {
public:
    void    Traverse() const;                                               // 遍历
    void    LoadFromFile(std::fstream& file);                               // 从文件加载
};

void File::LoadFromFile (std::fstream& file)  {
    Clear();

    while(1) {
        String      tmpString;
        List<char>  tmp;

        while(file.peek() != -1 && file.peek() != '\n') {
            tmp.Insert(tmp.Length() + 1, file.get());
        }
        tmpString.length = tmp.Length();
        tmpString.str = new char[tmpString.length + 1];

        for(int i = 0; i < tmpString.length; ++i) {
            tmp.GetNode(i + 1, tmpString.str[i]);
        }
        tmpString.str[tmpString.length] = 0;

        Insert(Length() + 1, tmpString);

        if(file.peek() == -1)   break;
        else                    file.get();
    }
}

void File::Traverse() const {
    for(int i = 1; i <= Length(); i++) {
        String tmp;
        GetNode(i, tmp);
        std::cout << tmp << std::endl;
    }
}
#endif //DATA_STRUCTURE_AND_ALGORITHM_ANALYSIS_TEXT_EDITOR_H
