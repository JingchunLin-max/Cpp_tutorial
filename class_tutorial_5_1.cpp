#include <iostream>

//模板的使用方式
//1. 模板自动推导
//2. 显示指定类型

//模板必须要确定出T的数据类型，才可以使用

/*
    普通函数与函数模板的区别
    1. 普通函数调用可以发生隐式类型转换
    2. 函数模板 用自动类型推导，不可以发生隐式类型转换
    3. 函数模板 用显示指定类型， 可以发生隐式类型转换
*/

/*
    普通函数与函数模板的调用规则
    1. 如果函数模板和普通函数都可以调用，优先调用普通函数
    2. 可以通过空模板参数列表 强制调用 函数模板
    3. 函数模板可以发生函数重载 
    4. 如果函数模板可以产生更好的匹配，优先调用函数模板（这是在发生隐式类型转换的时候）。

    总结：
        如果写了函数模板就不要写相同的普通函数了
*/
class Object
{
public:
    int a;
    int b;
};

template<class T>
bool compare(T &a, T &b)
{
    if (a == b) {return true;}
    return false;    
}

template<> bool compare(Object &a, Object &b)
{
    if (a.a = b.a && a.b == b.b) {return false;}
    return true;
}

/*
    利用具体化的模板，可以解决自定义类型的通用化
    STL能够有运用系统提供的模板
*/

int main()
{

    return 0;
}
