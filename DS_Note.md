Chapter 2-Linear List
========

1. 对于顺序表的初始化，可将声明和定义分离，避免野指针无法判断问题；
2. 链表头的节点中，数据域可以存储关于链表的信息，例如节点数量等；
3. 返回值为地址时，若查找失败，则可返回`NULL`，并在主函数调用时，**判断是否调用成功。**
4. 清空链表`Clear()` -> 从第一个结点开始逐一删除；
5. 编写`enum StatusCode`作为函数操作状态码。
    ```C++
    enum StatusCode {SUCCESS, FAIL, UNDER_FLOW, OVER_FLOW,RANGE_ERROR, DUPLICATE_ERROR,
	NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED};
    ```
6. **查找运算：**顺序表可以按照序号随机访问读取，单链表需要逐一移动，若查找失败，则返回`nullptr`；
7. **单链表插入运算：**若需要将新结点插入到表的第i个结点上，需要定位到位置为`(a-1)`的节点pos；
8. **单链表删除结点：**需要用一个tmp指针记录被删除结点的地址，便于前后结点结合之后的删除；
9. 顺序表**存储密度**大于线性表，若能确定线性表的大小，为了节约空间，宜用顺序表作为其存储结构；顺序表查找等**时间复杂**度也更低（可随机访问）；若频繁进行插入与删除操作，则宜采用链表作为存储结构；若表的插入和删除主要发生在表的首尾两端，可以给链表添加`rear`尾指针；
---

Chapter 3-Stack and Queue
========
-   **顺序栈的数据成员**
    -   `count` `maxSize` `array`
-   **链式栈的数据成员**
    -   `top` 栈顶指针
## Stack
-   插入删除端为栈顶`Top`，另一端为栈底`Bottom`；
-   栈`a1`为栈底元素，`an`为栈顶元素；
-   **顺序栈**：利用一组连续地址的存储单元依次存放从栈底到栈顶的数据元素；
-   链式栈结点的`next`由`Top`指向`Bottom`；
-   栈的链式实现一般不使用头结点，即`a1`直接为栈底元素；
## Queue
-   **队列**：是只允许在一端插入，在另一端删除的线性表；
-   `a1`是队头结点，`an`是队尾结点。使用链表实现时，分别设置`头指针`和`尾指针`；
    ```c++
    front -> next = &a1;
    rear == &an;
    
    (front == rear) == (queue.Empty() == true); 
    ```
-   **链式队列**结点的`next`由`Front`指向`Rear`；
-   **循环队列**
    -   在入队、出队的操作中，可能造成顺序表的后部分溢出，但前半部分的顺序表为空，造成假溢现象，此时可以采用虚幻队列的方式进行解决；
    -   注意区分`front == rear`时空栈或满栈的判断；
---

# Summary
-   结构体`struct`操作符的`<<`重载
    -   在结构体内声明为友元函数
        ```C++
        friend ostream& operator<<(ostream& out, StructType const s) {
            out << PARAMETERS;
            return out;
        }
        ```
    -   参数
    -   调用，直接使用`std::cout`
        ```c++
        std::cout << (StructType) s << endl;
        ```
-   **函数指针`(*visit)`**