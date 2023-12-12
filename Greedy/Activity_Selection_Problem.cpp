#include<bits/stdc++.h>
using namespace std;

 static bool myCmp(pair<int,int>p1,pair<int,int>p2)
    {
        if(p1.second==p2.second)
        {
            return p1.first<p2.first;
        }
        return p1.second<p2.second;
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        pair<int,int>p[n];
        
        for(int i=0;i<n;i++)
        {
            p[i].first=start[i];
            p[i].second=end[i];
        }
        
     sort(p,p+n,myCmp);
     
     int res=1;
     int prev=0;
     
     for(int i=1;i<n;i++)
     {
         if(p[i].first>p[prev].second)
         {
             res++;
             prev=i;
         }
     }
        
        return res;
    }

int main()
{
    int n;
    cout<<"Enter the total number of activites\n";
    cin>>n;

    vector<int>start(n);
    vector<int>end(n);
     
    cout<<"Enter the start and end time of activites\n";

    for(int i=0;i<n;i++)
    {
        cin>>start[i];
        cin>>end[i];
    }
    
    cout<<"Total number of activities="<<activitySelection(start,  end,  n);
    return 0;
}