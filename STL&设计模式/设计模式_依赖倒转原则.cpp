/*
��������ԭ���ԭʼ���壺�߲�ģ�鲻Ӧ�������ڵͲ�ģ�飬���߶�Ӧ�������ڳ���
����Ӧ��������ϸ�ڣ�ϸ��Ӧ�������ڳ���

����˼��
��������ԭ��ĺ���˼�룺Ҫ����ӿڱ�̣���Ҫ����ʵ�ֱ�̡�


*/

#include <iostream>

using namespace std;

//�߲����
class Business
{
public:
    virtual void GeneralService() = 0;
};

class TransferAccounts :public Business//����ת��ҵ��
{
public :
    void GeneralService()
    {
        cout << "����ת��ҵ��" << endl;
    }
};


class SaveMoney :public Business//�����Ǯҵ��
{
public:
    void GeneralService()
    {
        cout << "�����Ǯҵ��" << endl;
    }
};

class DrawMoney :public Business//����ȡǮҵ��
{
public:
    void GeneralService()
    {
        cout << "����ȡǮҵ��" << endl;
    }
};

//�в��߼�
void test(Business*my)
{
    my->GeneralService();
    delete my;
}


//ҵ���߼�
void test01()
{
    test(new TransferAccounts);
    test(new SaveMoney);
    test(new DrawMoney);
}

int main(void)
{
    test01();

    return 0;
}
