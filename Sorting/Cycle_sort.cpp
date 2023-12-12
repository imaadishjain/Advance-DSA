#include<bits/stdc++.h>
using namespace std;


void cycle_sort(int arr[], int n)
{
    for(int cs=0;cs<n-1;cs++)
    {
        int pos=cs;
        int item=arr[cs];
        for(int i=cs+1;i<n;i++)
        {
            if(arr[i]<item)
            {
                pos++;
            }
        }

        swap(arr[pos],item);

        while(pos!=cs)
        {
          pos=cs;

          for(int i=cs+1;i<n;i++)
          {
            if(arr[i]<item)
            {
                pos++;
            }
          }
          swap(item,arr[pos]);
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the size of array=";
    cin>>n;
    int *arr=new int[n];
    cout<<"Enter the pages of books\n";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    cycle_sort(arr,n);

    cout<<"Sorted Array\n";

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}