#include <iostream>

using namespace std;
/*
    纯虚函数和抽象类
    当类中有了纯虚函数，这个类也称为抽象类；
    抽象类无法实例化对象；
    抽象类的子类必须重写父类中的纯虚函数，否则也属于抽象类
*/


/*
    虚析构和纯虚析构
    多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码

    1. 如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
    2. 拥有纯虚析构函数的类也属于抽象类

*/

class Base
{
public:
    Base() 
    {
        std::cout << "Base 构造函数调用" << std::endl;
    }
    virtual ~Base() = 0;

    virtual void func() = 0;
};
// 有纯虚析构之后，也属于抽象类
Base::~Base()
{
    std::cout << "Base 析构函数调用" << std::endl;
}

class Son : public Base
{
public:
    Son() 
    {
        std::cout << "Son 构造函数调用" << std::endl;
    }
    ~Son() 
    {
        std::cout << "Son 析构函数调用" << std::endl;
    }
    
    virtual void func()
    {
        std::cout << "func函数调用" << std::endl;
    }
};


void test()
{    
    Base *obj = new Son;
    
    delete obj;
}
int main()
{
    test();
    return 0;
}