#include<bits/stdc++.h>
using namespace std;


int minimumsum(int arr[], int n)
{
    int res=0;
    
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]!=arr[i+1])
        {
            if(arr[i+1]!=arr[0])
            {
               cout<<"From "<<i+1<<" to ";
            }
            else
            {
                cout<<(i)<<endl;
            }
        }
    }

    if(arr[n-1]!=arr[0])
    {
        cout<<(n-1)<<endl;
    }
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

    cout<<"Minimum number of Flips are="<<minimumsum(arr,n);

    return 0;
}