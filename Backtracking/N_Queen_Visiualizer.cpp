#include<bits/stdc++.h>
using namespace std;

int board[4][4]={{0}};

bool isSafe(int col,int row,int N)
{
    for(int i=0;i<col;i++)
    {
        if(board[row][i]==1)
        {
            return false;
        }
    }

    for(int i=row,j=col;i>=0 && j>=0 ;i--,j--)
    {
        if(board[i][j]==1)
        {
            return false;
        }
    }

    for(int i=row,j=col;i<N &&j>=0;i++,j--)
    {
        if(board[i][j]==1)
        {
            return false;
        }
    }

    return true;
}
bool queen(int col,int N)
{
   if(col==N)
   {
    return true;
   }
   
   for(int i=0;i<N;i++)
   {
    if(isSafe(col,i,N))
    {
        board[i][col]=1;
        if(queen(col+1,N))
        {
            return true;
        }
        board[i][col]=0;
    }
   }
   return false;
}

int main()
{
    int N=4;

    if(queen(0,N))
    {
        cout<<"Yes\n";
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
        cout<<"No\n";
    }
    return 0;
}