#include<bits/stdc++.h>
using namespace std;


int searchinfinite(int arr[],int x)
{
    if(arr[0]==x)
    {
        return x;
    }
    int i=1;
    while(arr[i]<x)
    {
        i*=2;
    }
   
   if(arr[i]==x)
   {
    return i;
   }
   
   return binary_search(arr+i/2+1,arr+i,x);
}
int main()
{
    int n;
    cout<<"Enter the size of array=";
    cin>>n;
    int *arr=new int[1002];
    cout<<"Enter the element in sorted order\n";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int x;
    cout<<"Enter the elemente to be  find=";
    cin>>x;

    cout<<"Element"<<searchinfinite(arr,x);

    return 0;

}