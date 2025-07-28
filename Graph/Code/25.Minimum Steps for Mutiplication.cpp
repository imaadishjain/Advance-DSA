#include<bits/stdc++.h>
using namespace std;


int minimumMultiplications(vector<int>& arr, int start, int end)
    {
        vector<int>dist(100000 ,1e9);
        int n=arr.size();
        queue<pair<int,int>>q;
        
        dist[start]=0;
        
        q.push({start,0});
        
        while(!q.empty())
        {
            int number=q.front().first;
            int steps=q.front().second;
        
            q.pop();
            
            for(int i=0;i<n;i++)
            {
                int ml=(number*arr[i])%100000;
               if( dist[ml]>steps+1)
               {
                   dist[ml]=steps+1;
                   q.push({ml,steps+1});
               }
            }    
        }
        
        
        return dist[end]==1e9?-1:dist[end];
    }