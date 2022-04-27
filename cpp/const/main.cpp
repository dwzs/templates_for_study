// const 修饰对象           //对象成员不可修改
// const 修饰成员函数        //只能被const修饰的对象调用
// const 修饰成员函数返回值   //返回值不能被修改，一般当返回值为引用时可用到
// const 修饰成员函数入参     //入参不能被修改

// 常函数：
// 1.成员函数后加const后，我们称这个函数为常函数。
// （事实上，在成员函数后面加上const，修饰的是this指向，让指针指向的值不可以修改，原本的this指针就是指针常量，指针的指向不能修改，加上const后，值也不能修改。）
// 2.常函数内不可以修改成员属性
// 3.成员属性声明加关键字mutable后，在常函数中依然可以修改

// 常对象：
// 1.声明对象前加const称该对象为常对象
// （常对象的属性不能修改，但如果该常对象的属性的声明前加了mutable，则加了mutable的属性就可以修改）
// 2.常对象只能调用常函数
// (常对象不可以调用普通成员函数，因为普通成员函数可以修改属性)

#include <iostream>

using namespace std;

class A
{
public:
    A(int num) : data(num) {}
    ~A(){};

    int print_data()
    {
        cout << data << endl;
    }

    int print_data_const() const
    {
        cout << data << endl;
    }

    int data;
};

int main()
{
    A a(5);
    a.print_data();       //普通对象可调用普通成员函数
    a.print_data_const(); //普通对象可调用常成员函数

    const A a_c(4);
    // a_c.data = 1; //常对象的成员不可被修改
    // a_c.print_data(); // 常对象不能调用普通成员函数
    a_c.print_data_const(); // 常对象可调用常成员函数

    return 0;
}
