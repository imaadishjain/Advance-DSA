//Link-https://leetcode.com/problems/wildcard-matching/

#include<bits/stdc++.h>
using namespace std;

 //Memoization
  bool solve(int n, int m, string s,string p,vector<vector<int>>&dp)
   {
      if(n<0 && m<0)
      {
        return true;
      }
      if(n<0 &&  m==0 && p[0]=='*')
      {
        return true;
      }
     if(n<0 ||m<0)
     {
       return false;     
     }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }    
    if(p[m]!='*' && p[m]!='?' && s[n]!=p[m])
    {
            return false;
    }
    if(p[m]=='*')
    {
        return dp[n][m]=solve(n-1,m,s,p,dp) || solve(n,m-1,s,p,dp);
    }
    else
    {
        return dp[n][m]=solve(n-1,m-1,s,p,dp);
    }

   }
    bool isMatch(string s, string p) 
    {
        if(s==p)
        {
            return true;
        }
        int n=s.size();
        int m=p.size();
        string mp;
        mp+=p[0];
        
        for(int i=1;i<m;i++)
        {  
            if(p[i]=='*' && p[i-1]!='*')
            {  
                mp+=p[i];
            }
            else if(p[i]!='*')
            {
                mp+=p[i];
            }
        }

        int si=mp.size();
        vector<vector<int>>dp(n,vector<int>(si,-1));
        return solve(n-1,si-1,s,mp,dp);
    }



//Tabulation

 bool isMatch(string s, string p) 
    {
        if(s==p)
        {
            return true;
        }
        int n=s.size();
        int m=p.size();
        string mp;
        mp+=p[0];
        
        for(int i=1;i<m;i++)
        {  
            if(p[i]=='*' && p[i-1]!='*')
            {  
                mp+=p[i];
            }
            else if(p[i]!='*')
            {
                mp+=p[i];
            }
        }

        int si=mp.size();
        vector<vector<int>>dp(n+1,vector<int>(si+1,false));

        if(mp[0]=='*')
        {
            dp[0][1]=true;
        }
        if(mp[0]=='*' || mp[0]=='?' || mp[0]==s[0])
        {
            dp[0][0]=true;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=si;j++)
            {
                if(mp[j-1]=='*')
                {
                 dp[i][j]=dp[i-1][j] || dp[i][j-1];
                }
                else if(mp[j-1]=='?' || mp[j-1]==s[i-1])
                {
                 dp[i][j]=dp[i-1][j-1];
                }
            }
        }
        return dp[n][si];
    }

