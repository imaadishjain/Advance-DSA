#include<bits/stdc++.h>
using namespace std;



 // Disjoint set by rank

 int parent(int x,int par[])
    {
        if(par[x]==x)
        {
            return x;
        }
        
        return par[x]=parent(par[x],par);
    }
    void union_( int a, int b, int par[], int rank[]) 
    {
        int pa=parent(a,par);
        int pb=parent(b,par);
        
        if(pa==pb)
        {
            return;
        }
        
        if(rank[pa]<rank[pb])
        {
            par[pa]=pb;
        }
        else if(rank[pa]>rank[pb])
        {
            par[pb]=pa;
        }
        else
        {
            par[pb]=pa;
            rank[pa]++;
        }
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int rank1[])
    {
        return parent(x,par)==parent(y,par);
    }




    //Disjoint set by size






      int parent(int x,int par[])
    {
        if(par[x]==x)
        {
            return x;
        }
        
        return par[x]=parent(par[x],par);
    }
    void union_( int a, int b, int par[], int size[]) 
    {
        int pa=parent(a,par);
        int pb=parent(b,par);
        
        if(pa==pb)
        {
            return;
        }
        
        if(size[pa]<size[pb])
        {
            par[pa]=pb;
            size[pb]=size[pb]+size[pa];
        }
        else if(size[pa]>size[pb])
        {
            par[pb]=pa;
             size[pa]=size[pa]+size[pb];
        }
        else
        {
            par[pb]=pa;
            size[pa]=size[pa]+size[pb];
        }
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int size[])
    {
        return parent(x,par)==parent(y,par);
    }