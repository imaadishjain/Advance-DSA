#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(int i, int n, int b, int fee, vector<int> &prices, vector<vector<int>> &dp)
{
    if (i == n)
    {
        return 0;
    }
    int notake = solve(i + 1, n, b, fee, prices, dp);
    int buy = 0;
    int sell = 0;
    if (dp[i][b] != -1)
    {
        return dp[i][b];
    }
    if (b)
    {
        buy = solve(i + 1, n, 0, fee, prices, dp) - prices[i];
    }
    else
    {
        sell = prices[i] + solve(i + 1, n, 1, fee, prices, dp) - fee;
    }

    return dp[i][b] = max(notake, max(buy, sell));
}
int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve(0, n, 1, fee, prices, dp);
}

// Tabulation

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= 1; j++)
        {
            int notake = dp[i + 1][j];
            int buy = 0;
            int sell = 0;
            if (j)
            {
                buy = dp[i + 1][0] - prices[i];
            }
            else
            {
                sell = prices[i] + dp[i + 1][1] - fee;
            }

            dp[i][j] = max(notake, max(buy, sell));
        }
    }

    return dp[0][1];
}