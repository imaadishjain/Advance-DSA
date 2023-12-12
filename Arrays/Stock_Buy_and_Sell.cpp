#include<bits/stdc++.h>
using namespace std;


int maxprofit(int price[], int n)
{
    int profit=0;

    for(int i=0;i<n-1;i++)
    {
         if(price[i]<price[i+1])
        {
            profit+=price[i+1]-price[i];
        }
    }

    return profit;
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

    cout<<"Overall Profit is="<<maxprofit(arr,n);
    return 0;
}