#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)  
    { 
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        
        if(left<n && arr[left]>arr[largest])
        {
            largest=left;
        }
        if(right<n && arr[right]>arr[largest])
        {
           largest=right;
        }
        if(largest!=i)
        {
            swap(arr[i],arr[largest]);
            heapify(arr,n,largest);
        }
    }

    void buildHeap(int arr[], int n)  
    { 
     for(int i=(n-2)/2;i>=0;i--)
     {
        heapify(arr,n,i);
     }
    }

    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
        for(int i=n-1;i>=1;i--)
        {
            swap(arr[i],arr[0]);
            heapify(arr,i,0);
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
       
       cout<<"Heap sort\n";

       heapSort(arr,n);

      for(int i=0;i<n;i++)
      {
        cout<<arr[i]<<" ";
      }
      return 0;
    }