// Link-https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem

#include <bits/stdc++.h>
using namespace std;

// Memoization

int mod = 1e9 + 7;
int solve(int n, int sum, int arr[], vector<vector<int>> &dp)
{
	// Base Condition
	if (n == 0)
	{
		if (sum == arr[0])
		{
			if (arr[0] == 0)
			{
				return 2;
			}
			return 1;
		}
		if (sum == 0)
		{
			return 1;
		}
		return 0;
	}

	if (dp[n][sum] != -1)
	{
		return dp[n][sum];
	}
	int notake = solve(n - 1, sum, arr, dp);
	int take = 0;
	if (sum >= arr[n])
	{
		take = solve(n - 1, sum - arr[n], arr, dp);
	}

	return dp[n][sum] = (take % mod + notake % mod) % mod;
}
int perfectSum(int arr[], int n, int sum)
{
	vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
	return solve(n - 1, sum, arr, dp);
}

// Tabulation

int perfectSum(int arr[], int n, int sum)
{
	if (n == 1)
	{
		if (arr[0] == sum)
		{
			return 1;
		}
		return 0;
	}
	vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

	// Base Condition
	if (arr[0] <= sum)
	{
		dp[0][arr[0]] = 1;
	}
	dp[0][0] = 1;
	if (arr[0] == 0)
	{
		dp[0][0] = 2;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			int notake = dp[i - 1][j];
			int take = 0;
			if (j >= arr[i])
			{
				take = dp[i - 1][j - arr[i]];
			}
			dp[i][j] = (take % mod + notake % mod) % mod;
		}
	}
	return dp[n - 1][sum];
}
