// Link-https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training

#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(int n, int p, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    //Base Condition
    if (n < 0)
    {
        return 0;
    }

    if (dp[n][p] != -1)
    {
        return dp[n][p];
    }
    int ans = 0;
    for (int j = 1; j <= 3; j++)
    {
        if (j != p)
        {
            ans = max(ans, points[n][j - 1] + solve(n - 1, j, points, dp));
        }
    }

    return dp[n][p] = ans;
}
int maximumPoints(vector<vector<int>> &points, int n)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(n - 1, 0, points, dp);
}

// tabulation

int maximumPoints(vector<vector<int>> &points, int n)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));

    //Base Conditions
    dp[0][1] = points[0][0];
    dp[0][2] = points[0][1];
    dp[0][3] = points[0][2];

    for (int i = 1; i < n; i++)
    {

        for (int p = 1; p <= 3; p++)
        {
            int ans = 0;
            for (int j = 1; j <= 3; j++)
            {
                if (j != p)
                {
                    ans = max(ans, points[i][p - 1] + dp[i - 1][j]);
                }
            }

            dp[i][p] = ans;
        }
    }
    int ansi = 0;
    for (int i = 1; i <= 3; i++)
    {
        ansi = max(ansi, dp[n - 1][i]);
    }

    return ansi;
}