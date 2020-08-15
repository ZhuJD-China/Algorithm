#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int a[] = {0, 1, 2, 3};

int* Ptr = &a[(sizeof(a)/sizeof(int))];

int* Pend = &(a[3]);

void test01()
{
    if(Ptr == Pend)
        cout<<"Ptr == Pend"<<endl;
    cout<<"Ptr= "<<Ptr<<endl;
    cout<<"Pend= "<<Pend<<endl;

    for(int i=0; i<=4; i++)
    {
        cout<<&(a[i])<<endl;
    }

    vector<int> v;
    for(int i=10; i<20; i++)
        v.push_back(i);
    for(vector<int>::iterator Pbegin = v.begin(); Pbegin!=v.end(); Pbegin++)
    {
        cout<<*Pbegin<<endl;
    }
}

void test02()
{
    /*
    string_初始化_拼接_赋值_查找
    */

    string s1;           //默认初始化，s1是一个空串
    string s2(s1);       //s2是s1的副本
    string s3("value");  //直接初始化，s3是字面值"value"的副本，除了字面值最后的那个空字符外
    string s4 = "value"; //拷贝初始化，等价于s4("value"),s4是字面值"value"的副本
    string s5(10,'c');    //直接初始化，把s5初始化为由连续n个字符'c'组成的串
    string s6 = string(5,'c');//拷贝初始化，s6的内容是ccccc

    cout<<s3+s4+s5<<endl;

    string  s7 = s3+s4+s5;

    int pos = s7.find("lue"); // 从头往后
    int rpos = s7.rfind("lue"); //从尾往前
    cout<<"pos lue "<<pos<<endl;
    cout<<"rpos lue "<<rpos<<endl;
}


void test03()
{
    /*
    string替换_比较_子串_插入和删除
    */

    string s1("zjd");
    string s2 = "hzq";

    s1.replace(0, 1, s2);
    cout<<s1<<endl;

    string A ("aBcdef");
    string B ("AbcdEf");
    string C ("123456");
    string D ("123dfg");
    //下面是各种比较方法
    int m=A.compare (B); //完整的A和B的比较
    int n=A.compare(1,5,B,4,2); //"Bcdef"和"AbcdEf"比较
    int p=A.compare(1,5,B,4,2); //"Bcdef"和"Ef"比较
    int q=C.compare(0,3,D,0,3); //"123"和"123"比较
    cout << "m = " << m << ", n = " << n <<", p = " << p << ", q = " << q << endl;

    const char* ss = "zjkhs";
    string sss(ss);
    cout<<sss<<endl;

    /*
     s.substr(pos, n)    截取s中从pos开始（包括0）的n个字符的子串，并返回

       s.substr(pos)        截取s中从从pos开始（包括0）到末尾的所有字符的子串，并返回
    */
    string s4 = "hs";

    cout<<s4.substr(0, 1)<<endl;

    s4.insert(1, "zjdzjdzjd");  // 在pos的前面插入
    cout<<s4<<endl;

    string str = "hello c++! +++";
    // 从位置pos=10处开始删除，直到结尾
    // 即： " +++"
    str.erase(10);
    cout << '-' << str << '-' << endl;
    // 从位置pos=6处开始，删除4个字符
    // 即: "c++!"
    str.erase(6, 4);
    cout << '-' << str << '-' << endl;

}


int main(void)
{

    //test01();
    //test02();
    test03();
    return 0;
}
