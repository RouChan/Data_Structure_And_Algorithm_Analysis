-   操作符的`<<`重载
    -   声明为友元函数
        ```C++
        friend std::ostream& operator<<(std::ostream& out, const StructType& s) {
            out << PARAMETERS;
            return out;
        }
        ```
    -   参数
    -   调用，直接使用`std::cout`
        ```c++
        std::cout << (StructType) s << endl;
        ```
-   操作符`>>`重载
    -   声明为友元函数
        ```c++
        friend std::ostream& operator>>(std::istream& in, DataType& s) {
            // operations on s
            return in;
        }
        ```
-   操作符`+`重载
    -   返回类型非引用，非友元
        ```c++
        ClassType ClassType::operator+ (const ClassType& c1) {
            ClassType sum;
            return sum;
        }
        ```
-   子类析构函数被调用后，**自动调用父类析构函数**