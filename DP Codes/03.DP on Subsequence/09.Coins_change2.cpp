//Link-https://leetcode.com/problems/coin-change-ii/

#include<bits/stdc++.h>
using namespace std;

//Memoization

int solve(int n, int amount,vector<int>&coins,vector<vector<int>>&dp)
    {
        if(amount==0)
        {
            return 1;
        }
        if(n==0)
        {
            if(amount%coins[0]==0)
            {
                return 1;
            }
            return 0;
        }

        if(dp[n][amount]!=-1)
        {
            return dp[n][amount];
        }

        int notake=solve(n-1,amount,coins,dp);
        int take=0;
        if(amount>=coins[n])
        {
            take=solve(n,amount-coins[n],coins,dp);
        }
       
        return dp[n][amount]=notake+take;
    }
    int change(int amount, vector<int>& coins) 
    {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
         return solve(n-1,amount,coins,dp);
    }


//Tabulation


int change(int amount, vector<int>& coins) 
    {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
            {
            dp[0][i]=1;
            }
        }

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
               int notake=dp[i-1][j];
               int take=0;
              if(j>=coins[i])
              {
              take=dp[i][j-coins[i]];
               }
       
               dp[i][j]=notake+take;
            }
        }
         return dp[n-1][amount];
    }
