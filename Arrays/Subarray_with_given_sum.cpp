#include<bits/stdc++.h>
using namespace std;


bool subarray(int arr[], int n, int sum)
{
    int s=0;
    int  curr=0;

    for(int e=0;e<n;e++)
    {
        curr+=arr[e];

        while(curr>sum)
        {
            curr-=arr[s];
            s++;
        }

        if(curr==sum)
        {
            return 1;
        }
    }
    return 0;
}


int main()
{
    int n;
    cout<<"Enter the size of array=";
    cin>>n;

    int *arr=new int[n];
    cout<<"Enter the elements\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    int sum;
    cout<<"Enter the value of sum=";
    cin>>sum;
    cout<<std::boolalpha;
    cout<<"Subarray is present with given sum="<<subarray(arr,n,sum);

    return 0;
}