//Link-https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-all-lcs-sequences

#include<bits/stdc++.h>
using namespace std;



void making(int i, int j,string s,string t,string str,set<string>&st,vector<vector<int>>&dp)
    {
        if(i==0 || j==0)
        {
              reverse(str.begin(),str.end());
             st.insert(str);
            return;
        }
        if(s[i-1]==t[j-1])
        {
            making(i-1,j-1,s,t,str+t[j-1],st,dp);
        }
        else if(dp[i-1][j]==dp[i][j-1])
        {
            making(i-1,j,s,t,str,st,dp);
            making(i,j-1,s,t,str,st,dp);
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
             making(i-1,j,s,t,str,st,dp);
        }
        else
        {
             making(i,j-1,s,t,str,st,dp);
        }
    }
    vector<string> all_longest_common_subsequences(string s, string t)
    {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int notmatch=0;
                  int match=0;
                if(s[i-1]==t[j-1])
               {
                  match=1+dp[i-1][j-1];
               }
               else
               {
                notmatch=max(dp[i][j-1],dp[i-1][j]);
                }
        
             dp[i][j]=max(match,notmatch);
            }
        }
        set<string>vec;
        making(n,m,s,t,"",vec,dp);
        
        vector<string>ans(vec.begin(),vec.end());
        
         
        return ans;
    }