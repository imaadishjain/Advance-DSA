#include<bits/stdc++.h>
using namespace std;

 vector <int> nearlySorted(int arr[], int num, int K)
    {
        vector<int>ans;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<K;i++)
        {
            pq.push(arr[i]);
        }
        for(int i=K;i<num;i++)
        {
            pq.push(arr[i]);
            ans.push_back(pq.top());
            pq.pop();
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }

int main()
{
     int n;
        cout<<"Enter the size of array\n";
        cin>>n;
        cout<<"Enter the elements\n";
        int *arr=new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
    int k;
    cout<<"Enter the value of k\n";
    cin>>k;
  vector<int>ans=nearlySorted(arr,n,k);
     
     cout<<"Sorted array\n";

     for(auto it:ans)
     {
        cout<<it<<" ";
     }

     return 0;
}