**note of Advanced C Programming by Weng_Kai**

# 指针与字符串
## 指针的使用
-   借助指针完成函数对多个变量的修改；
-   函数返回运算的状态（利用返回特殊的不属于有效范围内的值来表示出错，例如`-1`、`0`）；
-   地址变量声明时，只是申请了一块**用于存储地址的内存，并未申请存储数据的内存**，切记初始化指向的内存块；
    ```C++
    int* a = 10;                    // ERROR
    int* b[] = {1, 2, 3, 4};        // ERROR
    ```
-   函数参数表的数组实际上是一个指针，数组变量是特殊的指针；
    ```C++
    int a[10];
    int* p = a;     // 无需&取地址；
    p[0] == a[0];
    a == &a[0];     // 数组的单元是一个变量；
    ```
-   数组变量是`const`指针，不能被赋值，或用一个数组初始化一个数组变量；
-   指针与`const`
    -   指针是`const`，表示某个指针一旦的到了某个变量的地址，不能再指向其他变量；
        ```c++
        int* p const = &i;      // q是const;
        q++;                    // ERROR
        ```
    -   指针所指的内容是`const`，指不能通过这个指针取修改那个变量（并不能使指向变量是`const`）
        ```c++
        const int* p = &i;
        *p = 26;            // ERROR
        i = 26;             // OK
        p = &j;             // OK
        ```
    -   判断哪个被`const`的标志是`const`在`*`前面还是后面；
        ```c++
        const int a[] = {1, 2, 3};  // 数组每个单元都是const int
        ```
-   **在函数中修改指针**，需使用`*& pointer`或`**pointer`传入参数；    
## 指针运算
-   指针增减
    ```c++
    // Assume a pointer, Type* p;
    p + (int)n == p + n * sizeof(Type); 
    ```
-   指针之间的增减
    ```c++
        // Assume pointer, Type* p and Type* p1;
        p1 - p == (p1 - p) / sizeof(Type);
    ```
-   `*p++`
    -   *运算级高于++；
    -   该指令表示取出`p`所指的数据后，将`p`移至下一个位置；
        ```c++
        // another way to traverse an array;
        // assume an array, namely int a[] = {1, 2, 3};
        for(int* p = a; *p = 3; ) {             // 3 indicates the last element.
            std::cout << *p++ << std::endl; 
        } 
        ```
-   指针比较，`<` `<=` `>` `>=` `!=`，用于比较在内存中的地址大小；
    >数组中的单元地址是线性递增的。
-   `0`地址
-   指针的类型
    -   所有的指针大小都是一样的，因为都是一个`32`位的地址（`sizeof`是另一回事）；
    -   指向不同类型的指针不能直接赋值（为了避免用错指针）；
    -   当然指针可以强制转换类型；