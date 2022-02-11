//tips: 编译报链接错误： 使用 g++ -Wall -pthread main_notify.cpp

#include <iostream>
#include <thread>
#include <vector>
#include <list>
#include <mutex>

#include <condition_variable>

using namespace std;

class A
{
private:
    list<int> msgqueue;
    mutex mymutex1;
    condition_variable mycon; //生成一个条件变量对象
public:
    void MsgDequeue()
    {
        int commmand = 0;
        while (true)
        {
            unique_lock<mutex> l(mymutex1);
            mycon.wait(l, [this]
                       {
                           if (!msgqueue.empty())
                               return true;
                           return false;
                       });
            commmand = msgqueue.front();
            msgqueue.pop_front();
            l.unlock(); //随时unlock()
            cout << "MsgDequeue执行，取出一个元素 " << commmand << endl;
        }

        return;
    }
    void MsgEnqueue()
    {

        for (int i = 0; i < 10; ++i)
        {
            cout << "MsgEnqueue执行，插入一个元素" << i << endl;
            unique_lock<mutex> l(mymutex1);
            msgqueue.push_back(i);
            mycon.notify_one(); //尝试把wait()线程唤醒
        }
    }
};
int main()
{
    A a;
    thread t1(&A::MsgEnqueue, &a);
    thread t2(&A::MsgDequeue, &a);
    t1.join();
    t2.join();
    cout << endl;
}
