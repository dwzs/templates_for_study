/////https://winsoft666.blog.csdn.net/article/details/78520237?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1-78520237-blog-52044632.pc_relevant_multi_platform_whitelistv1&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1-78520237-blog-52044632.pc_relevant_multi_platform_whitelistv1&utm_relevant_index=1

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

class MyString
{
private:
    char *_data;
    size_t _len;
    void _init_data(const char *s)
    {
        _data = new char[_len + 1];
        memcpy(_data, s, _len);
        _data[_len] = '\0';
    }

public:
    MyString()
    {
        _data = NULL;
        _len = 0;
    }

    MyString(const char *p)
    {
        _len = strlen(p);
        _init_data(p);
    }

    // 常左值引用构造函数
    MyString(const MyString &str)
    {
        _len = str._len;
        _init_data(str._data);
        std::cout << "Copy Constructor is called! source: " << str._data << std::endl;
    }

    MyString &operator=(const MyString &str)
    {
        if (this != &str)
        {
            _len = str._len;
            _init_data(str._data);
        }
        std::cout << "Copy Assignment is called! source: " << str._data << std::endl;
        return *this;
    }

    // //右值引用构造函数
    // MyString(MyString &&str)
    // {
    //     std::cout << "Move Constructor is called! source: " << str._data << std::endl;
    //     _len = str._len;
    //     _data = str._data;
    //     str._len = 0;
    //     str._data = NULL; // ! 防止在析构函数中将内存释放掉
    // }

    // MyString &operator=(MyString &&str)
    // {
    //     std::cout << "Move Assignment is called! source: " << str._data << std::endl;
    //     if (this != &str)
    //     {
    //         _len = str._len;
    //         _data = str._data;
    //         str._len = 0;
    //         str._data = NULL; // ! 防止在析构函数中将内存释放掉
    //     }
    //     return *this;
    // }

    virtual ~MyString()
    {
        if (_data != NULL)
        {
            std::cout << "Destructor is called! " << std::endl;
            free(_data);
        }
    }
};

int main()
{
    MyString a;
    a = MyString("Hello1");
    std::vector<MyString> vec;
    vec.push_back(MyString("World"));
}
