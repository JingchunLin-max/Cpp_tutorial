#include<iostream>
#include<string>

using namespace std;

/*
    C++对象模型和this指针
    1. 成员变量和成员函数分开存储
        空对象占用内存空间为：1
        C++编译器会给每一个空对象也分配一个字节空间， 是为了区分空对象占内存的位置
        每个空对象也应该有一个独一无二的内存地址。
        静态成员变量不属于类的对象上
        静态和非静态成员函数也不属于类的对象上

    2. THIS指针
        a. 解决名称冲突: this指针指向对象的指针 被调用的成员函数 所属的对象
        b. 返回对象本身用 *this指向的是对象本身//链式编程思想
    
    3. 空指针访问成员函数
    4. const 修饰成员函数
        a. 常函数不能修改成员变量的值
        b. this指针的本质 是指针常量，就是指针的指向是不可以修改的；
        c. 常对象：const Object 不允许修改普通的成员变量； 常对象只能调用常函数      

    5. 友元函数
        a. 一种特殊的属性，有些私有属性，也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术
        b. 全局函数做友元
        c. 类外写成员函数   
*/

class Object
{
    friend void Goody(const Object& obj);
    friend class InnerMember;
public:
    Object(const int a, const string str):m_age(a), m_name(str){}
    void showObject(const int& age) const
    {
        m_age = age;
        cout << m_age << endl;
    }
    void showObject() const
    {
        cout << m_age << endl;
    }

    mutable int m_age;

private:
    string m_name;
};

class InnerMember
{
public:
    void visit(const Object& obj);
};

void InnerMember::visit(const Object& obj)
{
    cout << "private args:" << obj.m_name;
}

void Goody(const Object& obj)
{
    cout << "real name:" << obj.m_name << endl;
}

int main()
{
    string str = "lyan.lin";
    Object objA(10, str);
    int a = 7;

    objA.showObject();
    objA.showObject(a);
    Goody(objA);

    return 0;
}