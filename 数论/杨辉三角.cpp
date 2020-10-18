/*
��                         1
                         1   1
                       1   2   1
                     1   3   3   1
                   1   4   6   4   1
                 1   5   10  10  5   1
               1   6   15  20  15  6   1
             1   7   21  35  35  21  7   1
           1   8   28  56  70  56  28  8   1
         1   9   36  84  126 126 84  36  9   1
       1   10  45  120 210 252 210 120 45  10  1
     1   11  55  165 330 462 462 330 165 55  11  1
   1   12  66  220 495 792 924 792 495 220 66  12  1
...
*/

//��ӡ�������

#include <iostream>
#include <vector>
using namespace std;
//������
/**
* n  ������
* return ������ŵ���ά�����з���
*/
vector<vector<int>> gen(int n)
{
    vector <vector<int>> res(n, vector<int>());
    for (int i = 0; i < n; i++)
    {
        //ȷ��ÿһ�����е����ָ���
        res[i].resize(i + 1);
        //��ͷ��Ϊ1
        res[i][0] = 1;
        res[i][i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            //i j λ�õ����ֵ�������������+����
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
    }

    return res;
}
//���Ժ���
int main()
{

    int n;
    while (cin >> n)
    {

        vector<vector<int>> res = gen(n);

        for (int i = 0; i < res.size(); i++)
        {
            //��ӡ�ո�ʹ������������
            for (int k = 0; k < n - i; k++)
            {
                cout << ' ';
            }
            for (int j = 0; j < res[i].size(); j++)
            {
                if (j == 0)cout<< res[i][j];
                else cout << ' '<<res[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}



