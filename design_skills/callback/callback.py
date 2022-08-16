# -*- coding:utf-8 -*-
#回调函数的作用
#灵活：可在应用程序定义数据处理逻辑，特别适合数据接收后处理（比如接收ros消息后放在callback函数里处理）

#回调函数1
#生成一个2k形式的偶数
def double(x):
    return x * 2
    
#回调函数2
#生成一个4k形式的偶数
def quadruple(x):
    return x * 4

#中间函数
#接受一个生成偶数的函数作为参数
#返回一个奇数
def getOddNumber(k, getEvenNumber):
    return 1 + getEvenNumber(k)
    
#起始函数，这里是程序的主函数
def main():    
    k = 1
    #当需要生成一个2k+1形式的奇数时
    i = getOddNumber(k, double)
    print(i)
    #当需要一个4k+1形式的奇数时
    i = getOddNumber(k, quadruple)
    print(i)
    #当需要一个8k+1形式的奇数时
    i = getOddNumber(k, lambda x: x * 8)
    print(i)
    
if __name__ == "__main__":
    main()
