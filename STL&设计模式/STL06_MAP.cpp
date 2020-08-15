#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

#define SALE_DEPATMENT 1 // ���۲���
#define DEVELOP_DEPATMENT 2 // �з�����
#define FINACIAL_DEPATMENT 3 // ������

// multimap ����
// ��˾������Ƹ�� 5 ��Ա���� 5 ��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
// ��Ա��Ϣ��: ���� ���� �绰 ���ʵ����
// ͨ�� Multimap ������Ϣ�Ĳ��� ���� ��ʾ
// �ֲ�����ʾԱ����Ϣ ��ʾȫ��Ա����Ϣ

class Worker
{
public:
    string mName;
    string mTele;
    int mAge;
    int mSalary;
};

// ����Ա��
void Create_Worker(vector<Worker>& vWorker)
{
    string seedName = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        Worker worker;
        worker.mName = "Ա��";
        worker.mName += seedName.at(i);
        worker.mAge = rand() % 10 + 20;
        worker.mTele = "010-88888888";
        worker.mSalary = rand() % 10000 + 10000;
        // ����Ա����Ϣ
        vWorker.push_back(worker);
    }
}

// Ա������
void WorkerByGroup(vector<Worker>& vWorker, multimap<int, Worker>& workeGroup)
{
    // ��Ա��������䵽��ͬ����
    srand(time(NULL));
    for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
    {
        int departID = rand() % 3 + 1;
        switch (departID)
        {
        case SALE_DEPATMENT:
            workeGroup.insert(make_pair(SALE_DEPATMENT, *it));
            break;
        case DEVELOP_DEPATMENT:
            workeGroup.insert(make_pair(DEVELOP_DEPATMENT, *it));
            break;
        case FINACIAL_DEPATMENT:
            workeGroup.insert(make_pair(FINACIAL_DEPATMENT, *it));
            break;
        default:
            break;
        }
    }
}

void showGroupWorkers(multimap<int, Worker>& workerGroup, int departID)
{
    // find(key);//���Ҽ� key �Ƿ����,�����ڣ����ظü���Ԫ�صĵ�������/�������ڣ����� map.end();
    multimap<int, Worker>::iterator it = workerGroup.find(departID);
    // �ҵ�ǰ����������
    // count(keyElem);//���������� key Ϊ keyElem �Ķ���������� map ��˵��Ҫô�� 0��Ҫô�� 1����multimap ��˵��ֵ���ܴ��� 1��
    int Departcount = workerGroup.count(departID);
    int num = 0;
    for (multimap<int, Worker>::iterator pos = it; it != workerGroup.end() && num < Departcount; pos++, num++)
    {
        cout << "������" << pos->second.mName << " ���䣺" << pos->second.mAge << " �绰��" << pos->second.mTele << " ���ʣ�" << pos->second.mSalary << endl;
    }
}

// ��ӡÿһ����Ա����Ϣ
void PrintWorkerByGroup(multimap<int, Worker>& workerGroup)
{
    // ��ӡ���۲���Ա����Ϣ
    cout << "���۲��ţ�" << endl;
    showGroupWorkers(workerGroup, SALE_DEPATMENT);
    // ��ӡ�з�����Ա����Ϣ
    cout << "�з����ţ�" << endl;
    showGroupWorkers(workerGroup, DEVELOP_DEPATMENT);
    // ��ӡ������Ա����Ϣ
    cout << "�����ţ�" << endl;
    showGroupWorkers(workerGroup, FINACIAL_DEPATMENT);
}

int main()
{
    // �����Ա����Ϣ
    vector<Worker> vWorker;
    // multimap���������Ϣ
    multimap<int, Worker> workerGroup;
    // ����Ա��
    Create_Worker(vWorker);
    // Ա������
    WorkerByGroup(vWorker, workerGroup);
    // ��ӡԱ����Ϣ
    PrintWorkerByGroup(workerGroup);


    return 0;
}
