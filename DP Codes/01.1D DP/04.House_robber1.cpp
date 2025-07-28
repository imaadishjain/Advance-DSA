// Link-https://leetcode.com/problems/house-robber/

#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(int n, vector<int> nums, vector<int> &dp)
{
    if (n < 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int notake = solve(n - 1, nums, dp);
    int take = nums[n] + solve(n - 2, nums, dp);

    return dp[n] = max(notake, take);
}
int rob(vector<int> &nums)
{

    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return solve(n - 1, nums, dp);
}

// tabulation

int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, -1);

    // for input-[1,2]
    for (int i = 0; i < n; i++)
    {
        dp[i] = nums[i];
    }

    for (int i = 1; i < n; i++)
    {

        int notake = dp[i - 1];
        int take = 0;
        if (i - 2 >= 0)
        {
            take = nums[i] + dp[i - 2];
        }

        dp[i] = max(dp[i], max(notake, take));
    }
    return dp[n - 1];
}