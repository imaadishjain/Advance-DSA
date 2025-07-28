// Link-https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=printing-longest-increasing-subsequence

#include <bits/stdc++.h>
using namespace std;

vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
{
    vector<int> dp(n, 1);
    vector<int> hash(n);

    int maxi = 1;
    int lastIndex = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
            {
                hash[i] = j;
                dp[i] = dp[j] + 1;
            }
        }
        if (maxi < dp[i])
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    vector<int> ans(maxi);
    maxi--;
    while (hash[lastIndex] != lastIndex)
    {
        ans[maxi] = arr[lastIndex];
        maxi--;
        lastIndex = hash[lastIndex];
    }
    ans[maxi] = arr[lastIndex];

    return ans;
}