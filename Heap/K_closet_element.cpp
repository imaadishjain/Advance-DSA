#include<bits/stdc++.h>
using namespace std;

void kcloset(int arr[], int n , int x,int k)
{
    priority_queue<pair<int,int>>pq;

    for(int i=0;i<k;i++)
    {
        pq.push({abs(x-arr[i]),i});
    }

    for(int i=k;i<n;i++)
    {
        auto p=pq.top();
        if(p.first>abs(x-arr[i]))
        {
            pq.pop();
            pq.push({abs(x-arr[i]),i});
        }
    }

    while(!pq.empty())
    {
        auto p=pq.top();
        pq.pop();
        cout<<arr[p.second]<<" ";
    }
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

    int x,k;
    cout<<"Enter the value of x=";
    cin>>x;

    cout<<"Enter the value of k=";
    cin>>k;

    kcloset(arr, n , x, k);
    return 0;

}