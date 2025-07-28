// Link-https://leetcode.com/problems/largest-divisible-subset/
#include <bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> hashed;
    for (int i = 0; i < n; i++)
    {
        hashed.push_back(i);
    }
    sort(nums.begin(), nums.end());
    int lastIndex = 0;
    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j])
            {
                dp[i] = 1 + dp[j];
                hashed[i] = j;
            }
        }
        if (maxi < dp[i])
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int> ans(maxi, 0);
    maxi--;
    while (hashed[lastIndex] != lastIndex)
    {
        ans[maxi] = nums[lastIndex];
        maxi--;
        lastIndex = hashed[lastIndex];
    }
    ans[maxi] = nums[lastIndex];
    return ans;
}