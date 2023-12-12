#include<bits/stdc++.h>
using namespace std;


int lastOccu(int arr[], int n, int x)
{
    int low=0;
    int high=n-1;

    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if(arr[mid]>x)
        {
            high=mid-1;
        }
        else if(arr[mid]<x)
        {
            low=mid+1;
        }
        else
        {
            if(mid==n-1 || arr[mid+1]!=x)
            {
                return mid;
            }
            else
            {
                low=mid+1;
            }
        }
    }

    return -1;
}


int main()
{
    int n;
    cout<<"Enter the size of array=";
    cin>>n;
    int *arr=new int[n];
    cout<<"Enter the element in sorted order\n";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int x;
    cout<<"Enter the element whoes last Ocuurence have to find=";
    cin>>x;

    cout<<"Last Occurence of Element="<<lastOccu(arr,n,x);

    return 0;

}