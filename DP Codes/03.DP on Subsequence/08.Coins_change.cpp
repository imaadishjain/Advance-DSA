// Link-https://leetcode.com/problems/coin-change/

#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(int n, int amount, vector<int> &coins, vector<vector<int>> &dp)
{
    if (amount == 0)
    {
        return 0;
    }
    if (n == 0)
    {
        if (amount % coins[0] == 0)
        {
            return amount / coins[0];
        }
        return 1e9;
    }
    if (dp[n][amount] != -1)
    {
        return dp[n][amount];
    }
    int notake = solve(n - 1, amount, coins, dp);
    int take = 1e9;
    if (amount >= coins[n])
    {
        take = 1 + solve(n, amount - coins[n], coins, dp);
    }

    return dp[n][amount] = min(notake, take);
}
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = solve(n - 1, amount, coins, dp);

    if (ans == 1e9)
    {
        return -1;
    }
    return ans;
}

// Tabulation

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
        {
            dp[0][i] = i / coins[0];
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            int notake = dp[i - 1][j];
            int take = 1e9;
            if (j >= coins[i])
            {
                take = 1 + dp[i][j - coins[i]];
            }

            dp[i][j] = min(notake, take);
        }
    }

    int ans = dp[n - 1][amount];

    if (ans == 1e9)
    {
        return -1;
    }
    return ans;
}