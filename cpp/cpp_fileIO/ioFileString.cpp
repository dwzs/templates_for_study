    #include <iostream> // cout, cin, cerr etc...
    #include <fstream> // ifstream, ofstream
    #include <string>

    using namespace std;

    int main()
    {
        std::string sFilename = "MyFile.txt";    
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
        fileSink << "Hello Open Source,World1!" << std::endl;
        fileSink << 123 << std::endl;
        fileSink << 541 << std::endl;
        /******************************************
         *                                        *
         *                READING                 *
         *                                        *
         ******************************************/
       
        std::ifstream fileSource(sFilename); // Creates an input file stream
        if (!fileSource) {
            std::cerr << "Canot open " << sFilename << std::endl;
            exit(-1);
        }
        else {
            ///////////////从文件读取有下面三种方式，
            // //1. <<  >>
            std::string buffer;
            while (fileSource >> buffer)     //默认以空格作为分割符
            {
                std::cout << buffer << std::endl;
            }

            // //2.get()
            // char ch;
            // while (fileSource.get(ch)) {     //每次获取一个字符，
            //     std::cout << ch << std::endl;
            // }

            // //3.getline()
            // string line;
            // while (getline(fileSource, line)) {   //默认以回车为分割符
            //     std::cout << line << std::endl;
            // }
            // string line2;
            // while (getline(fileSource, line2, ',') ) {    //以逗号作为分割符,默认会忽视掉回车符
            //     std::cout << line2 << std::endl;
            // }

        }
        exit(0);
    }
