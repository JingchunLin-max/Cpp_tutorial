#include<iostream>
#include<string>
/*
函数调用运算符重载
*/
using namespace std;
class my_print
{
public:
   void operator()(const string str)
   {
        cout << str << endl;
   }   
};

void test()
{
    my_print myp;
    string str = "lyan.lin";
    myp(str);   
}

int main()
{
    test();
    return 0;
}