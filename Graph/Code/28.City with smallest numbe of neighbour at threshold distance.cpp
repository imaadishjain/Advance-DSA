#include<bits/stdc++.h>
using namespace std;







int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold)
    {
    
        vector<vector<int>>matrix(n,vector<int>(n,1e9));
        
        for(int i=0;i<m;i++)
        {
            matrix[edges[i][0]][edges[i][1]]=edges[i][2];
            matrix[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        
        for(int i=0;i<n;i++)
        {
            matrix[i][i]=0;
        }
        
        
        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    matrix[i][j]=min(matrix[i][j],matrix[i][via]+matrix[via][j]);
                }
            }
        }
        
        int ans=-1;
        int o=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int  j=0;j<n;j++)
            {
                if(i!=j && matrix[i][j]<=distanceThreshold)
                {
                    count++;
                }
            }
            if( o>count)
            {
                ans=i;
                o=count;
            }
            else if( o==count)
            {
                ans=max(ans,i);
            }
        }
        
        return ans;
    }