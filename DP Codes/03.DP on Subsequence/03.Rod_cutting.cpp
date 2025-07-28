// Link-https://www.geeksforgeeks.org/problems/rod-cutting0840/1

#include <bits/stdc++.h>
using namespace std;

int solve(int n, int prices[], vector<int> &dp)
{
    if (n == 1)
    {
        return prices[n - 1];
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans = prices[n - 1];
    for (int i = 1; i <= n / 2; i++)
    {
        int left = max(prices[i - 1], solve(i, prices, dp));
        int right = max(prices[n - i - 1], solve(n - i, prices, dp));
        ans = max(ans, left + right);
    }

    return dp[n] = ans;
}

int cutRod(int price[], int n)
{
    vector<int> dp(n + 1, -1);
    return solve(n, price, dp);
}


// Tabulation

int cutRod(int price[], int n)
{
    vector<int> dp(n + 1, 0);

    dp[1] = price[0];

    for (int i = 2; i <= n; i++)
    {
        int ans = price[i - 1];
        for (int j = 1; j <= i / 2; j++)
        {
            int left = max(price[j - 1], dp[j]);
            int right = max(price[i - j - 1], dp[i - j]);
            ans = max(ans, left + right);
        }
        dp[i] = ans;
    }
    return dp[n];
}
