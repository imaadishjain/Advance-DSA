#include<bits/stdc++.h>
using namespace std;


int kadnes(int arr[], int n)
{
    int res=arr[0];
    int maxxending=arr[0];

    for(int i=1;i<n;i++)
    {
        maxxending=max(maxxending,maxxending+arr[i]);

        res=max(maxxending,res);
    }

    return res;
}

int maxxsum(int arr[], int n)
{
    int normal_sum=kadnes(arr,n);
    if(normal_sum<0)
    {
        return normal_sum;
    }

    int sum=0;

    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        arr[i]=-arr[i];
    }

    int circular_sum=sum+kadnes(arr,n);

    return max(normal_sum,circular_sum);
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

    cout<<"Maximum Subarray sum of Circular array="<<maxxsum(arr,n);



    return 0;
}