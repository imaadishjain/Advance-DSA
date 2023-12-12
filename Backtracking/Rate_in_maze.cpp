#include<bits/stdc++.h>
using namespace std;

int maze[4][4]= {{1,0,0,0},
                    {1,1,0,1},
                    {0,1,0,0},
                    {1,1,1,1}};

int board[4][4]={{0,0}};
bool isSafe(int i, int j,int N)
{
    if(i<N && j<N && maze[i][j]==1)
    {
        return true;
    }
    return false;
}


bool ratinmaze(int i, int j,int N)
{
     if(i==N-1 && j==N-1)
     {
        board[i][j]=1;
        return true;
     }

     if(isSafe(i,j,N))
     {
        board[i][j]=1;
        if(ratinmaze(i+1,j,N))
        {
            return true;
        }
        else if(ratinmaze(i,j+1,N))
        {
            return true;
        }
        board[i][j]=0;
     }

     return false;
}

int main()
{
     
    
    int N=4;
    if( ratinmaze(0,0,4))
    {
        cout<<"YES"<<endl;
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
        cout<<"NO"<<endl;
    }

return 0;
}