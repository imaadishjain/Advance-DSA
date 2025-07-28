#include<bits/stdc++.h>
using namespace std;


 int findParent(int x,vector<int>&parent)
    {
        if(x==parent[x])
        {
            return x;
        }
        
        return parent[x]=findParent(parent[x],parent);
    }
    
    void Union(int u, int v, vector<int>&parent,vector<int>&size)
    {
        int pu=findParent(u,parent);
        int pv=findParent(v,parent);
        
        if(pu==pv)
        {
            return;
        }
        if(size[pu]<size[pv])
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else if(size[pu]>size[pv])
        {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else
        {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
    vector<vector<string>> mergeDetails(vector<vector<string>>& details) 
    {
        int n=details.size();
        
        vector<int>parent(n+1);
        vector<int>size(n+1,1);
        
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
        
        
       // sort(details.begin(), details.end());
        unordered_map<string, int>mpp;
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<details[i].size();j++)
            {
                string mails=details[i][j];
                if(mpp.find(mails)==mpp.end())
                {
                    mpp[mails]=i;
                }
                else
                {
                    int u=mpp[mails];
                    Union(u,i,parent,size);
                }
            }
        }
        
        vector<string>vec[n];
        
        
        for(auto it: mpp)
        {
            string mails=it.first;
            int p=parent[it.second];
            vec[p].push_back(mails);
        }
        
       
        
        vector<vector<string>>ans;
        
        for(int i=0;i<n;i++)
        {
            if(vec[i].size()==0)
            {
                continue;
            }
            vector<string>temp;
            sort(vec[i].begin(),vec[i].end());
            
            temp.push_back(details[i][0]);
            
            for(auto it:vec[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }