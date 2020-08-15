#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

#define SALE_DEPATMENT 1 // 销售部门
#define DEVELOP_DEPATMENT 2 // 研发部门
#define FINACIAL_DEPATMENT 3 // 财务部门

// multimap 案例
// 公司今天招聘了 5 个员工， 5 名员工进入公司之后，需要指派员工在那个部门工作
// 人员信息有: 姓名 年龄 电话 工资等组成
// 通过 Multimap 进行信息的插入 保存 显示
// 分部门显示员工信息 显示全部员工信息

class Worker
{
public:
    string mName;
    string mTele;
    int mAge;
    int mSalary;
};

// 创建员工
void Create_Worker(vector<Worker>& vWorker)
{
    string seedName = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        Worker worker;
        worker.mName = "员工";
        worker.mName += seedName.at(i);
        worker.mAge = rand() % 10 + 20;
        worker.mTele = "010-88888888";
        worker.mSalary = rand() % 10000 + 10000;
        // 保存员工信息
        vWorker.push_back(worker);
    }
}

// 员工分组
void WorkerByGroup(vector<Worker>& vWorker, multimap<int, Worker>& workeGroup)
{
    // 把员工随机分配到不同部门
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
    // find(key);//查找键 key 是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回 map.end();
    multimap<int, Worker>::iterator it = workerGroup.find(departID);
    // 找当前部门总人数
    // count(keyElem);//返回容器中 key 为 keyElem 的对组个数。对 map 来说，要么是 0，要么是 1。对multimap 来说，值可能大于 1。
    int Departcount = workerGroup.count(departID);
    int num = 0;
    for (multimap<int, Worker>::iterator pos = it; it != workerGroup.end() && num < Departcount; pos++, num++)
    {
        cout << "姓名：" << pos->second.mName << " 年龄：" << pos->second.mAge << " 电话：" << pos->second.mTele << " 工资：" << pos->second.mSalary << endl;
    }
}

// 打印每一部分员工信息
void PrintWorkerByGroup(multimap<int, Worker>& workerGroup)
{
    // 打印销售部门员工信息
    cout << "销售部门：" << endl;
    showGroupWorkers(workerGroup, SALE_DEPATMENT);
    // 打印研发部门员工信息
    cout << "研发部门：" << endl;
    showGroupWorkers(workerGroup, DEVELOP_DEPATMENT);
    // 打印财务部门员工信息
    cout << "财务部门：" << endl;
    showGroupWorkers(workerGroup, FINACIAL_DEPATMENT);
}

int main()
{
    // 存放新员工信息
    vector<Worker> vWorker;
    // multimap保存分组信息
    multimap<int, Worker> workerGroup;
    // 创建员工
    Create_Worker(vWorker);
    // 员工分组
    WorkerByGroup(vWorker, workerGroup);
    // 打印员工信息
    PrintWorkerByGroup(workerGroup);


    return 0;
}
