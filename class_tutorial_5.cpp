#include <iostream>

using namespace std;
struct Object
{   
    Object():a_(0), b_(0) {};
    Object(int a, int b) : a_(a), b_(b) {}; 
    void operator=(const Object &b);
    int a_;
    int b_;
};

void Object::operator=(const Object &obj)
{
    this->a_ = obj.a_;
    this->b_ = obj.b_;
}

int main()
{
    Object obj(1, 3);
    Object temp;
    temp = obj;
    cout << temp.a_ << " " << temp.b_ << endl;
    return 0;
}