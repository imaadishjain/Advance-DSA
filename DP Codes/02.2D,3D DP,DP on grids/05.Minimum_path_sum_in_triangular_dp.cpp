// Link-https://leetcode.com/problems/triangle/description/

#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(int m, int n, vector<vector<int>> triangle, vector<vector<int>> &dp)
{
    //Base Condition
    if (m == 0 && n == 0)
    {
        return triangle[m][n];
    }
    if (m < 0 || n < 0 || n >= triangle[m].size())
    {
        return 1e9;
    }

    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    int same = triangle[m][n] + solve(m - 1, n, triangle, dp);
    int shift = triangle[m][n] + solve(m - 1, n - 1, triangle, dp);

    return dp[m][n] = min(same, shift);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int m = triangle.size();
    int n = triangle[m - 1].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ans = 1e9;

    for (int i = 0; i < n; i++)
    {
        ans = min(ans, solve(m - 1, i, triangle, dp));
    }
    return ans;
}

// Tabulation

int minimumTotal(vector<vector<int>> &triangle)
{
    int m = triangle.size();
    int n = triangle[m - 1].size();
    vector<vector<int>> dp(m, vector<int>(n, 1e9));
    int ans = 1e9;
    //Base Condition
    dp[0][0] = triangle[0][0];

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {

            dp[i][j] = min(dp[i][j], (triangle[i][j] + dp[i - 1][j]));
            if (j != 0)
            {
                dp[i][j] = min(dp[i][j], (triangle[i][j] + dp[i - 1][j - 1]));
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, dp[m - 1][i]);
    }
    return ans;
}