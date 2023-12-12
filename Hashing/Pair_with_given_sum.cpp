#include<bits/stdc++.h>
using namespace std;

bool pair_sum(int arr[], int n, int sum)
{
    unordered_set<int>st;
    for(int i=0;i<n;i++)
    {
        if(st.find(sum-arr[i])!=st.end())
        {
            return 1;
        }
        else
        {
            st.insert(arr[i]);
        }
    }

    return 0;
}


int main()
{
    cout<<std::boolalpha;
    int n;
    cout<<"Enter the size of array=";
    cin>>n;

    int *arr=new int[n];


    cout<<"Enter the element\n";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int sum;

    cout<<"Enter the sum=";
    cin>>sum;

    cout<<"Pair is present="<<pair_sum(arr,n,sum);


    return 0;
}