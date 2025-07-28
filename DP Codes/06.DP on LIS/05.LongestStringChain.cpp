// Link-https://leetcode.com/problems/longest-string-chain/

#include <bits/stdc++.h>
using namespace std;

static bool myCmp(string p, string q)
{
    if (p.length() == q.length())
    {
        return p < q;
    }
    return p.length() < q.length();
}

bool check(string s2, string s1)
{
    int n = s1.length();
    int m = s2.length();
    if (m - n != 1)
    {
        return false;
    }
    int i = 0;
    int j = 0;

    while (i < m && j < n)
    {
        if (s2[i] == s1[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    if ((j == n && i == m - 1) || (j == n && i == m))
    {
        return true;
    }
    return false;
}
int longestStrChain(vector<string> &words)
{
    int n = words.size();

    sort(words.begin(), words.end(), myCmp);
    vector<int> dp(n, 1);
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (check(words[i], words[j]) && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
        if (maxi < dp[i])
        {
            maxi = dp[i];
        }
    }
    return maxi;
}