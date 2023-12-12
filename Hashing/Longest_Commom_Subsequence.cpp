#include<bits/stdc++.h>
using namespace std;


int longestconseq(int arr[], int n)
{
    unordered_set<int>st(arr,arr+n);
    int res=1; 

    for(auto it:st)
    {
        if(st.find(it-1)==st.end())
        {
           int curr=1;
           while(st.find(curr+it)!=st.end())
           {
            curr++;
           }
           res=max(res,curr);
        }
    }
    return res;
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


  cout<<"Longest Consecutive Subsequence is="<<longestconseq(arr,n);


    return 0;
}