// Link-https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int t;
    int maxi = 0;
    int l = prices.size();
    int mini = prices[0];
    for (int i = 1; i < l; i++)
    {
        maxi = max(maxi, prices[i] - mini);
        mini = min(mini, prices[i]);
    }
    return maxi;
}