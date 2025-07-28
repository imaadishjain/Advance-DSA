// Link-https://leetcode.com/problems/climbing-stairs/description/
#include <bits/stdc++.h>
using namespace std;

// Memoization

int solve(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int one=solve(n-1,dp);
    int two=0;
    if(n-2>=0)
    {
        two=solve(n-2,dp);
    }
    return dp[n] =one+two;
}
int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}




// Tabulation

int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);

    // Base Condition
    dp[0] = 1;


    for (int i =1; i <= n; i++)
    {
        int one=dp[i-1];
        int two=0;
        if(i-2>=0)
        {
            two=dp[i-2];
        }
        dp[i] =one+two;
    }

    return dp[n];
}
