#include<bits/stdc++.h>
using namespace std;


int searchrotated(int arr[], int n , int x)
{
    int low=0;
    int high=n-1;

    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if( arr[mid]==x)
        {
            return mid;
        }
        else if(arr[mid]>arr[low])
        {
            if(x>=arr[low] && arr[mid]>x)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        else
        {
            if(arr[mid]<x && x<=arr[high])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
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
    cout<<"Enter the element\n";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int x;
    cout<<"Enter the element  to be find=";
    cin>>x;

    cout<<"Element="<<searchrotated(arr,n,x);

    return 0;

}