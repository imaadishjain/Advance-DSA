#include<bits/stdc++.h>
using namespace std;


bool checkdivide(int arr[], int n)
{
    int res=0;
    
    for(int i=0;i<n;i++)
    {
        res+=arr[i];
    }

    if(res%3!=0)
    {
        return 0;
    }
    
    int curr=0;
    for(int i=0;i<n;i++)
    {
        curr+=arr[i];
        
        if(curr==res/3)
        {
            curr=0;
        }
    }

    if(curr==0)
    {
        return 1;
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

   cout<<std::boolalpha;


   cout<<"Is array is divided into  three  subarray of equal sum="<<checkdivide(arr,n);

    return 0;
}