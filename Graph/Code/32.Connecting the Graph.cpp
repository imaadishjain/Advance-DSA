#include<bits/stdc++.h>
using namespace std;


int findParent(int x, vector<int>&parent)
    {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x]=findParent(parent[x],parent);
    }
    
    void Union(int x, int y,vector<int>&parent,vector<int>&size)
    {
        int px=findParent(x,parent);
        int py=findParent(y,parent);
        
        if(size[py]<size[px])
        {
            parent[py]=px;
            size[px]+=size[py];
        }
        else if(size[py]>size[px])
        {
            parent[px]=py;
            size[py]+=size[px];
        }
        else
        {
            parent[px]=py;
            size[py]+=size[px];
        }
    }
    int Solve(int n, vector<vector<int>>& edge)
    {
        vector<int>parent(n);
        vector<int>size(n);
        
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
        
        int cycle=0;
        
        for(auto it:edge)
        {
            int u=it[0];
            int v=it[1];
            
            if(findParent(u,parent)!=findParent(v,parent))
            {
               Union(u,v,parent,size);
            }
            else
            {
                cycle++;
            }
        }
        int parentboss=-1;
        for(int i=0;i<n;i++)
        {
           
            if(parent[i]==i)
            {
               
                parentboss++;
            }
        }
        return cycle>=parentboss?parentboss:-1;
        
    }