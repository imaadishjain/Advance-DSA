//Link-https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

//Keeping the maximum pallindromic portion intact
#include<bits/stdc++.h>
using namespace std;

int minInsertions(string s)
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
          
        return s.size()-dp[n][n];
    }

