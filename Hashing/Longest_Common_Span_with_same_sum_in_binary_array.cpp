#include<bits/stdc++.h>
using namespace std;


int longestCommonSubarray(int a[], int b[], int n)
{
    for(int i=0;i<n;i++)
    {
        a[i]=a[i]-b[i];
    }
    unordered_map<int,int>mpp;
    int presum=0;
    int res=0;
    for(int i=0;i<n;i++)
    {
        presum+=a[i];

        if(mpp.find(presum)!=mpp.end())
        {
             res=max(res,i-mpp[presum]);
        }
        else
        {
           mpp.insert({presum,i});        
        }
    }

    return res;
}


int main()
{
    cout<<std::boolalpha;
    int n;
    cout<<"Enter the size of arrays=";
    cin>>n;
    int *a=new int[n];
    int *b=new int[n];
    cout<<"Enter the element of first array\n";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the element of second array\n";

    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    cout<<"Longest Common Subarray size="<<longestCommonSubarray(a,b,n);
    return 0;
}