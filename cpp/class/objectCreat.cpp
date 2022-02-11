
#include<iostream>

using namespace std;

void print()
{
    cout << "wsy" << endl;
}

class A
{
    public:
        A();
        A(string s);
    
};

A::A()
{
    cout << "creat A" << endl;
}

A::A(string s)
{
    cout << "creat A " << "and input: " << s << endl;
}

//class B
class B
{
    public:
        B();
        B(string s);
        A a1_;
        A a2_;
        // A a2_("wsy");  //error: expected identifier before string constant:在类声明时不能调用对象的构造函数，因为此时程序还没有进入到执行步骤，所以不能调用构造函数或者执行运算。
        // cout << "wsy" << endl;  //error: ‘cout’ does not name a type  :内存，堆栈等运行环境没准备好，因此不识别 cout
        // print();    //error: ISO C++ forbids declaration of ‘print’ with no type :同上
};

B::B():a1_("a1"),a2_("a2")   //这里可以选择调用A的哪一个构造函数
{
    // a1_("a1")  //这里调用的时A的“()”这个运算符，而这个运算符没有定义，因此报错找不到操作符“（）”。
    cout << "creat B" << endl;
}

B::B(string s)
{
    cout << "creat B " << "and input: " << s << endl;
}


int main()
{
    // A a1;
    // A a2("wsy");

    B b1;
    // B b2("123");

    // A;   //error: declaration does not declare anything 
    // A();   //调用构造函数 A()
    // A("A");  //调用构造函数 A(string s)

    // A a();   // 与 A a 调用相同构造函数

    // A a = A();   //赋值构造
}