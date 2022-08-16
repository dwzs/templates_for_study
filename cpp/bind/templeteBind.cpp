#include <functional>
#include <iostream>
#include <string>
#include "boost/bind.hpp"

using namespace std;

class some_class
{
    public:

    void print_string( string s1, string s2)
    {
        cout << s1 << "----" << s2 << " from class " << '\n';
    }

};

void print_string( string s1, string s2)
{ 
    cout << s1 << "----" << s2 << '\n';
}



int main()
{

    some_class sc;

    //原始函数 void print_string( string s1, string s2)
    auto func1 = boost::bind(&print_string, "wsy", "123");  // 减少函数入参个数 func1（）
    auto func11 = boost::bind(&print_string, _1, "123");  // 减少函数入参个数 func1（arg1）

    auto func2 = boost::bind(&print_string, _2, _1);  // 改变函数入参顺序 func1（arg2, arg1）

    auto func3 = boost::bind(&some_class::print_string, &sc, _1, _2);  // 绑定对象的函数,用于回调函数绑定对象指针


    func1("123");
    func11("wsy");
    func2("wsy", "123");
    func3("wsy", "123");

}
