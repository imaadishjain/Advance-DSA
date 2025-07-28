//Link-https://leetcode.com/problems/assign-cookies/

#include<bits/stdc++.h>
using namespace std;


int findContentChildren(vector<int>& g, vector<int>& s)
    {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int i=g.size()-1;
        int j=s.size()-1;
        int ans=0;
        while(i>=0 && j>=0)
        {
            if(g[i]>s[j])
            {
               i--;
            }
            else
            {
               ans++;
               i--;j--;
            }
        }
        return ans;
    }