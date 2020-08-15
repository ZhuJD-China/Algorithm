#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;
int w, h, n, s[5], t[5];
char dataset[40][40];
int G[300][6], color[300][300][300], dist[300][300][300], redist[300][300][300];
int deg[300];   //记录每个编号为i的空格周围可以走的步数

int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};


//int Count =0;  //测试到返回结果 压队列的次数 比较单向BFS和双向BFS的效率

int ID(int a, int b, int c)      //对状态进行编码，一个位置占8位
{
    return (a << 16) | (b << 8) | c;
}

bool conflict(int a, int b, int a2, int b2)
{
    return ((a2 == b2) || (a == b2 && b == a2));//移动到了同一个点上，或者是交换了位置等都是不合理的形式
}

int bfs()
{
    queue<int> qf;  //记录正向bfs
    queue<int> qb;  //记录反向bfs

    dist[s[0]][s[1]][s[2]] = 0;
    dist[t[0]][t[1]][t[2]] = 1; //分别记录正反两种遍历走了多少步数

    qf.push(ID(s[0], s[1], s[2]));
    qb.push(ID(t[0], t[1], t[2]));  //起点终点分别压入队列，压入队列的时候对点进行编码

    color[s[0]][s[1]][s[2]] = 1;
    color[t[0]][t[1]][t[2]] = 2;    //分别标注正反两种遍历已经走过的,三个点同时动

    while(!qf.empty() || !qb.empty())
    {
        int fnum = qf.size(), bnum = qb.size();
        while(fnum--)
        {
            int u = qf.front();
            qf.pop();
            int a = (u >> 16) & 0xff, b = (u >> 8) & 0xff, c = u & 0xff;//解码出出列状态三个小鬼的位置

            for(int i = 0; i < deg[a]; i++)
            {
                int a2 = G[a][i];
                for(int j = 0; j < deg[b]; j++)
                {
                    int b2 = G[b][j];
                    if(conflict(a, b, a2, b2))  continue;

                    for(int k = 0; k < deg[c]; k++)
                    {
                        int c2 = G[c][k];
                        if(conflict(a, c, a2, c2) || conflict(b, c, b2, c2))    continue;

                        if(color[a2][b2][c2] == 0)
                        {
                            dist[a2][b2][c2] = dist[a][b][c] + 1;
                            color[a2][b2][c2] = 1;
                            qf.push(ID(a2, b2, c2));
                          //  Count++;
                        }
                        else if(color[a2][b2][c2] == 2)   //双向BFS搜素碰面了就等于找到最短路了
                        {
                            return dist[a][b][c] + dist[a2][b2][c2];
                        }
                    }
                }
            }
        }

        while(bnum--)
        {
            int u = qb.front();
            qb.pop();
            int a = (u >> 16) & 0xff, b = (u >> 8) & 0xff, c = u & 0xff;//oxff：256 , 二进制 ：11111111

            for(int i = 0; i < deg[a]; i++)
            {
                int a2 = G[a][i];
                for(int j = 0; j < deg[b]; j++)
                {
                    int b2 = G[b][j];
                    if(conflict(a, b, a2, b2))  continue;

                    for(int k = 0; k < deg[c]; k++)
                    {
                        int c2 = G[c][k];
                        if(conflict(a, c, a2, c2) || conflict(b, c, b2, c2))    continue;

                        if(color[a2][b2][c2] == 0)
                        {
                            dist[a2][b2][c2] = dist[a][b][c] + 1;
                            color[a2][b2][c2] = 2;
                            qb.push(ID(a2, b2, c2));
                        //    Count++;
                        }
                        else if(color[a2][b2][c2] == 1)
                        {
                            return dist[a][b][c] + dist[a2][b2][c2];
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    while(~scanf("%d%d%d", &w, &h, &n) && w)
    {
        getchar();
        for(int i = 0; i < h; i++)  gets(dataset[i]);
        int cnt = 0, x[300], y[300], id[20][20];    //从图中抽取出空间并求出初始状态和目标状态,
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
            {
                if(dataset[i][j] != '#')
                {
                    x[cnt] = i;
                    y[cnt] = j;
                    id[i][j] = cnt;//记录点的编号，xy数组根据编号得到点，id根据点得到编号
                    if(islower(dataset[i][j]))  s[dataset[i][j] - 'a'] = cnt;       //初始状态
                    else if(isupper(dataset[i][j])) t[dataset[i][j] - 'A'] = cnt;   //目标状态
                    cnt++;  //注意这里的cnt++不能偷懒在上面一行末尾，因为这样有时候cnt++会没有执行
                }
            }

        //将所有的空格提出来建一张图，而不是临时去判断五种走法是否合法
        for(int i = 0; i < cnt; i++)    //利用空格建立图，我们一共cnt个点，然后将每个点对应的五种情况都放进G图中
                                        //deg[i]表示这个点的五种情况哪一种可以走
        {
            deg[i] = 0;
            for(int j = 0; j < 5; j++)
            {
                int nx = x[i] + dx[j];
                int ny = y[i] + dy[j];
                if(dataset[nx][ny] != '#')  G[i][deg[i]++] = id[nx][ny];//储存的是点的编号
            }
        }

        if(n <= 2)
        {
            deg[cnt] = 1;    //没有第三个点，添加第三个点
            G[cnt][0] = cnt;
            s[2] = t[2] = cnt++;
        }
        if(n <= 1)
        {
            deg[cnt] = 1;    //只包含一个点，仍然满足的话，添加第二个点
            G[cnt][0] = cnt;
            s[1] = t[1] = cnt++;
        }

        memset(dist, 0, sizeof(dist));
        memset(color, 0, sizeof(color));
        if(s[0] == t[0] && s[1] == t[1] && s[2] == t[2])    printf("0\n");
        else    printf("%d\n", bfs());
    }

   // cout<<Count<<endl;// 431352
    return 0;
}

/*
Sample Input：

5 5 2
#####
#A#B#
#   #
#b#a#
#####
16 4 3
################
## ########## ##
#    ABCcba    #
################
16 16 3
################
### ##    #   ##
##  #  ##   # c#
#  ## ########b#
# ##  # #   #  #
#  # ##   # # ##
##  a#  # # #  #
### ## #### ## #
##   #   #  #  #
#  ##### # ## ##
####   #B# #   #
##  C#   #   ###
#  # # ####### #
# ######  A##  #
#        #    ##
################
0 0 0

Sample Output：

7
36
77
*/
