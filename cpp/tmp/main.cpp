#include <iostream>
#include <vector>

using namespace std;

class MyClass
{
public:
    MyClass()
    {
        cout << "MyClass! " << endl;
    }

    MyClass(int i)
    {
        num_ = i;
        i++;
        cout << "MyClass1 " << num_ << endl;
    }

    MyClass(int &i)
    {
        num_ = i;
        i++;
        cout << "MyClass2 " << num_ << endl;
    }

    // MyClass(int &&i)
    // {
    //     num_ = i;
    //     i++;
    //     cout << "MyClass3 " << num_ << endl;
    // }

    static void print(int i)
    {
        cout << i << endl;
    }

    // static void print_s(int i)
    // {
    //     print2(i);
    // }
    void print2(int i)
    {
        cout << i << endl;
    }

    void print3(int i)
    {
        print(i);
        print2(i);
    }
    int num_;
};

class D
{
public:
    D(int i)
    {
        i_ = i;
    }
    void printA()
    {
        cout << "printA" << endl;
        // cout << i_ << endl;
    }
    static void printB()
    {
        cout << "printB" << endl;
        cout << is_ << endl;
    }
    int i_ = 1;
    static int is_;
};
int D::is_ = 2;

int main(void)
{
    int i = 1;
    static int i_s = 2;

    int i1 = 1;
    static int i_s1 = 2;

    int *i_h = new int();

    cout << &i << endl;
    cout << &i_s << endl;

    cout << endl;
    cout << &i1 << endl;
    cout << &i_s1 << endl;

    cout << endl;
    cout << i_h << endl;
    cout << &i_h << endl;

    // //使用new关键字，在堆区开辟一个int数组
    // char *arr = new char[5]{1, 2, 3, 4, 5};
    // //并不是计算数组arr所占用的内存空间大小，而是计算指针所占内存大小，32位系统指针占4字节，64位系统指针占8字节
    // cout << sizeof(arr) << endl;
    // //解指针，因为arr指针指向的时数组的首元素，所以实际计算的是int类型的数据所占用内存空间，int类型占4字节
    // cout << sizeof(*arr) << endl;

    // vector<int> v1;
    // vector<int> v2;
    // v1.push_back(1);
    // v1.push_back(2);
    // v1.push_back(2);
    // v1.push_back(2);
    // v1.push_back(2);
    // cout << &v1 << endl;
    // cout << &v1[0] << endl;
    // cout << sizeof(v1) << endl;
    // cout << sizeof(v1[0]) << endl;

    // cout << endl;
    // cout << &v2 << endl;
    // cout << sizeof(v2) << endl;
}

// 常指针：指针指向的内容为常量
// 指针常量：指针本身是常量

// int main()
// {
//     int i = 1;
//     MyClass m1(1);
//     // MyClass m2(i);
//     // MyClass m3(1);

//     // // cout << i << endl;
//     // m1.print2(1);
//     // m1.print(1);
//     // MyClass::print(1);
//     m1.print3(1);

//     return 0;
// }