#include <iostream>

using namespace std;

class MyClass
{
public:
    MyClass()
    {
        cout << "MyClass! " << endl;
    }

    // MyClass(int i)
    // {
    //     num_ = i;
    //     i++;
    //     cout << "MyClass1 " << num_ << endl;
    // }

    MyClass(int &i)
    {
        num_ = i;
        i++;
        cout << "MyClass2 " << num_ << endl;
    }

    int num_;
};

// 常指针：指针指向的内容为常量
// 指针常量：指针本身是常量

int main()
{
    int i = 1;
    MyClass m1(1);
    // MyClass m2(i);
    // MyClass m3(1);

    cout << i << endl;

    return 0;
}