// Link-https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-increasing-subsequence

#include <bits/stdc++.h>
using namespace std;

int longestSubsequence(int n, int a[])
{
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(ans.begin(), ans.end(), a[i]);

        if (it == ans.end())
        {
            ans.push_back(a[i]);
        }
        else
        {
            int index = it - ans.begin();
            ans[index] = a[i];
        }
    }
    return ans.size();
}