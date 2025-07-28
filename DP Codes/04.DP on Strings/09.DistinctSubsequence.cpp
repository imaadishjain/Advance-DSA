//Link-https://leetcode.com/problems/distinct-subsequences/

#include<bits/stdc++.h>
using namespace std;

//Memoization
 int solve(int n, int m,string s, string t,vector<vector<int>>&dp)
    {
        if(m<0)
        {
            return 1;
        }
        if(n<0)
        {
            return 0;
        }
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        int match=0;
        int notake=solve(n-1,m,s,t,dp);
        if(s[n]==t[m])
        {
            match=solve(n-1,m-1,s,t,dp);
        }
        return dp[n][m]=(match+notake);
    }
    int numDistinct(string s, string t)
    {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s,t,dp);
    }

//Tabulation


 int mod=1e9+7;
    int numDistinct(string s, string t)
    {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++)
        {
           for(int j=1;j<=m;j++)
            {
                int  match=0;
                int  notake=dp[i-1][j];
                if(s[i-1]==t[j-1])
                {
                 match=dp[i-1][j-1];
                }
               dp[i][j]=((match)%mod+(notake)%mod)%mod;
            }
        }
        return dp[n][m];
    }

