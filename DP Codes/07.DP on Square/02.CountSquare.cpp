//Link-https://leetcode.com/problems/count-square-submatrices-with-all-ones/submissions/1329839811/

#include <bits/stdc++.h>
using namespace std;

int countSquares(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(matrix.begin(), matrix.end());

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (dp[i][j] == 1)
            {
                int mini = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
                dp[i][j] += mini;
            }
        }
    }
    for (auto it1 : dp)
    {
        for (auto it2 : it1)
        {
            ans += it2;
        }
    }

    return ans;
}