#include<bits/stdc++.h>
using namespace std;


int largest_area(int arr[],int n)
{
    stack<int>st;

    int ans=INT_MIN;

    for(int i=0;i<n;i++)
    {
        while(!st.empty() &&  arr[st.top()]>=arr[i])
        {
            int tp=st.top();
            st.pop();
            int res=arr[tp]*(st.empty()?i:(i-st.top()-1));
            ans=max(res,ans);
        }
    st.push(i);
    }

    while(!st.empty())
    {
        int tp=st.top();
        st.pop();

        int res=arr[tp]*(st.empty()?n:(n-st.top()-1));
        ans=max(res,ans);
    }

    return ans;
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

    cout<<"Largest area of Histogram="<<largest_area(arr,n);

    return 0;
}