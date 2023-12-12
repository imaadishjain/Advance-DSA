#include<bits/stdc++.h>
using namespace std;


int peak_element(int arr[], int n)
{
    int low=0;
    int high=n-1;

    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if(mid!=0 && arr[mid-1]>=arr[mid])
        {
            high=mid-1;
        }

        else if(mid!=n-1 && arr[mid]<=arr[mid+1])
        {
            low=mid+1;
        }

        else
        {
            return arr[mid];
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

   cout<<"Peak Element="<<peak_element(arr,n);
    return 0;

}