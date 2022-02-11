//////////////////////////////////////*************************************/////////////////////////////////////////////////////////
/////////////////////重载了String的部分函数
//////////////////////////////////////*************************************/////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class String
{
public:
    String() { cout << "default constructor " << endl; } //默认构造函数；当没定义构造函数时会自动生成，这里显示声明了默认构造函数。
    String(const char *str = NULL);                      //普通构造函数
    String(const String &other);                         //拷贝构造函数

    String &operator=(const String &other); //赋值函数
    ~String(void);                          //析构函数;只有一个，不能被重载，不带参数

private:
    char *m_string; //保存字符串
};

String::~String(void) //析构函数
{
    cout << "Destructor: " << m_string << endl;
    if (m_string != NULL) //不为空，就释放内存
    {
        delete[] m_string;
        m_string = NULL;
    }
}

String::String(const char *str) //普通构造函数
{

    m_string = new char[strlen(str) + 1]; //分配空间
    strcpy(m_string, str);

    cout << "construct: " << m_string << endl;
}

String::String(const String &other) //拷贝构造函数；这里是深拷贝，编译器自动生成的拷贝构造函数为浅拷贝；
{
    m_string = new char[strlen(other.m_string) + 1]; //分配空间并拷贝
    strcpy(m_string, other.m_string);
    cout << "copy construct: " << m_string << endl;
}

String &String::operator=(const String &other) //赋值函数；这里是深拷贝，编译器自动生成赋值操作为浅拷贝；
{
    if (this == &other) //如果对象和other是用一个对象，直接返回本身
    {
        return *this;
    }
    delete[] m_string; //先释放原来的内存
    m_string = new char[strlen(other.m_string) + 1];
    strcpy(m_string, other.m_string);

    cout << "operator = funtion: " << m_string << endl;

    return *this;
}

int main()
{
    String a();        //调用默认构造函数 ; 注意与 String a 存在区别，不添加括号时可能会调用 String(const char *str = NULL)，因为存在默认值
    String b("hello"); //调用普通构造函数
    String c(b);       //调用拷贝构造函数
    String d = b;      //调用拷贝构造函数

    c = b; //调用赋值函数

    cout << endl;
    return 0;
}