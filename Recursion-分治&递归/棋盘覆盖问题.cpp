//棋盘覆盖问题-分治
/*
(tr，tc)是棋盘左上角的方格坐标
(dr,dc)是特殊方格所在的坐标
size是棋盘的行数和列数
*/
#include<iostream>
using namespace std;
int board[1025][1025];
static int tile = 1;

void ChessBoard(int tr,int tc,int dr,int dc,int size)
{
    if(size==1) return ;//递归边界

    int t=tile++;//L型骨牌号
    int s=size/2;//分割棋盘

    //覆盖左上角子棋盘
    if(dr<tr+s && dc<tc+s)
        ChessBoard(tr,tc,dr,dc,s);//特殊方格在此棋盘中
    else //此棋盘中无特殊方格，用t号L型骨牌覆盖右下角
    {
        board[tr+s-1][tc+s-1]=t;
        //覆盖其余方格
        ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
    }

    //覆盖右上角子棋盘
    if(dr<tr+s && dc>=tc+s)
        ChessBoard(tr,tc+s,dr,dc,s);//特殊方格在此棋盘中
    else //此棋盘中无特殊方格，用t号L型骨牌覆盖左下角
    {
        board[tr+s-1][tc+s]=t;
        //覆盖其余方格
        ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
    }

    //覆盖左下角子棋盘
    if(dr>=tr+s && dc<tc+s)//特殊方格在此棋盘中
        ChessBoard(tr+s,tc,dr,dc,s);
    else //此棋盘中无特殊方格，用t号L型骨牌覆盖右上角
    {
        board[tr+s][tc+s-1]=t;
        //覆盖其余方格
        ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
    }

    //覆盖右下角子棋盘
    if(dr>=tr+s && dc>=tc+s)//特殊方格在此棋盘中
        ChessBoard(tr+s,tc+s,dr,dc,s);
    else //此棋盘中无特殊方格，用t号L型骨牌覆盖左上角
    {
        board[tr+s][tc+s]=t;
        //覆盖其余方格
        ChessBoard(tr+s,tc+s,tr+s,tc+s,s);
    }
}

int main()
{
    int i,j;
    int k;
    while(cin>>k)
    {
        int size = 1<<k;
        int x,y;
        cin>>x>>y;
        board[x][y]=0;
        ChessBoard(0, 0, x, y, size);
        for(i=0; i<size; i++)
        {
            for(j = 0; j < size; j++)
                cout<< board[i][j]<<"\t";
            cout<<"\n";
        }
    }
    return 0;
}
