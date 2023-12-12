#include<bits/stdc++.h>
using namespace std;

int  N=4;
int board[4][4]={{1,0,3,0},
                {0,0,2,1},
                {0,1,0,2},
                {2,4,0,0}
                };


bool isSafe(int row, int col,int x)
{
    for(int i=0;i<N;i++)
    {
        if(board[row][i]==x || board[i][col]==x )
        {
            return false;
        }
    }
    
    int s=sqrt(N);
    int rs=row-row%s;
    int cs=col-col%s;

    for(int i=0;i<s;i++)
    {
        for(int j=0;j<s;j++)
        {
            if(board[i+rs][j+cs]==x)
            {
                return false;
            }
        }
    }
    return true;
}
bool solve()
{
    int i,j;
    for( i=0;i<N;i++)
    {
        for( j=0;j<N;j++)
        {
            if(board[i][j]==0)
            {
                break;
            }
        }
    }
    if(i==N && j==N)
    {
        return true;
    }
    
    for(int x=1;x<=N;x++)
    {
        if(isSafe(i,j,x))
        {
            board[i][j]=x;
            if(solve())
            {
                return true;
            }
            board[i][j]=0;
        }
    }
    return false;
}

int main()
{
    if(solve())
    {
        cout<<"YES\n";

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
           {
            cout<<board[i][j]<<" "; 
           }
           cout<<endl;
        }
    }
    else
    {
        cout<<"NO\n";
    }
    return 0;
}