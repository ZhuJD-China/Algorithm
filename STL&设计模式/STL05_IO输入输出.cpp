#include <iostream>
#include <iomanip>

using namespace std;

void test01()
{
    /*
    cin.peek() 其返回值是一个char型的字符，其返回值是指针指向的当前字符，
    但它只是观测，指针仍停留在当前位置，并不后移。如果要访问的字符是文件结束符，则函数值是EOF（-1）。

    其功能是从输入流中读取一个字符 但该字符并未从输入流中删除 若把输入流比作一个 栈类
    那么这里的peek函数就相当于栈的成员函数front
    而如果cin.get()则相当于栈的成员函数pop。 下面这段代码能帮助您更清晰地理解peek函数
    */
    char c;
    int n;
    char str[256];
    cout << "Enter a number or a word: "<<endl;
    c=cin.peek();
    if ( (c >= '0') && (c <= '9') )
    {
        cin >> n;
        cout << "You have entered number " << n << endl;
    }
    else
    {
        cin >> str;
        cout << " You have entered word " << str << endl;
    }
}

void test02()
{
    /*
    cin.get(字符变量名)可以用来接收字符
    cin.get(字符数组名,接收字符数目)用来接收一行字符串,可以接收空格
    */
    char ch;
    ch=cin.get();//或者cin.get(ch);
    cout<<ch<<endl;
}

void test03()
{
    // getline函数可读取整行，包括前导和嵌入的空格，并将其存储在字符串对象中
    string name;
    string city;
    cout << "Please enter your name: ";
    getline(cin, name);
    cout << "Enter the city you live in: ";
    getline(cin, city);
    cout << "Hello, " << name << endl;
    cout << "You live in " << city << endl;
}

void test04()
{
    int n = 141;
    //1) 分别以十六进制、十进制、八进制先后输出 n
    cout << "1)" << hex << n << " " << dec << n << " " << oct << n << endl;
    double x = 1234567.89, y = 12.34567;
    //2)保留5位有效数字
    cout << "2)" << setprecision(5) << x << " " << y << " " << endl;
    //3)保留小数点后面5位
    cout << "3)" << fixed << setprecision(5) << x << " " << y << endl;
    //4)科学计数法输出，且保留小数点后面5位
    cout << "4)" << scientific << setprecision(5) << x << " " << y << endl;
    //5)非负数显示正号，输出宽度为12字符，宽度不足则用 * 填补
    cout << "5)" << showpos << fixed << setw(12) << setfill('*') << 12.1 << endl;
    //6)非负数不显示正号，输出宽度为12字符，宽度不足则右边用填充字符填充
    cout << "6)" << noshowpos << setw(12) << left << 12.1 << endl;
    //7)输出宽度为 12 字符，宽度不足则左边用填充字符填充
    cout << "7)" << setw(12) << right << 12.1 << endl;
    //8)宽度不足时，负号和数值分列左右，中间用填充字符填充
    cout << "8)" << setw(12) << internal << -12.1 << endl;
    cout << "9)" << 12.1 << endl;


    cout<<"----------------------------------------------------------"<<endl;

    cout.flags(ios::left); //左对齐
	cout << setw(10) << -456.98 << "The End" << endl;
	cout.flags(ios::internal); //两端对齐
	cout << setw(10) << -456.98 << "The End" << endl;
	cout.flags(ios::right); //右对齐
	cout << setw(10) << -456.98 << "The End" << endl;

	cout << left << setw(10) << -456.98 << "The End" << endl; //左对齐
	cout << internal << setw(10) << -456.98 << "The End" << endl; //两端对齐
	cout << right << setw(10) << -456.98 << "The End" << endl; //右对齐

	cout<<"----------------------------------------------------------"<<endl;

	cout << setfill('0') << setw(10) << 45698 << endl;

	cout.setf(ios::showpos | ios::uppercase);
	cout << hex << setw(4) << 12 << setw(12) << -12 << endl;
	cout << dec << setw(4) << 12 << setw(12) << -12 << endl;
	cout << oct << setw(4) << 12 << setw(12) << -12 << endl;
	cout.unsetf(ios::showpos | ios::uppercase);
	cout << hex << setw(4) << 12 << setw(12) << -12 << endl;
	cout << dec << setw(4) << 12 << setw(12) << -12 << endl;
	cout << oct << setw(4) << 12 << setw(12) << -12 << endl;

	cout<<"----------------------------------------------------------"<<endl;

	cout << showbase << setw(4) << hex << 32 << setw(4) << oct << 32 << endl;
	cout << noshowbase << setw(4) << hex << 32 << setw(4) << oct << 32 << endl;

	cout.setf(ios::showbase);
	cout << setw(4) << hex << 32 << setw(4) << oct << 32 << endl;
	cout.unsetf(ios::showbase);
	cout << setw(4) << hex << 32 << setw(4) << oct << 32 << endl;

	cout<<"----------------------------------------------------------"<<endl;

	cout.setf(ios::fixed);
	cout << setprecision(0) << 12.05 << endl;
	cout << setprecision(1) << 12.05 << endl;
	cout << setprecision(2) << 12.05 << endl;
	cout << setprecision(3) << 12.05 << endl;
	cout.setf(ios::scientific, ios::floatfield);
	cout << setprecision(0) << 12.05 << endl;
	cout << setprecision(1) << 12.05 << endl;
	cout << setprecision(2) << 12.05 << endl;
	cout << setprecision(3) << 12.05 << endl;

}

int main ()
{

    //test01();
    //test02();
    //test03();
    test04();
    return 0;
}
