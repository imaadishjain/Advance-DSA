#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(int i, int n, int prev, vector<int> &num, vector<vector<int>> &dp)
{
    if (i == n)
    {
        return 0;
    }
    if (dp[i][prev + 1] != -1)
    {
        return dp[i][prev + 1];
    }
    int notake = solve(i + 1, n, prev, num, dp);
    int take = 0;
    if (prev == -1 || num[prev] < num[i])
    {
        take = 1 + solve(i + 1, n, i, num, dp);
    }
    return dp[i][prev + 1] = max(take, notake);
}
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solve(0, n, -1, nums, dp);
}

// Tabulation

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = i - 1; prev >= -1; prev--)
        {
            int notake = dp[i + 1][prev + 1];
            int take = 0;
            if (prev == -1 || nums[prev] < nums[i])
            {
                take = 1 + dp[i + 1][i + 1];
            }
            dp[i][prev + 1] = max(take, notake);
        }
    }
    return dp[0][-1 + 1];
}

// Effective Solution use for tracing

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    int ansi = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        ansi = max(ansi, dp[i]);
    }

    return ansi;
}