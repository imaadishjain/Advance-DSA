#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(int i, int n, int b, vector<int> &prices, vector<vector<int>> &dp)
{
    if (i == n)
    {
        return 0;
    }
    int buy = 0;
    int sell = 0;
    if (dp[i][b] != -1)
    {
        return dp[i][b];
    }
    int notake = solve(i + 1, n, b, prices, dp);
    if (b)
    {
        buy = solve(i + 1, n, 0, prices, dp) - prices[i];
    }
    else
    {
        sell = prices[i] + solve(i + 1, n, 1, prices, dp);
    }

    return dp[i][b] = max(notake, max(buy, sell));
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solve(0, n, 1, prices, dp);
}

// Tabulation
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= 1; j++)
        {
            int buy = 0;
            int sell = 0;
            int notake = dp[i + 1][j];
            if (j)
            {
                buy = dp[i + 1][0] - prices[i];
            }
            else
            {
                sell = prices[i] + dp[i + 1][1];
            }

            dp[i][j] = max(notake, max(buy, sell));
        }
    }

    return dp[0][1];
}