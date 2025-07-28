
// Link-https://www.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost

#include <bits/stdc++.h>
using namespace std;

// Memoization

int solve(int n, int k, vector<int> height, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans = 1e9;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            ans = min(ans, abs(height[n] - height[n - i]) + solve(n - i, k, height, dp));
        }
    }
    return dp[n] = ans;
}
int minimizeCost(vector<int> &height, int n, int k)
{
    vector<int> dp(n + 1, -1);
    return solve(n - 1, k, height, dp);
}

// Tabulation

int minimizeCost(vector<int> &height, int n, int k)
{
    vector<int> dp(n + 1, -1);

    dp[0] = 0;

    for (int j = 1; j < n; j++)
    {
        int ans = 1e9;
        for (int i = 1; i <= k; i++)
        {
            if (j - i >= 0)
            {
                ans = min(ans, abs(height[j] - height[j - i]) + dp[j - i]);
            }
        }
        dp[j] = ans;
    }
    return dp[n - 1];
}