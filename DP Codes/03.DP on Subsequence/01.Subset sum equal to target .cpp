//Link-https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

//Memoization
#include<bits/stdc++.h>
using namespace std;


 bool solve(int n,int sum,vector<int>arr,vector<vector<int>>&dp)
    {

        // Base Condition
         if(sum==0)
         {
             return true;
         }
        if(n==0)
        {
            if(sum==arr[0])
            {
            return true;
            }
            return false;
        }


        if(dp[n][sum]!=-1)
        {
            return dp[n][sum];
        }
        bool notake=solve(n-1,sum,arr,dp);
        bool take=false;
        if(sum>=arr[n])
        {
            take=solve(n-1,sum-arr[n],arr,dp);
        }
        return dp[n][sum]=notake || take;
    }
    bool isSubsetSum(vector<int>arr, int sum)
    {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(n-1,sum,arr,dp);
    }

//Tabulation


bool isSubsetSum(vector<int>arr, int sum)
    {
        int n=arr.size();
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));

        // Base Condition
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        dp[0][arr[0]]=true;

        
        
        for(int i=1;i<n;i++)
        {
         for(int j=0;j<=sum;j++)
         {
            bool notake=dp[i-1][j];
             bool take=false;
            if(j>=arr[i])
             {
            take=dp[i-1][j-arr[i]];
             }
             dp[i][j]=notake || take;
         }
        }
        
        return dp[n-1][sum];
    }