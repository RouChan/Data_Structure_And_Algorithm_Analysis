//
// Created by 喻如辰 on 2020/9/27.
// 已知两个链表`la`和`lb`，其元素值递增排序。编程将`la`和`lb`合并成一个递减有序（相同值元素只保留一个）的链表`lc`。
//

#include <iostream>
#include "../Header&Library/SinglyLinkedList.h"
using namespace std;

template <class DataType>
class MergeList : public List<DataType> {
public:
    friend void CombineList(List<DataType>& la, List<DataType>& lb, List<DataType>& lc);
};

template <class DataType>
void CombineList(List<DataType>& la, List<DataType>& lb, List<DataType>& lc){
    enum Status {empty = 0, left};
    Status laStatus = left, lbStatus = left;
    int laPos = 0, lbPos = 0;

    while (laStatus + lbStatus) {
        if(laPos == la.Length()) {
            laStatus = empty;
        }
        if(lbPos == lb.Length()) {
            lbStatus = empty;
        }

        if(laStatus == left && lbStatus == left) {
            DataType laTmp, lbTmp;

            la.GetNode(laPos + 1, laTmp);
            lb.GetNode(lbPos + 1, lbTmp);

            if(laTmp <= lbTmp) {
                lc.Insert(1, laTmp);
                laPos++;
                if(laTmp == lbTmp) lbPos++;
            } else {
                lc.Insert(1, lbTmp);
                lbPos++;
            }
        } else if (laStatus == left) {                  // la剩余，lb无
            while(laPos != la.Length()) {
                DataType laTmp;
                la.GetNode(laPos + 1, laTmp);
                lc.Insert(1, laTmp);
                laPos++;
            }
            laStatus = empty;
        } else if (lbStatus == left) {                  // lb剩余，la无
            while(lbPos != lb.Length()) {
                DataType lbTmp;
                lb.GetNode(lbPos + 1, lbTmp);
                lc.Insert(1, lbTmp);
                lbPos++;
            }
            lbStatus = empty;
        }
    }
}

int main () {
    List<int> la, lb, lc;

    for(int i = 0; i < 5; i++) {
        la.Insert(la.Length() + 1, i);
    }

    for(int i = 0; i < 8; i += 2) {
        lb.Insert(lb.Length() + 1, i + 1);
    }

    CombineList(la, lb, lc);

    lc.Traverse(1, lc.Length());

    return 0;
}