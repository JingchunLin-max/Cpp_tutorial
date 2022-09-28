#include<iostream>

using namespace std;

class Object
{
public:
Object():m_age(0), m_height(nullptr){}
Object(int age, int height):m_age(age), m_height(new int(height)){}
~Object()
{
    if (m_height != nullptr)
    {
        delete(m_height);
        m_height = nullptr;
    }
}

Object& operator=(const Object &obj);

int m_age;
int* m_height;

};

Object& Object::operator=(const Object &obj)
{
    if (m_height != nullptr)
    {
        delete(m_height);
        m_height = nullptr;
    }
    
    m_age = obj.m_age;
    m_height = new int(*obj.m_height);

    return *this;
}

void test()
{
    Object obj(10, 18);
    Object obj_a;

    obj_a = obj;

    cout << *obj.m_height << endl;
    cout << *obj_a.m_height << endl;
}

int main()
{
    test();

    return 0;
}