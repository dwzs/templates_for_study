
#include <thread>
#include <mutex>
#include <iostream>
#include <list>

using namespace std;

class msgList
{
private:
    list<int> mylist;
    mutex m;
    int i = 0;

public:
    void WriteList()
    {
        while (i < 10)
        {
            lock_guard<mutex> guard(m); //对象创建时构造函数中调用 m.lock(), 析构函数中自动调用 m.unlock()
            mylist.push_back(i++);
        }
        return;
    }
    void showList()
    {
        for (auto p = mylist.begin(); p != mylist.end(); p++)
        {
            cout << (*p) << " ";
        }
        cout << endl;
        cout << "size of list : " << mylist.size() << endl;
        return;
    }
};
int main()
{
    msgList mlist;
    thread pwrite0(&msgList::WriteList, &mlist);
    thread pwrite1(&msgList::WriteList, &mlist);

    pwrite0.join();
    pwrite1.join();
    cout << "threads end!" << endl;

    mlist.showList(); //子线程结束后主线程打印list
    return 0;
}