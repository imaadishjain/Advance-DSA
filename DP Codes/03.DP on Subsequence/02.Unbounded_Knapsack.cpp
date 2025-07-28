
// Link-https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=knapsack-with-duplicate-items

#include <bits/stdc++.h>
using namespace std;

int solve(int n, int w, int val[], int wt[], vector<vector<int>> &dp)
{
    if (n == 0)
    {
        if (w >= wt[0])
        {
            return val[0] * (w / wt[0]);
        }
        return 0;
    }
    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }
    int notake = solve(n - 1, w, val, wt, dp);
    int take = 0;
    int repeat = 0;
    if (w >= wt[n])
    {
        take = val[n] + solve(n - 1, w - wt[n], val, wt, dp);
        repeat = val[n] + solve(n, w - wt[n], val, wt, dp);
    }

    return dp[n][w] = max(notake, max(take, repeat));
}
int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(N, vector<int>(W + 1, -1));
    return solve(N - 1, W, val, wt, dp);
}

// Tabulation

int knapSack(int N, int W, int val[], int wt[])
{
    vector<vector<int>> dp(N, vector<int>(W + 1, 0));
    
    // Base Condition.
    for (int i = 0; i <= W; i++)
    {
        dp[0][i] = val[0] * (i / wt[0]);
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            int notake = dp[i - 1][j];
            int take = 0;
            int repeat = 0;
            if (j >= wt[i])
            {
                take = val[i] + dp[i - 1][j - wt[i]];
                repeat = val[i] + dp[i][j - wt[i]];
            }

            dp[i][j] = max(notake, max(take, repeat));
        }
    }

    return dp[N - 1][W];
}