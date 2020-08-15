#include <iostream>
#include <iomanip>

using namespace std;

void test01()
{
    /*
    cin.peek() �䷵��ֵ��һ��char�͵��ַ����䷵��ֵ��ָ��ָ��ĵ�ǰ�ַ���
    ����ֻ�ǹ۲⣬ָ����ͣ���ڵ�ǰλ�ã��������ơ����Ҫ���ʵ��ַ����ļ�������������ֵ��EOF��-1����

    �书���Ǵ��������ж�ȡһ���ַ� �����ַ���δ����������ɾ�� ��������������һ�� ջ��
    ��ô�����peek�������൱��ջ�ĳ�Ա����front
    �����cin.get()���൱��ջ�ĳ�Ա����pop�� ������δ����ܰ����������������peek����
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
    cin.get(�ַ�������)�������������ַ�
    cin.get(�ַ�������,�����ַ���Ŀ)��������һ���ַ���,���Խ��տո�
    */
    char ch;
    ch=cin.get();//����cin.get(ch);
    cout<<ch<<endl;
}

void test03()
{
    // getline�����ɶ�ȡ���У�����ǰ����Ƕ��Ŀո񣬲�����洢���ַ���������
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
    //1) �ֱ���ʮ�����ơ�ʮ���ơ��˽����Ⱥ���� n
    cout << "1)" << hex << n << " " << dec << n << " " << oct << n << endl;
    double x = 1234567.89, y = 12.34567;
    //2)����5λ��Ч����
    cout << "2)" << setprecision(5) << x << " " << y << " " << endl;
    //3)����С�������5λ
    cout << "3)" << fixed << setprecision(5) << x << " " << y << endl;
    //4)��ѧ������������ұ���С�������5λ
    cout << "4)" << scientific << setprecision(5) << x << " " << y << endl;
    //5)�Ǹ�����ʾ���ţ�������Ϊ12�ַ�����Ȳ������� * �
    cout << "5)" << showpos << fixed << setw(12) << setfill('*') << 12.1 << endl;
    //6)�Ǹ�������ʾ���ţ�������Ϊ12�ַ�����Ȳ������ұ�������ַ����
    cout << "6)" << noshowpos << setw(12) << left << 12.1 << endl;
    //7)������Ϊ 12 �ַ�����Ȳ��������������ַ����
    cout << "7)" << setw(12) << right << 12.1 << endl;
    //8)��Ȳ���ʱ�����ź���ֵ�������ң��м�������ַ����
    cout << "8)" << setw(12) << internal << -12.1 << endl;
    cout << "9)" << 12.1 << endl;


    cout<<"----------------------------------------------------------"<<endl;

    cout.flags(ios::left); //�����
	cout << setw(10) << -456.98 << "The End" << endl;
	cout.flags(ios::internal); //���˶���
	cout << setw(10) << -456.98 << "The End" << endl;
	cout.flags(ios::right); //�Ҷ���
	cout << setw(10) << -456.98 << "The End" << endl;

	cout << left << setw(10) << -456.98 << "The End" << endl; //�����
	cout << internal << setw(10) << -456.98 << "The End" << endl; //���˶���
	cout << right << setw(10) << -456.98 << "The End" << endl; //�Ҷ���

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
