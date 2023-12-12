#include<bits/stdc++.h>
using namespace std;


int subset(int arr[], int n, int sum)
{
    if(n==0)
    {
        return sum==0?1:0;
    }

    return subset(arr,n-1,sum)+subarray(arr,n-1,sum-arr[n-1]);
}

int main()
{
    int n;
    cout<<"Enter the size of array=";
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

  int sum;
  cout<<"Enter the value of sum=";
  cin>>sum;

    cout<<"Total number of subset with given sum="<<subset(arr,n,sum);
    return 0; 
}
