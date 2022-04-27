#include <iostream>

using namespace std;

class MyClass
{
public:
    MyClass()
    {
        cout << "MyClass!" << endl;
    }

    int num_;
};

// 常指针：指针指向的内容为常量
// 指针常量：指针本身是常量

int main()
{
    int i = 541;
    int i1 = 451;

    const int *cpi = &i;
    int *const pci = &i;

    // cout << cpi << "  " << *cpi << endl;
    cout << pci << "  " << *pci << endl;

    // cpi = &i1;
    // *cpi = 5;

    // pci = &i1;
    *pci = i1;

    // cout << cpi << "  " << *cpi << endl;
    cout << pci << "  " << *pci << endl;

    return 0;
}