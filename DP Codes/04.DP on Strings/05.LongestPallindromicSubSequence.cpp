//Link-https://leetcode.com/problems/longest-palindromic-subsequence/

#include<bits/stdc++.h>
using namespace std;

//Memoization
int solve(int n, int m, string s,string r,vector<vector<int>>&dp)
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

        if(s[n]==r[m])
        {
            match=1+solve(n-1,m-1,s,r,dp);
        }
        else
        {
            notmatch=max(solve(n-1,m,s,r,dp),solve(n,m-1,s,r,dp));
        }
        return dp[n][m]=max(match,notmatch);
    }
    int longestPalindromeSubseq(string s)
    {
        int n=s.length();
        string r=s;
        reverse(r.begin(),r.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        return solve(n-1,n-1,s,r,dp);
    }

 //Tabulation

 int longestPalindromeSubseq(string s)
    {
        int n=s.length();
        string r=s;
        reverse(r.begin(),r.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int match=0;
                int notmatch=0;

              if(s[i-1]==r[j-1])
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
          
        return dp[n][n];
    }