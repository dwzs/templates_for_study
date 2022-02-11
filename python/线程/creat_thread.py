# -*- coding:utf-8 -*-


import  threading,time

def progress(arg):
    print("thread name is %s -----"%threading.current_thread().name)
    print(arg)


if __name__ == '__main__':
    
    thread=threading.Thread(target=progress, args='w') #创建一个线程
    thread.start()
    thread.join()

    threads=[threading.Thread(target=progress, args='w') for i in range(4)]#创建四个线程存入列表
    for t in threads:
        t.start()
        time.sleep(1)
    for t in threads:
        t.join()
