#include<bits/stdc++.h>
using namespace std;


void ceil(int arr[], int n)
{
    set<int>st;

    for(int i=0;i<n;i++)
    {
        auto it=st.lower_bound(arr[i]);

        if(it==st.end())
        {
            cout<<"-1"<<" ";
        }
        else
        {
            cout<<*it<<" ";
        }

        st.insert(arr[i]);
    }
}


int main()
{
    int n;
    cout<<"Enter the size of array\n";
    cin>>n;

    int *arr=new int[n];
    cout<<"Enter the value\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"Ceiling on left\n";
    ceil(arr,n);
    return 0;
}