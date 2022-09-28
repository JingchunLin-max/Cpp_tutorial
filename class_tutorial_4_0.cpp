#include <iostream>

class Base
{
public:
    virtual void Speak()
    {
        std::cout << "Animal is talking!" << std::endl;
    }
};

class son : public Base
{
public:
    void Speak()
    {
        std::cout << "cat is meowing !" << std::endl;
    }
};

void doSpeak(Base &obj)
{
    obj.Speak();
}

// 地址早绑定的状态，在编译阶段确定函数地址
// 如果想让地址晚绑定，就是要使用virtual 虚函数。
int main()
{
    son cat;
    doSpeak(cat);
    return 0;
}  

//多态带来的好处
// a. 组织结构清晰
// b. 可读性强
// c. 对于前期和后期扩展以及维护性高
