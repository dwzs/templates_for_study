
#include <thread>
#include <mutex>
#include <iostream>
#include <list>
#include <unistd.h>

using namespace std;

class msgList
{
private:
    list<int> mylist;
    mutex m;
    int i = 0;

public:
    void WriteList1()
    {
        while (i < 10)
        {
            cout << "write1: " << i << endl;
            mylist.push_back(i++);
        }
        return;
    }

    void WriteList2()
    {
        while (i < 10)
        {
            cout << "write2: " << i << endl;
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
    thread pwrite1(&msgList::WriteList1, &mlist);
    thread pwrite2(&msgList::WriteList2, &mlist);

    pwrite1.join();
    pwrite2.join();
    cout << "threads end!" << endl;

    mlist.showList(); //子线程结束后主线程打印list
    return 0;
}