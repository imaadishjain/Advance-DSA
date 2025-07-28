//Link-https://leetcode.com/problems/house-robber-ii/


#include<bits/stdc++.h>
using namespace std;


int solve(int s,int e,vector<int>&nums)
    {
        vector<int>dp(e+1,-1);
        for(int i=s;i<=e;i++)
        {
            dp[i]=nums[i];
        }
        for(int i=1;i<=e;i++)
        {

            int notake=dp[i-1];
            int take=0;
            if(i-2>=0)
            {
             take=nums[i]+dp[i-2];
            }

               dp[i]=max(dp[i],max(notake,take));
        }
        return dp[e];
    }
    int rob(vector<int>& nums)
    {
        int n=nums.size();
         if(n==1)
         {
            return nums[0];
         }
        return max(solve(0,n-2,nums),solve(1,n-1,nums));
    }