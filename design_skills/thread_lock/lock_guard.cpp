//tips: 编译报链接错误： 使用 g++ -pthread lock_guard.cpp

#include <thread>
#include <mutex>
#include <iostream>

int g_i = 0;
std::mutex g_i_mutex; // protects g_i

void safe_increment()
{
    const std::lock_guard<std::mutex> lock(g_i_mutex); //程序运行到这里时会判断g_i_mutex 是否被占用，假如被占用则阻塞在这里，直到被释放才往下执行。
                                                       // lock_guard会自动释放
    ++g_i;

    std::cout << std::this_thread::get_id() << ": " << g_i << '\n';

    // g_i_mutex is automatically released when lock
    // goes out of scope
}

int main()
{
    std::cout << "main: " << g_i << '\n';

    std::thread t1(safe_increment);
    std::thread t2(safe_increment);

    t1.join();
    t2.join();

    std::cout << "main: " << g_i << '\n';
}
