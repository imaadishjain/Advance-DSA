//Link-https://leetcode.com/problems/partition-equal-subset-sum/

#include<bits/stdc++.h>
using namespace std;

//Memoization
bool solve(int n, int sum,vector<int>&nums,vector<vector<int>>&dp)
    {
       if(sum==0)
       {
        return true;
       }
       if(n==0)
       {
        return false;
       }
       if(dp[n][sum]!=-1)
       {
        return dp[n][sum];
       }
       bool notake=solve(n-1,sum,nums,dp);
       bool take=false;
       if(sum>=nums[n])
       {
        take=solve(n-1,sum-nums[n],nums,dp);
       }

       return dp[n][sum]=take || notake;
    }
    bool canPartition(vector<int>& nums)
    {
         int n=nums.size();
         int sum=0;
         for(auto it:nums)
         {
            sum+=it;
         }
         if(sum%2!=0)
         {
            return false;
         }
         vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
         return solve(n-1,sum/2,nums,dp);
    }



//Tabulation
     bool canPartition(vector<int>& nums)
    {
         int n=nums.size();
         int sum=0;
         for(auto it:nums)
         {
            sum+=it;
         }
         if(sum%2!=0)
         {
            return false;
         }
         vector<vector<bool>>dp(n,vector<bool>(sum/2+1,false));
         for(int i=0;i<n;i++)
         {
            dp[i][0]=1;
         }

         
         for(int i=1;i<n;i++)
         {
            for(int j=0;j<=sum/2;j++)
            {
                 bool notake=dp[i-1][j];
                 bool take=false;
              if(j>=nums[i])
               {
                 take=dp[i-1][j-nums[i]];
               }
                dp[i][j]=take || notake;
            }
         }

         return dp[n-1][sum/2];
    }