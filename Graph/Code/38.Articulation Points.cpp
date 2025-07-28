#include<bits/stdc++.h>
using namespace std;

  int timer=0;
      
      void dfs(int node,int parent,int tn[], int low[],vector<int>&visi,vector<int>&mark,vector<int>adj[])
      {
          visi[node]=1;
          tn[node]=low[node]=timer;
          timer++;
          int child=0;
          for(auto it: adj[node])
          {
              if(!visi[it])
              {
                  dfs(it,node,tn,low,visi,mark,adj);
                  low[node]=min(low[node],low[it]);
                  if(low[it]>=tn[node] && parent!=-1)
                  {
                      mark[node]=1;
                  }
                  child++;
              }
              else
              {
                 low[node]=min(low[node],tn[it]); 
              }
          }
          if(child>1 &&parent==-1)
          {
              mark[0]=1;
          }
      }
    vector<int> articulationPoints(int n, vector<int>adj[])
    {
        int tn[n];
        int low[n];
        vector<int>ans;
        vector<int>mark(n,0);
        vector<int>visi(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!visi[i])
            {
                dfs(i,-1,tn,low,visi,mark,adj);
            }
          
        }
        
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(mark[i]==1)
            {
                ans.push_back(i);
            }
        }
        if(ans.size()==0)
        {
            ans.push_back(-1);
        }
        return ans;

    }