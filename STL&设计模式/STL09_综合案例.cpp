/*
学校演讲比赛案例：

1）某市举行一场演讲比赛，共有24个人参加，按参加顺序设置参赛号。比赛共三轮，前两轮为淘汰赛，第三轮为决赛。

2）比赛方式：分组比赛

第一轮分为4个小组，根据参赛号顺序依次划分，比如100-105为一组，106-111为第二组，
        依次类推，每组6个人，每人分别按抽签（draw）顺序演讲。当小组演讲完后，淘汰组内排名最后的三个选手，然后继续下一个小组的比赛。

        第二轮分为2个小组，每组6人，每个人分别按参赛号顺序演讲。当小组完后，淘汰组内排名最后的三个选手，然后继续下一个小组的比赛。

         第三轮只剩下6个人，本轮为决赛，选出前三名。

         选手每次要随机分组，进行比赛。

4）比赛评分：10个评委打分，去除最低、最高分，求平均分

每个选手演讲完由10个评委分别打分。该选手的最终得分是去掉一个最高分和一个最低分，求得剩下的8个成绩的平均分。选手的名次按得分降序排列，若得分一样，按参赛号升序排名。
*/

#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <functional>
#include <string>
#include <numeric>	//包含accumulate算法

using namespace std;

//选手信息
class Speaker
{
public:
	string m_name;
	int m_score[3];	//可存放三轮的评分
};

//产生选手
int genSpeaker(map<int, Speaker> &mapSpeaker, vector<int> &v)
{
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	random_shuffle(str.begin(), str.end());	//随机排序
	Speaker tmp;

	for (int i = 0; i < 24; i++)
	{
		tmp.m_name = "选手";
		tmp.m_name = tmp.m_name + str[i];	//获得选手名称
		mapSpeaker.insert(pair<int, Speaker>(100 + i, tmp));	//编号100 + i
	}

	for (int i = 0; i < 24; i++)
	{
		v.push_back(100 + i);	//初始选手的编号放入v中
	}
	return 0;
}

//选手抽签
int speech_contest_draw(vector<int> &v)
{
	random_shuffle(v.begin(), v.end());
	return 0;
}

//选手比赛
int speech_contest(int index, vector<int> &v1, map<int, Speaker> &mapSpeaker, vector<int> &v2)
{

	multimap<int, int, greater<int>> multimapGroup;	//小组比赛得分 记录下来 求前3名和后3名 成绩 编号
	int tmpCount = 0;
	//个人得分
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		tmpCount++;
		deque<int> dscore;	//存放每个评委的打分
		int score;
		for (int j = 0; j < 10; j++)	//10个评委打分
		{
			score = 50 + rand() % 50;
			dscore.push_back(score);
		}
		sort(dscore.begin(), dscore.end());
		dscore.pop_back();	//去除最高分最低分
		dscore.pop_front();
		int scoresum = accumulate(dscore.begin(), dscore.end(), 0);
		int scoreavg = scoresum / dscore.size();
		mapSpeaker[*it].m_score[index] = scoreavg;	//选手得分存入容器中
		multimapGroup.insert(pair<int, int>(scoreavg, *it));	//记录在小组里 得分 编号

		//处理分组
		if (tmpCount % 6 == 0)	//每个小组的人评分完毕级打印成绩 按格式：编号 名称 得分
		{
			cout << "|*****小组比赛结果*****|" << endl;
			cout << "参赛号\t姓名\t得分" << endl;
			for (multimap<int, int>::iterator mit = multimapGroup.begin(); mit != multimapGroup.end(); mit++)
			{
				cout << mit->second << "\t" << mapSpeaker[mit->second].m_name << "\t" << mit->first << endl;
			}

			//把每组前3名晋级者的编号放入v2
			while (multimapGroup.size() > 3)	//因为已自动降序排序
			{
				multimap<int, int>::iterator it1 = multimapGroup.begin();
				v2.push_back(it1->second);
				multimapGroup.erase(it1);
			}
			multimapGroup.clear();	//清除本小组比赛成绩
		}
	}
	return 0;
}

//查看比赛结果
int speech_contest_print(int index, vector<int> &v, map<int, Speaker> &mapSpeaker)
{
	cout << "\n/----------第"<<index+1<<"轮比赛晋级名单----------/" << endl;
	cout << "参赛号\t姓名\t得分" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "\t" << mapSpeaker[*it].m_name << "\t" << mapSpeaker[*it].m_score[index] << endl;
	}
	return 0;
}

int main()
{
	//容器设计
	map<int, Speaker> mapSpeaker;	//选手编号和信息
	vector<int>	v1;		//初始选手名单
	vector<int>	v2;		//第一轮晋级名单
	vector<int>	v3;		//第二轮晋级名单
	vector<int>	v4;		//第三轮前三名

	//产生选手	得到第一轮选手比赛名单
	genSpeaker(mapSpeaker, v1);

	cout << "\n\n\n|***输入任意键开始第一轮比赛***|" << endl;
	cin.get();
	//第一轮 选手抽签 选手比赛 查看比赛结果
	speech_contest_draw(v1);
	speech_contest(0, v1, mapSpeaker, v2);
	speech_contest_print(0, v2, mapSpeaker);

	cout << "\n\n\n|***输入任意键开始第二轮比赛***|" << endl;
	cin.get();
	//第二轮 选手抽签 选手比赛 查看比赛结果
	speech_contest_draw(v2);
	speech_contest(1, v2, mapSpeaker, v3);
	speech_contest_print(1, v3, mapSpeaker);

	cout << "\n\n\n|***输入任意键开始第三轮比赛***|" << endl;
	cin.get();
	//第三轮 选手抽签 选手比赛 查看比赛结果
	speech_contest_draw(v3);
	speech_contest(2, v3, mapSpeaker, v4);
	speech_contest_print(2, v4, mapSpeaker);

	system("pause");
	return 0;
}
