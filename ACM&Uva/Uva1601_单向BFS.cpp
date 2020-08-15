#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<queue>
#include<stack>
using namespace std;

const int maxs = 20; ///矩形地图，最大16，这里设置大点，20吧
const int maxn = 150; /// 75% cells plus 2 fake nodes 根据题意，2*2的格子里至少有一个障碍，那么能走的格点数设为150
const int dx[]= {1,-1,0,0,0}; /// 4 moves, plus "no move"
const int dy[]= {0,0,1,-1,0};


//int Count =0;  //测试到返回结果 压队列的次数 比较单向BFS和双向BFS的效率

inline int ID(int a, int b, int c)
{
    //内联函数，减少执行时间
    return (a<<16)|(b<<8)|c;
    //由于int 类型保存8个字节，所以这个操作将a放到了最前面的8个字节，b放到了中间的8个字节，c放到了最后的8个字节
    //a，b，c最大为256，也就是8位。
    //相当于将三个数直接映射成一个整数，方便下面搜索
}

int s[3], t[3]; /// starting/ending position of each ghost //代表初始节点(s)和目标节点(t)


int deg[maxn], G[maxn][5]; /// target cells for each move (including "no move").
//图的信息
//deg 代表 第 maxn 号节点的边数，也就是能往几个方向走(包括原地不动) -> deg 表示出度，存储能够前进的方向
//G 代表 第 maxn 号节点 的 第 i 条边连的节点的编号，也就是第maxn号节点的邻居(包括自己)


inline bool conflict(int a, int b, int a2, int b2)
{
    //内联函数，同样是减少执行时间
    return a2 == b2 || (a2 == b && b2 == a);///第一个表示a,b进入同一空格，第二个表示2者交换位置
    //题目说两个鬼不能占用同一个格点，且不能在一步之内交换位置
}

int d[maxn][maxn][maxn]; /// distance from starting state 与起始状态的距离
//第maxn 个状态到起点的距离

int bfs()
{
    queue<int> q;
    memset(d, -1, sizeof(d));
    q.push(ID(s[0], s[1], s[2])); /// starting node 三个鬼的位置 和在一起表示一个状态
    d[s[0]][s[1]][s[2]] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        //配合上面的函数 ID();
        int a = u>>16, b = (u>>8)&0xff, c = u&0xff;  //&0xff表示取最后的8个字节

        if(a == t[0] && b == t[1] && c == t[2]) return d[a][b][c]; // solution found 搜到了

        //三重循环，三个鬼一起走
        for(int i = 0; i < deg[a]; i++)
        {
            int a2 = G[a][i]; //a下一个节点的编号
            for(int j = 0; j < deg[b]; j++)
            {
                int b2 = G[b][j]; //b下一个节点的编号

                if(conflict(a, b, a2, b2)) continue;//是否满足条件

                for(int k = 0; k < deg[c]; k++)
                {
                    int c2 = G[c][k];

                    if(conflict(a, c, a2, c2)) continue;
                    if(conflict(b, c, b2, c2)) continue;

                    if(d[a2][b2][c2] != -1) continue;//判断是否被访问过,被访问过一定不是最短路径

                    d[a2][b2][c2] = d[a][b][c]+1; //更新距离
                    q.push(ID(a2, b2, c2));
                              //  Count++;
                }
            }
        }
    }
    return -1;
}

int main()
{
    int w, h, n; //长宽，鬼数

    while(scanf("%d%d%d\n", &w, &h, &n) == 3 && n)
    {
        char maze[20][20];//迷宫

        for(int i = 0; i < h; i++)
            fgets(maze[i], 20, stdin);//读入迷宫
            //切记，不要用getline...某些行中不会补齐空格


        // extract empty cells
        int cnt, x[maxn], y[maxn], id[maxs][maxs]; //cnt is the number of empty cells
        //分别代表编号cnt，第maxn号的x值，第maxn号的y值，位置(x,y)的ID

        cnt = 0;
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                if(maze[i][j] != '#')
                {
                    x[cnt] = i;  //第cnt号的x值
                    y[cnt] = j;  //第cnt号的y值  可以直接用x, y 两个数组访问第cnt号在图中x和y的下标
                    id[i][j] = cnt;  // 第cnt号在图中的位置(x,y)的ID

                    if(islower(maze[i][j])) s[maze[i][j] - 'a'] = cnt; //注意减的是小写a
                    else if(isupper(maze[i][j])) t[maze[i][j] - 'A'] = cnt; //注意减的是大写A

                    cnt++;
                }

        // build a graph of empty cell
        //利用空格建立图，我们一共cnt个点，然后将每个点对应的五种情况都放进G图中
        //deg[i]表示这个点的五种情况哪一种可以走
        for(int i = 0; i < cnt; i++)
        {
            //通过节点编号建图，而不是坐标
            deg[i] = 0;//先初始化一下边

            for(int dir = 0; dir < 5; dir++)
            {
                //找邻居，自己当然也算了
                int nx = x[i]+dx[dir], ny = y[i]+dy[dir];
                // "Outermost cells of a map are walls 地图的最外层细胞是墙"
                //    means we don't need to check out-of-bound
                if(maze[nx][ny] != '#') G[i][deg[i]++] = id[nx][ny];//出度+1，指向空格区域
                //将点(nx,ny)与点i连起来，建立关系  //储存的是点的编号
            }
        }

        // add fakes nodes so that in each case we have 3 ghosts. this makes the code shorter
        //强制性将鬼填满，注意：这不是强迫症，只是减少代码量(判断鬼为2或1时的情况)
        if(n <= 2)  //没有第三个点，添加第三个点
        {
            deg[cnt] = 1;
            G[cnt][0] = cnt;
            s[2] = t[2] = cnt++;
        }
        if(n <= 1)  //只包含一个点，仍然满足的话，添加第二个点
        {
            deg[cnt] = 1;
            G[cnt][0] = cnt;
            s[1] = t[1] = cnt++;
        }

        printf("%d\n", bfs());
    }

    //    cout<<Count<<endl;//1085033
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

