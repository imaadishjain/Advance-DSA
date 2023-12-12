#include<bits/stdc++.h>
using namespace std;

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

void makefriend(int x, int y)
{
     union_(x,y);
}

bool arefriend(int x, int y)
{
    return (find(x)==find(y));
}

int main()
{
  int n;
  cout<<"Enter the number of operation\n";
  cin>>n;
  parent.resize(n);
  rank1.resize(n);
   
   for(int i=0;i<n;i++)
   {
    parent[i]=i;
    rank1[i]=0;
   }
  
  makefriend(0,1);
  makefriend(1,3);
  cout<<"Friend="<<arefriend(0,2)<<endl;
  cout<<"Friend="<<arefriend(0,1)<<endl;
  cout<<"Friend="<<arefriend(0,3)<<endl;

}


