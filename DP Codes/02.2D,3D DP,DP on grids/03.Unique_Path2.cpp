//Link-https://leetcode.com/problems/unique-paths-ii/description/

#include <bits/stdc++.h>
using namespace std;

// Memoization

int solve(int m, int n, vector<vector<int>> mt, vector<vector<int>> &dp)
{
    // Base Condition
    if (m == 0 && n == 0)
    {
        return 1;
    }
    if (m < 0 || n < 0)
    {
        return 0;
    }


    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    int up = 0;
    int left = 0;
    if (m > 0 && mt[m - 1][n] == 0)
    {
        up = solve(m - 1, n, mt, dp);
    }
    if (n > 0 && mt[m][n - 1] == 0)
    {
        left = solve(m, n - 1, mt, dp);
    }

    return dp[m][n] = left + up;
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    if (obstacleGrid[m - 1][n - 1] == 1)
    {
        return 0;
    }
    return solve(m - 1, n - 1, obstacleGrid, dp);
}

// Tabulation

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    //Base Condition
    dp[0][0] = 1;
    
    if (obstacleGrid[m - 1][n - 1] == 1)
    {
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 0)
            {
                if (i - 1 >= 0 && obstacleGrid[i - 1][j] == 0)
                {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0)
                {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
    }
    return dp[m - 1][n - 1];
}