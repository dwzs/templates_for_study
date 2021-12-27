#include <iostream> // cout, cin, cerr etc...
#include <fstream> // ifstream, ofstream
#include <string>

using namespace std;

int main()
{
    std::string sFilename = "MyBinFile.bin";    
    /******************************************
     *                                        *
     *                WRITING                 *
     *                                        *
     ******************************************/
    std::ofstream fileSink(sFilename); // Creates an output file stream
    if (!fileSink) {
        std::cerr << "Canot open " << sFilename << std::endl;
        exit(-1);
    }
    /* std::endl will automatically append the correct EOL */
    // string c1 = "Hello Open Source,World1!";
    char c2[100]  = "Hello Open Source,World2!";
    int i = 3;
    fileSink.write(c2, sizeof(c2));             //writing char to bin file
    fileSink.write((char *)&i, sizeof(int));    //writing int to bin file

    fileSink.close();  //这句不能少！！！！


    /******************************************
     *                                        *
     *                READING                 *
     *                                        *
     ******************************************/
    ifstream fin(sFilename.c_str());
    if (!fin.is_open()) {
        cerr << "error: open file for input failed!" << endl;
        abort();
    }

    char c_in[100];
    
    fin.read((char *)&c_in, sizeof(c2));    // read char from bin file
    cout << c_in << endl;

    int i_in;  
    fin.read((char *)&i_in, sizeof(int));  // read int from bin file
    cout << i_in << endl;

    // int i2_in;  
    // int i3_in;                    //尝试按字节数量读取bin文件。 int i = 3; 占4个字节（0000 0000 0000 0011） 
    // fin.read((char *)&i2_in, 1);  // 读取第一个字节为3，读取第二个字节为0。 结果与预期不一致，不确定什么原因，因此最好还是不要这这么操作
    // fin.read((char *)&i3_in, 1);  // 读取第一个字节为3，读取第二个字节为0
    // cout << i2_in << endl;
    // cout << i3_in << endl;
 
    fin.close();
    return 0;

}