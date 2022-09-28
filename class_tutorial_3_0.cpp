#include<iostream>

using namespace std;
/*
    运算符重载操作
    1. 成员函数重载 + 号 本质： Object p = p1.operator(p2)
    2. 通过全局函数重载 + 号 本质 Object p = operator(p1, p2)
    3. 左移运算符重载
        a. 一般不运用成员函数来重载左移运算符，只能运用全局函数来左移运算符。
    4. 递增运算符重载
    5. 赋值运算符重载
        a.
*/

class Object
{
public:
    Object(){};
    Object(int a, int b):m_A(a), m_B(b){}
    // Object operator+(const Object& obj_b)
    // {
    //     Object temp;
    //     temp.m_A = this->m_A + obj_b.m_A;
    //     temp.m_B = this->m_B + obj_b.m_B;

    //     return temp;
    // }

    //后置运算符重载， 占位参数int用来区分前置和后置递增
    Object operator++(int)
    {
        Object temp(*this);
        this->m_A = this->m_A + 1 ;
        this->m_B = this->m_B + 1;

        return temp;
    }
     Object& operator++()
    {
        this->m_A = this->m_A + 1 ;
        this->m_B = this->m_B + 1;

        return *this;
    }
    int m_A;
    int m_B;
    ~Object(){        
        // cout << "destructor successufully:" << m_A << endl;
    }
};

Object operator+(const Object &obj_a, const Object &obj_b)
{
    Object temp;
    temp.m_A = obj_a.m_A + obj_b.m_A;
    temp.m_B = obj_a.m_B + obj_b.m_B;

    return temp;
}

Object operator+(const Object &obj_a, const int num)
{
    Object temp;
    temp.m_A = obj_a.m_A + num;
    temp.m_B = obj_a.m_B + num;

    return temp;
}

ostream & operator<<(ostream &cout, const Object &obj)
{
    cout << obj.m_A << endl;
    cout << obj.m_B << endl;

    return cout;
}

void test_a()
{
    Object obj_a(1, 2);
    // Object obj_b(2, 3);
    // Object obj_c;
    // obj_c = obj_a + obj_b;
    // cout << obj_c.m_A << endl;
    // cout << obj_c.m_B << endl;
    cout << (obj_a++)++ << endl;
    cout << obj_a << endl;
    cout << ++(++obj_a) << endl;
    int i = 2;
    // if (obj_c != nullptr)
    // {
    //     delete(obj_c);
    //     cout << "release successfully" << endl;
    // }

}
/*
  Note: delete函数删除自己开辟的存储类的指针的时候，会调用析构函数删除类
        不要滥用运算符重载
*/
int main()
{
    test_a();

    return 0;
}