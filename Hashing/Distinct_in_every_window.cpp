#include<bits/stdc++.h>
using namespace std;


void countdistinct(int arr[], int n, int k)
{
    unordered_map<int,int>mpp;

    for(int i=0;i<k;i++)
    {
         mpp[arr[i]]++;
    }
    cout<<mpp.size()<<" ";

    for(int i=k;i<n;i++)
    {
      mpp[arr[i]]++;

      if(mpp[arr[i-k]]==1)
      {
        mpp.erase(arr[i-k]);
      }
      else
      {
        mpp[arr[i-k]]--;
      }

      cout<<mpp.size()<<" ";
    }
}


int main()
{
    int n;
    cout<<"Enter the size of array=";
    cin>>n;
    int *arr=new int[n];
    cout<<"Enter the  elememts\n";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

     int k;
     cout<<"Enter the size of window\n";
     cin>>k;

     countdistinct(arr,n,k);

     return 0;
}