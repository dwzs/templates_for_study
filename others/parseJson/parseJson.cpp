
//////////build:  g++ parseJson.cpp -L ./libs -ljson_linux-gcc-7_libmt
#include <string.h>
#include <json/json.h>
#include <iostream>
#include <fstream>
using namespace std;
void ReadFileJson();
void writeFileJson();

int main()
{
    ReadFileJson();
    writeFileJson();
    return 0;
}

void writeFileJson()
{
    //根节点
    Json::Value root;

    //根节点属性
    root["name"] = Json::Value("shuiyixin");
    root["age"] = Json::Value(21);
    root["sex"] = Json::Value("man");

    //子节点
    Json::Value friends1;

    //子节点属性
    friends1["friend_name"] = Json::Value("ZhaoWuxian");
    friends1["friend_age"] = Json::Value(21);
    friends1["friend_sex"] = Json::Value("man");

    //子节点挂到根节点上
    root["friends_r"] = Json::Value(friends1);

    //数组形式
    root["hobby"].append("sing");
    root["hobby"].append("1 2 3 4 5"); //x,y,h,c,s
    root["hobby"].append(5);           //x,y,h,c,s
    root["hobby"].append("/n");        //x,y,h,c,s
    root["hobby"].append(1);           //x,y,h,c,s
    root["hobby"].append(";");         //x,y,h,c,s

    for (int i = 0; i < 10; i++)
    {
        root["points"][i].append(i);
        root["points"][i].append(i + 1);
        root["points"][i].append(i + 2);
        root["points"][i].append(i + 3);
        root["points"][i].append(i + 4);
    }

    //缩进输出
    cout << "StyledWriter:" << endl;
    Json::StyledWriter sw;
    cout << sw.write(root) << endl
         << endl;

    //输出到文件
    ofstream os;
    os.open("beWrite.json", std::ios::out); //覆盖的方式打开文件
    // os.open("beWrite.json", std::ios::out | std::ios::app);  //追加的方式打开文件
    if (!os.is_open())
        cout << "error：can not find or create the file which named \" beWrite.json\"." << endl;
    os << sw.write(root);
    os.close();
}

void ReadFileJson()
{
    Json::Value root; //定义根节点
    Json::Reader reader;
    ifstream in("jsonFile.json", ios::binary); //输入json文件的绝对路径
    if (!in.is_open())
    {
        cout << "文件打开错误" << endl;
        return;
    }

    if (reader.parse(in, root))
    {
        string name = root["name"].asString(); //普通键值解析
        int no_camp = root["no_camp"].asInt();
        int save_state = root["save_state"].asInt();
        int state_locked = root["state_locked"].asInt();
        int default_state = root["default_state"].asInt();
        int recover_state = root["recover_state"].asInt();
        cout << "name 是  " << name << endl;
        cout << "no_camp is  " << no_camp << endl;
        cout << "save_state is  " << save_state << endl;
        cout << "state_locked is  " << state_locked << endl;
        cout << "default_state is  " << default_state << endl;
        cout << "recover_state is  " << recover_state << endl;
        //string str ="雄霸天下";
        //cout << str << endl;
        string relive_type = root["relive"]["type"].asString();
        int relive_relive_item = root["relive"]["relive_item"].asInt();
        cout << "relive_type is  " << relive_type << endl;
        cout << "relive_camp_item is  " << relive_relive_item << endl;
        int sz = root["relive"]["state"].size();
        for (int i = 0; i < sz; i++) //简单数组解析
        {
            int state = root["relive"]["state"][i].asInt();
            cout << "state is" << state;
        }
        cout << endl;
        int size = root["relive"]["camp_relive"].size();
        for (int i = 0; i < size; i++) //复杂数组解析
        {
            int posx = root["relive"]["camp_relive"][i]["posX"].asInt();
            int posy = root["relive"]["camp_relive"][i]["posY"].asInt();
            //cout << posx << endl;

            cout << "posx is  " << posx << "    posy is  " << posy << endl;
        }
    }
}