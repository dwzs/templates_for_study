# -*- coding:utf-8 -*-


import  threading,time

g_i = 11
g_i2 = 22

def progress(arg):
    print("thread name is %s -----"%threading.current_thread().name)
    # print(arg)
    print(g_i)


if __name__ == '__main__':
    a = 1
    b = 2
    print(g_i)

    thread=threading.Thread(target=progress, args='w') #共享内存方式访问主线程内的数据（g_i）
    thread.start()
    thread.join()

