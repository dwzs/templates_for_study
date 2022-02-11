//
// Created by yue on 18-7-21.
//
#include <iostream>
#include <fstream>
#include <string>
#include "example.pb.h"

using namespace std;

int main() {

//////往文件里写proto里定义类型数据/////////////
    Example example;

    example.set_stringval("hello,world");   //单一数据
    
    Example_EmbeddedMessage *embeddedExample = new Example_EmbeddedMessage();
    embeddedExample->set_int32val(1);  
    example.set_allocated_embeddedexample(embeddedExample); //嵌套类型数据
    
    example.add_repeatedint32val(5);    //重复类型数据，类似数组
    example.add_repeatedint32val(4);    //重复类型数据，类似数组
    example.add_repeatedint32val(1);    //重复类型数据，类似数组

    //序列化数据写入到文件
    std::string filename = "single_length_delimited_all_example1_val_result";
    std::fstream output(filename, std::ios::out | std::ios::trunc | std::ios::binary);
    if (!example.SerializeToOstream(&output)) {
        std::cerr << "Failed to write example." << std::endl;
        exit(-1);
    }

    

    output.sync();
    output.close();

//////读序列化的数据/////////////
    Example example2read;
    fstream input(filename, ios::in | ios::binary);
    example2read.ParseFromIstream(&input);  //解析序列化文件

    cout << example2read.stringval() << endl;  //读取单一数据
    cout << example2read.embeddedexample().int32val() << endl; //读取嵌套数据数据
    cout << example2read.repeatedint32val(0) << endl;   //读取重复类型数据
    cout << example2read.repeatedint32val(1) << endl;   //读取重复类型数据
    cout << example2read.repeatedint32val(2) << endl;   //读取重复类型数据

    return 0;
}
