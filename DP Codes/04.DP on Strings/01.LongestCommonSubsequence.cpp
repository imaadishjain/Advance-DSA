//Link-https://leetcode.com/problems/longest-common-subsequence/

#include<bits/stdc++.h>
using namespace std;



//Memoization

   int solve(int n, int m, string text1,string text2,vector<vector<int>>&dp)
     {
        if(n<0 || m<0)
         {
        return 0;
         }
         if(dp[n][m]!=-1)
         {
            return dp[n][m];
         }
        int match=0;
        int notmatch=0;
        if(text1[n]==text2[m])
        {
            match=1+solve(n-1,m-1,text1,text2,dp);
        }
        else
        {
            notmatch=max(solve(n-1,m,text1,text2,dp),solve(n,m-1,text1,text2,dp));
        }
        return dp[n][m]=max(match,notmatch);
     }
    int longestCommonSubsequence(string text1, string text2) 
    {
         int n=text1.length();
         int m=text2.length();
         vector<vector<int>>dp(n,vector<int>(m,-1));
         return solve(n-1,m-1,text1,text2,dp);
    }


// Tabulation

int longestCommonSubsequence(string text1, string text2) 
    {
         int n=text1.length();
         int m=text2.length();
         vector<vector<int>>dp(n+1,vector<int>(m+1,0));

         for(int i=1;i<=n;i++)
         {
            for(int j=1;j<=m;j++)
            {
              int match=0;
              int notmatch=0;
               if(text1[i-1]==text2[j-1])
                {
                 match=1+dp[i-1][j-1];
                }
               else
                {
                notmatch=max(dp[i-1][j],dp[i][j-1]);
               }
               dp[i][j]=max(match,notmatch);
            }
         }

         return dp[n][m];
    }