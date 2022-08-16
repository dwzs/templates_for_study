/////////////////////////////////////////////////////
//condition_variable:
// wait()
// wait_for();
// wait_until();

// notify_one();  //取消某个等待的线程，具体线程不确定
// notify_all();
/////////////////////////////////////////////////////

#include <thread>
#include <mutex>
#include <iostream>
#include <deque>
#include <condition_variable>
#include <unistd.h>
#include <atomic>

////////////////////// wait(lock) ////////////////////////////////////////////////////////////////////
std::mutex g_mtx_;
std::condition_variable g_cond_;
std::atomic<bool> g_pred_;

void test_wait()
{
    std::unique_lock<std::mutex> lock(g_mtx_);
    g_cond_.wait(lock); // 收到notify就解除阻塞

    printf("---------I am test_wait---------\n");
}

int main()
{
    printf("-------------test_wait-------------\n");
    std::thread t1(test_wait);
    printf("------------sleep start------------\n");
    sleep(3);
    printf("-------------sleep end-------------\n");
    {
        std::unique_lock<std::mutex> lock(g_mtx_);
    }
    g_cond_.notify_one();
    t1.join();
    return 0;
}

// /////////////// wait(lock, _Predicate) ///////////////////////////////////////////////////////////////////////////
// std::mutex g_mtx_;
// std::condition_variable g_cond_;
// std::atomic<bool> g_pred_;

// void test_wait_pred()
// {
//     std::unique_lock<std::mutex> lock(g_mtx_);
//     g_cond_.wait(lock, []
//                  { return true; });  //收到 notify 后判断函数返回结果，返回true则解除阻塞

//     printf("---------I am test_wait_pred---------\n");
// }

// int main()
// {
//     printf("----------test_wait_pred-----------\n");
//     std::thread t1(test_wait_pred);
//     printf("----------awaken first-------------\n");
//     {
//         std::unique_lock<std::mutex> lock(g_mtx_);
//     }
//     g_cond_.notify_one();
//     sleep(2);
//     printf("----------awaken second------------\n");
//     {
//         std::unique_lock<std::mutex> lock(g_mtx_);
//         g_pred_.store(true);
//     }
//     g_cond_.notify_one();
//     t1.join();
//     return 0;
// }
