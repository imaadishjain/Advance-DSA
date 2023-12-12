#include<bits/stdc++.h>
using namespace std;


int maxlength(int arr[], int n)
{
    int curr=1;
    int ans=1;

    for(int i=0;i<n-1;i++)
    {
        if((arr[i]%2==0 && arr[i+1]%2!=0 ) || (arr[i]%2!=0 && arr[i+1]%2==0))
        {
           curr++;
           ans=max(ans,curr);
        }
        else
        {
            curr=1;
        }
    }

    return ans;
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

    cout<<"Maximum Subarray with Consecutive Even Odd(vice versa) are="<<maxlength(arr,n);

    return 0;
}