/*
ѧУ�ݽ�����������

1��ĳ�о���һ���ݽ�����������24���˲μӣ����μ�˳�����ò����š����������֣�ǰ����Ϊ��̭����������Ϊ������

2��������ʽ���������

��һ�ַ�Ϊ4��С�飬���ݲ�����˳�����λ��֣�����100-105Ϊһ�飬106-111Ϊ�ڶ��飬
        �������ƣ�ÿ��6���ˣ�ÿ�˷ֱ𰴳�ǩ��draw��˳���ݽ�����С���ݽ������̭����������������ѡ�֣�Ȼ�������һ��С��ı�����

        �ڶ��ַ�Ϊ2��С�飬ÿ��6�ˣ�ÿ���˷ֱ𰴲�����˳���ݽ�����С�������̭����������������ѡ�֣�Ȼ�������һ��С��ı�����

         ������ֻʣ��6���ˣ�����Ϊ������ѡ��ǰ������

         ѡ��ÿ��Ҫ������飬���б�����

4���������֣�10����ί��֣�ȥ����͡���߷֣���ƽ����

ÿ��ѡ���ݽ�����10����ί�ֱ��֡���ѡ�ֵ����յ÷���ȥ��һ����߷ֺ�һ����ͷ֣����ʣ�µ�8���ɼ���ƽ���֡�ѡ�ֵ����ΰ��÷ֽ������У����÷�һ����������������������
*/

#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <algorithm>
#include <functional>
#include <string>
#include <numeric>	//����accumulate�㷨

using namespace std;

//ѡ����Ϣ
class Speaker
{
public:
	string m_name;
	int m_score[3];	//�ɴ�����ֵ�����
};

//����ѡ��
int genSpeaker(map<int, Speaker> &mapSpeaker, vector<int> &v)
{
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	random_shuffle(str.begin(), str.end());	//�������
	Speaker tmp;

	for (int i = 0; i < 24; i++)
	{
		tmp.m_name = "ѡ��";
		tmp.m_name = tmp.m_name + str[i];	//���ѡ������
		mapSpeaker.insert(pair<int, Speaker>(100 + i, tmp));	//���100 + i
	}

	for (int i = 0; i < 24; i++)
	{
		v.push_back(100 + i);	//��ʼѡ�ֵı�ŷ���v��
	}
	return 0;
}

//ѡ�ֳ�ǩ
int speech_contest_draw(vector<int> &v)
{
	random_shuffle(v.begin(), v.end());
	return 0;
}

//ѡ�ֱ���
int speech_contest(int index, vector<int> &v1, map<int, Speaker> &mapSpeaker, vector<int> &v2)
{

	multimap<int, int, greater<int>> multimapGroup;	//С������÷� ��¼���� ��ǰ3���ͺ�3�� �ɼ� ���
	int tmpCount = 0;
	//���˵÷�
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		tmpCount++;
		deque<int> dscore;	//���ÿ����ί�Ĵ��
		int score;
		for (int j = 0; j < 10; j++)	//10����ί���
		{
			score = 50 + rand() % 50;
			dscore.push_back(score);
		}
		sort(dscore.begin(), dscore.end());
		dscore.pop_back();	//ȥ����߷���ͷ�
		dscore.pop_front();
		int scoresum = accumulate(dscore.begin(), dscore.end(), 0);
		int scoreavg = scoresum / dscore.size();
		mapSpeaker[*it].m_score[index] = scoreavg;	//ѡ�ֵ÷ִ���������
		multimapGroup.insert(pair<int, int>(scoreavg, *it));	//��¼��С���� �÷� ���

		//�������
		if (tmpCount % 6 == 0)	//ÿ��С�����������ϼ���ӡ�ɼ� ����ʽ����� ���� �÷�
		{
			cout << "|*****С��������*****|" << endl;
			cout << "������\t����\t�÷�" << endl;
			for (multimap<int, int>::iterator mit = multimapGroup.begin(); mit != multimapGroup.end(); mit++)
			{
				cout << mit->second << "\t" << mapSpeaker[mit->second].m_name << "\t" << mit->first << endl;
			}

			//��ÿ��ǰ3�������ߵı�ŷ���v2
			while (multimapGroup.size() > 3)	//��Ϊ���Զ���������
			{
				multimap<int, int>::iterator it1 = multimapGroup.begin();
				v2.push_back(it1->second);
				multimapGroup.erase(it1);
			}
			multimapGroup.clear();	//�����С������ɼ�
		}
	}
	return 0;
}

//�鿴�������
int speech_contest_print(int index, vector<int> &v, map<int, Speaker> &mapSpeaker)
{
	cout << "\n/----------��"<<index+1<<"�ֱ�����������----------/" << endl;
	cout << "������\t����\t�÷�" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "\t" << mapSpeaker[*it].m_name << "\t" << mapSpeaker[*it].m_score[index] << endl;
	}
	return 0;
}

int main()
{
	//�������
	map<int, Speaker> mapSpeaker;	//ѡ�ֱ�ź���Ϣ
	vector<int>	v1;		//��ʼѡ������
	vector<int>	v2;		//��һ�ֽ�������
	vector<int>	v3;		//�ڶ��ֽ�������
	vector<int>	v4;		//������ǰ����

	//����ѡ��	�õ���һ��ѡ�ֱ�������
	genSpeaker(mapSpeaker, v1);

	cout << "\n\n\n|***�����������ʼ��һ�ֱ���***|" << endl;
	cin.get();
	//��һ�� ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������
	speech_contest_draw(v1);
	speech_contest(0, v1, mapSpeaker, v2);
	speech_contest_print(0, v2, mapSpeaker);

	cout << "\n\n\n|***�����������ʼ�ڶ��ֱ���***|" << endl;
	cin.get();
	//�ڶ��� ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������
	speech_contest_draw(v2);
	speech_contest(1, v2, mapSpeaker, v3);
	speech_contest_print(1, v3, mapSpeaker);

	cout << "\n\n\n|***�����������ʼ�����ֱ���***|" << endl;
	cin.get();
	//������ ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������
	speech_contest_draw(v3);
	speech_contest(2, v3, mapSpeaker, v4);
	speech_contest_print(2, v4, mapSpeaker);

	system("pause");
	return 0;
}
