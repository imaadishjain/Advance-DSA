//Link-https://leetcode.com/problems/unique-paths/submissions/1319425934/



#include<bits/stdc++.h>
using namespace std;

//Memoization
int solve(int i,int j,int m,int n,vector<vector<int>>&dp)
    {

        // Base Condition
        if(i==0 && j==0)
        {
            return 1;
        }
        if(i>m || i<0 || j<0 || j>n )
        {
            return 0;
        }


        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int down=solve(i-1,j,m,n,dp);
        int right=solve(i,j-1,m,n,dp);

        return dp[i][j]=down+right;

    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,m,n,dp);
    }



//Tabulation

int uniquePaths(int m, int n)
    {
        vector<vector<int>>dp(m,vector<int>(n,0));

        // Base Condition
        dp[0][0]=1;
        
        for(int i=0;i<m;i++)
        {
           
            for(int j=0;j<n;j++)
            {
                if(i-1>=0)
                {
                  dp[i][j]+=dp[i-1][j];
                }
                if(j-1>=0)
                {
                 dp[i][j]+=dp[i][j-1];
                }
            }

        }
        return dp[m-1][n-1];
    }