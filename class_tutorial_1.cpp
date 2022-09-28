/*
    author: lyan.lin
    date: 2022.9.17
*/

#include<iostream>

using namespace std;

/* 
    构造函数的调用规则
    1. 创建一个类，c++编译器会给每一个类加上三个默认构造函数：
      无参，函数体为空； 默认析构函数，函数体为空；默认拷贝构造函数，对属性进行值拷贝
    2. 如果提供了有参构造函数，编译器就不默认提供，无参构造函数了
    3. 如果author提供了拷贝构造函数，编译器就不默认提供其他构造函数了
 */

/*
    深拷贝与浅拷贝*/
/*
    浅拷贝带来的问题就是内存重复释放 -> 自己实现拷贝构造桉树，解决此问题 
*/

/*
    静态成员
    1. 静态成员变量
        所有对象共享同一份数据
        编译阶段就分配内存
        类内声明，类外初始化操作 
        Note: 静态成员变量有两种访问方式：1. 通过类成员进行访问；2. 通过类名进行访问

    2. 静态成员函数
        所有对象共享同一个函数
        静态成员函数只能访问静态的成员变量
        Note:通过对象访问； 通过类名访问（类外访问不到private 静态成员函数）
*/


class Object
{
public:
    //Constructor
    Object() 
    {
        age = 0;
        cout << "non-args constructor" << endl;
    }
    Object(const int &a)
    {
        age = a;
        cout << "constructor with args" << endl;
    }
    Object(const Object &obj)
    {
        age = obj.age;
        cout << "copier constructor" << endl;
    }

    ~Object(){
        cout << "destructor" << endl;
        if (height != nullptr)
        {
            delete height;
            height = nullptr;
        }
    }
    int age;
    int* height;

};

void test(){
    //1.括号法
    Object obj_a; //默认构造函数调用
    Object obj_b(10);
    Object obj_c(obj_b);

    //2.显示法
    Object obj_d;
    Object obj_e = Object(1);
    Object obj_f = Object(obj_e);

    //注意事项：不要利用拷贝构造函数 初始化匿名对象。编译器会认为 Object (obj_e) == Object obj_e

    //3.隐式转换法
    Object obj_g = 1;
    Object obj_h = obj_g;
    
}

int main(){
    test();
    return 0;
}