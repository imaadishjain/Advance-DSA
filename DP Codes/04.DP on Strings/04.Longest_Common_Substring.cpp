//Link-https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

#include<bits/stdc++.h>
using namespace std;


int longestCommonSubstr (string s, string t, int n, int m)
    {
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=m;j++)
           {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
           }
       }
       int ans=0;
       for(auto it1:dp)
       {
           for(auto it2:it1)
           {
               ans=max(ans,it2);
           }
       }
       
       return ans;
    }