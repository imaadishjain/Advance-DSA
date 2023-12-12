#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int s;
    int d;
    int w;
};

vector<int>parent;
vector<int>rank1;

int find(int x)
{
    if(parent[x]==x)
    {
        return x;
    }

    return  parent[x]=find(parent[x]);
}

void union_(int x, int y)
{
    int x_resp=find(x);
    int y_resp=find(y);

    if(x_resp==y_resp)
    {
        return;
    }
    if(rank1[x_resp]<rank1[y_resp])
    {
        parent[x_resp]=y_resp;
    }
    else if(rank1[y_resp]<rank1[x_resp])
    {
        parent[y_resp]=x_resp;
    }
    else
    {
        parent[x_resp]=y_resp;
        rank1[y_resp]++;
    }
}
bool myCmp(Edge e1, Edge e2)
{
    return e1.w<e2.w;
}
int main()
{
    int n;
    cout<<"Enter the total number of Edges\n";
    cin>>n;
    int v;
    cout<<"Enter the total number of Vertices\n";
    cin>>v;

    parent.resize(v);
    rank1.resize(v);
    for(int i=0;i<v;i++)
    {
        parent[i]=i;
        rank1[i]=0;
    }
    Edge arr[n];

    for(int i=0;i<n;i++)
    {
        int s,d,w;
        cout<<"Enter the source,Destination and Weigth\n";
        cin>>s;cin>>d;cin>>w;

        arr[i].s=s;
        arr[i].d=d;
        arr[i].w=w;
    }

    sort(arr,arr+n,myCmp);
    int ans=0;
    
    for(int i=0,s=0;s<v-1;i++)
    {
      Edge e=arr[i];
      int src=find(e.s);
      int dest=find(e.d);
      if(src!=dest)
      {
        ans+=e.w;
        union_(e.s,e.d);
        s++;
      }
    }
    cout<<"Minumum Cost is="<<ans<<endl;

    return 0;
}


