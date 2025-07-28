//Link-https://leetcode.com/problems/minimum-falling-path-sum/


#include<bits/stdc++.h>
using namespace std;



 int solve(int m, int n, vector<vector<int>>matrix,vector<vector<int>>&dp)
    {
        //Base Condition
        if(m<0 || n<0 || n>=matrix[0].size())
        {
            return 1e9;
        }
        if(m==0)
        {
            return matrix[m][n];
        }

        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        int up=matrix[m][n]+solve(m-1,n,matrix,dp);
        int leftup=matrix[m][n]+solve(m-1,n-1,matrix,dp);
        int rightup=matrix[m][n]+solve(m-1,n+1,matrix,dp);

        return dp[n][m]=min(up,min(leftup,rightup));

    }
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=1e9;

        vector<vector<int>>dp(m,vector<int>(n,-1));

        for(int i=0;i<n;i++)
        {
             ans=min(ans,solve(m-1,i,matrix,dp));
        }
       return ans;

    }



  //  Tabulation

    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=1e9;

        vector<vector<int>>dp(m,vector<int>(n,-1));

        // Base Condition
        for(int i=0;i<n;i++)
        {
            dp[0][i]=matrix[0][i];
        }


        for(int i=1;i<m;i++)
       {
         for(int j=0;j<n;j++)
         {
            int up=matrix[i][j]+dp[i-1][j];
            int leftup=1e9;
            if(j-1>=0)
            {
              leftup=matrix[i][j]+dp[i-1][j-1];
            }
            int rightup=1e9;
            if(j+1<n)
            {
                rightup=matrix[i][j]+dp[i-1][j+1];
            }
            dp[i][j]=min(up,min(leftup,rightup));
         }
       }
       
       for(int i=0;i<n;i++)
       {
        ans=min(ans,dp[m-1][i]);
       }
       return ans;

    }