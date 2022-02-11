# -*- coding:utf-8 -*-
import os
import commands
import subprocess
# 1.system()  程序需要阻塞并等待返回
print('======system()======')     
r1 = os.system('ls -al /')
print(r1)

##2. popen()  程序需要阻塞并等待返回
print('======popen()======')
r2 = os.popen('ls -al /').read()
print(r2)

##3. commands.getoutput()  程序需要阻塞并等待返回
print('======commands.getoutput()======')
r3 = commands.getoutput("ls -al /")
print(r3)

##4. commands.getoutput()  程序需要阻塞并等待返回
print('======subprocess.call()======')
r4 = subprocess.call('ls -al /', shell=True)
print(r4)


