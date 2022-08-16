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
    int a = 99;

    int b = 2;

    float c = a / b;

    cout << c; /* output will be 49.0 as 99/ 2 will be implicitly converted to 49 and 49 in float is 49.0 */

    float d = static_cast<float>(a / b);

    cout << d;

    /* output will be again 49.0 as the a/b will give us the answer 49( int / int=int) and 49 in float is 49.0 */

    float e = static_cast<float>(a) / b;

    cout << e;

    /* output will be 49.5 as static cast will convert int a into float data type ie 99 willbe convert it into 99.0 and float / int will give us the answer in float data type and will get stord in the float typed variable e */

    // getch();
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