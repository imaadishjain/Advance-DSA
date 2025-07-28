#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n=grid.size();
	    int m=grid[0].size();
	    
	     vector<vector<int>>ans(n,vector<int>(m,0));
	     
	     vector<vector<bool>>visi(n,vector<bool>(m,0));
	     
	     
	     queue<pair<pair<int,int>,int>>q;
	     
	     
	     for(int i=0;i<n;i++)
	     {
	         for(int j=0;j<m;j++)
	         {
	             if(grid[i][j]==1)
	             {
	                 q.push({{i,j},0});
	                 visi[i][j]=true;
	         
	             }
	         }
	     }
	     
	     while(!q.empty())
	     {
	         int x=q.front().first.first;
	         int y=q.front().first.second;
	         int c=q.front().second;
	       
	         ans[x][y]=c;
	         
	         q.pop();
	         
	         int deltarow[]={1,0,-1,0};
	         int deltacol[]={0,1,0,-1};
	         
	         for(int i=0;i<4;i++)
	         {
	             
	                 int row=x+deltarow[i];
	                 int col=y+deltacol[i];
	                 
	                 if(row>=0 && row<n && col>=0 && col<m && !visi[row][col])
	                 {
	                     visi[row][col]=true;
	                     q.push({{row,col},c+1});
	                 }
	        }
	        }
	     
	     
	     return ans;
	    
	}