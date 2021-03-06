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
-   **(循环)顺序队列的数据成员**
    -   `(int)front`队头 `(int)rear`队尾 `maxSize` `array`
-   **链式队列的数据成员**
    -   `front`队头指针 `rear`队尾指针
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

Chapter 4-String
===========
-   **顺序串数据成员**
    -   `str`（存储串的头指针） `length`


-   块链存储表示
    -   串的数据元素是一个字符，因此使用链式存储结构保存串时，每个结点的指针域所占空间大于字符作占的空间，因此空间利用效率较低，引入块链存储表示；
    -   **块链存储**，每个结点存放若干个字符，减少链表中的结点数量，增大空间利用效率；
-   存储密度；
---

Chapter 5-Array and Generalized Table
=========
-   **对称矩阵、三角矩阵数据成员**
    -   `Elemt*` `n`(矩阵行数)
-   **十字链表数据成员**
    -   `row` `col` `num`(非零元素个数) `**rightHead` `**downHead`
-   **十字链表结点数据成员**
    -   `row` `col` `value`(使用三元组代替) `**rightHead` `**downHead`


## Array&Matrix
-   高维数组在内存中的存储顺序（一段连续的、一维的内存空间）：
    ```c++
    // 行优先顺序存储类型
    a[0][0][0] ... a[0][0][n - 1] ... a[0][m - 1][n - 1] ... a[p - 1][m - 1][n - 1];
    ```
-   **矩阵 Matrix**可以描述为二维数组，**下标通常从`1`开始**，常用`a(i,j)`引用矩阵中第`i`行第`j`列的元素；
-   特殊矩阵
    -   值相同的元素或零元素在矩阵中按一定的规律分布；
    -   可以用特殊的方法进行存储和处理，以便提高空间和时间效率；
    -   包括对称矩阵、三角矩阵、对角矩阵；
    -   保持行优先的存储顺序；
    -   单独开辟一个一维数组保存特殊矩阵的非零非规律部分映射；
-   对称矩阵
    -   方阵、`a(i,j) = a(j,i)`；
    -   只需要存储上三角或下三角的元素，且对称元素共享同一个存储空间，能节约一半的存储空间；
-   三角矩阵
    -   以主对角线划分，矩阵上三角矩阵（下三角均为常数）、下三角矩阵（上三角均为常数）；
    -   只需要存储上三角或下三角的元素和对应三角存储的常数；
-   对角矩阵
    -   除了主对角线和主对角线相邻两侧的若干条对角线伤的元素外，其余元素皆为零；
-   **稀疏矩阵：** 矩阵中非零元素个数远小于矩阵元素的总个数；
    -   稀疏因子`e=s/(m*n)`，`e<0.05`为稀疏矩阵，采用压缩存储方法节约存储空间；
    -   **三元组顺序表压缩方式**：以顺序存储结构来表示三元组表；
        ```c++
        struct Triple {
            int row, col, value;
        };
        
        class Matrix {
            Triple *element;
        };
        ```
        -   一个三元组`(i,j,a(i,j))`唯一确定了矩阵`A`的一个非零元，因此稀疏矩阵可由表示非零元的三元组及其行列数唯一确定；
        -   使用二维数组存储三元组数据`(row, column, value)`；
    -   矩阵转置算法见`Algorithm_Note.md`
-   十字链表
    -   引入原因：稀疏矩阵经过运算后，零元素位置/个数发生较大变化，三元组不易变化；
    -   矩阵的每个非零元素使用一个结点表示，结点包括`row` `col` `value` `right` `down`（表示同一行/同一列下一个非零元素）；
    -   可以用两个一维数组分别存储行链表/列链表的头结点；
## Generalized List
-   广义表`GL={a1, a2, ..., an}`是线性表的推广，不限表元素的原子性，每个元素自身容许有自身的结构，即`an`可以是一个子表（循环定义）；
-   元素大写表示广义表，小写表示原子。例如`E={a, E}`表示一个递归的表；
-   n>0，广义表第一个元素被称为表头`Head(GL)`，**其他所有的表元素组成的表称为表尾`Tail(GL)`**，因此表头可以是原子/广义表，表尾一定是广义表；
-   深度`Depth(GL)`
    -   广义表表达式中括号的最大嵌套数；
    -   空表的深度为`1`；
-   存储结构（引用数法广义表）
    -   头结点（`tag=HEAD, ref 引用数, nextLink`）；
    -   表结点，表示链表（`tag=ATOM, atom, nextLink`）；
    -   原子结点，表示原子（`tag=LIST, subLink, nextLink`）；
    -   三类结点可以用一个结构体表示；
        ```c++
        union {
                int                     ref;                        // designed for HEAD.  头结点->引用次数
                DataType                value;                      // designed for ATOM.  原子结点->数据
                GenListNode<DataType>   *subLink;                   // designed for LIST   表结点->子表
            };
        ``` 
    -   每个结点包括三个域：标志域`(enum)`、数据域`(union)`，指针域`(pointer)`；
    -   头结点的数据域（`ref` 引用数）可以用来记录该表是否被继续使用，进而对该结点安全的删除；
---
    
Chapter 6-Tree and Binary Tree
===========
-   **二叉树链式存储结构结点数据成员**
    -   `leftChid` `rightChild` `parent` `value`
-   使用二叉链表存储树时，结点遵循"左孩子右兄弟"规则；
-   树型结构是一类重要的非线性结构，结点之间有分支，且具有层次结构；
-   树是n>0个结点的有限集合T
    -   有且只有一个特定的结点称为`root`，只有直接后继，无直接前驱（最上面的结点），`root`处于`Level1`；
    -   当n>1时，...；
## **6.2 二叉树**
-   二叉树需要区分左子树、右子树（有序树）；
-   **二叉树性质**
    -   任何一个二叉树，若有`n0`个叶子结点，`n2`个度为2的结点，则必存在关系`n0=n2+1`；
    -   具有`n`个结点的完全二叉树的深度为`[log(2, n)] + 1`；
    -   在完全二叉树中，对于一个编号为`i`的结点
        -   若`i=1`则为根结点；若`i>1`，则`[i/2]`为其双亲结点；
        -   若`2i>n`，则结点`i`没有左孩子，否则`2i`为左孩子；
        -   若`2i+1>n`，则结点`i`没有右孩子，否则结点`2i+1`为右孩子；
-   **遍历**
    > 访问根结点记作D，遍历根的左子树记作L，遍历根的右子树记作R；
    -   遍历顺序
        -   前序遍历（DLR/Preorder Traversal）；
        -   中序遍历（LDR/Inorder Traversal）；
        -   后序遍历（LRD/Postorder Traversal）；
        -   层次遍历（Levelorder Traversal）：按照二叉树的层次，从上到下、从左到右的次序访问结点；
    -   递归算法；
    -   非递归算法：效率更高、使用栈；
## 6.4 线索二叉树
-   **线索二叉树结点数据成员**
    -   `leftChild` `leftTag` `data` `rightChild` `rightTag`
-   利用空闲的链域存放遍历过程中的前驱和后继信息；
    -   若结点左子树**不为空**，则`leftChild`指向左子树，`leftTag`标记为0；
    -   若结点左子树为空，则`leftChild`指向前驱，`leftTag`标记为1；
## 6.5 **哈夫曼树与哈夫曼编码**
-   哈夫曼树/最优二叉树，指一类带权路径长度最短的树；
    -   路径：指从一个结点（根）到某结点的路径；
-   