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