// Link-https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump

#include <bits/stdc++.h>
using namespace std;

// Memoization
int solve(int n, vector<int> height, vector<int> &dp)
{
  // Base Condition
  if (n == 0)
  {
    return 0;
  }
  if (dp[n] != -1)
  {
    return dp[n];
  }
  int one = abs(height[n] - height[n - 1]) + solve(n - 1, height, dp);
  int two = 1e9;
  if (n >= 2)
  {
    two = abs(height[n] - height[n - 2]) + solve(n - 2, height, dp);
  }

  return dp[n] = min(one, two);
}
int minimumEnergy(vector<int> &height, int n)
{
  vector<int> dp(n + 1, -1);
  return solve(n - 1, height, dp);
}

// Tabulation

int minimumEnergy(vector<int> &height, int n)
{
  vector<int> dp(n + 1, -1);
  
  // Base Condition
  dp[0] = 0;
  for (int i = 1; i < n; i++)
  {
    int one = abs(height[i] - height[i - 1]) + dp[i - 1];
    int two = 1e9;
    if (i - 2 >= 0)
    {
      two = abs(height[i] - height[i - 2]) + dp[i - 2];
    }
    dp[i] = min(one, two);
  }
  return dp[n - 1];
}