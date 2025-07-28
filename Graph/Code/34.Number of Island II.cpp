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
        if(size[pv]<size[pu])
        {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
        else if(size[pv]>size[pu])
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else
        {
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
      vector<int>parent(n*m+1);
      vector<int>size(n*m+1,1);
      
      for(int i=0;i<=n*m;i++)
      {
          parent[i]=i;
      }
      
      
      vector<vector<int>>matrix(n,vector<int>(m,0));
      
      vector<int>vec;
      
      int ans=0;
      
      int deltarow[]={-1,0,1,0};
      int deltacol[]={0,1,0,-1};
      
      for(int i=0;i<operators.size();i++)
      {
          int row=operators[i][0];
          int col=operators[i][1];
          
          if(matrix[row][col]==1)
          {
             vec.push_back(ans);
             continue;
          }
          ans+=1;
            matrix[row][col]=1;
          int node=row*m+col;
          for(int g=0;g<4;g++)
          {
              int nr=row+deltarow[g];
              int nc=col+deltacol[g];
              if(nr>=0 && nr<n && nc>=0 && nc<m && matrix[nr][nc]==1)
              {
                int adjNode=nr*m+nc;
                if(findParent(node,parent)!=findParent(adjNode,parent))
                {
                  Union(node,adjNode,parent,size);
                   ans-=1;
                }
              }
          
          }
        
          vec.push_back(ans);
          
      }
      
      return vec;
    }