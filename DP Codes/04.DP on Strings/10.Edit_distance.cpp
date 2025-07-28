#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(int n, int m, string w1, string w2, vector<vector<int>> &dp)
{
    if (n < 0)
    {
        return m + 1;
    }
    if (m < 0)
    {
        return n + 1;
    }

    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }

    int match = 1e9;
    int notmatch = 1 + solve(n - 1, m, w1, w2, dp);
    if (w1[n] == w2[m])
    {
        match = solve(n - 1, m - 1, w1, w2, dp);
    }
    else
    {
        notmatch = min(notmatch, 1 + solve(n - 1, m - 1, w1, w2, dp));
        notmatch = min(notmatch, 1 + solve(n, m - 1, w1, w2, dp));
    }

    return dp[n][m] = min(match, notmatch);
}
int minDistance(string word1, string word2)
{
    int n = word1.length();
    int m = word2.length();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(m - 1, n - 1, word2, word1, dp);
}
