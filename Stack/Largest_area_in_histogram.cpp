#include<bits/stdc++.h>
using namespace std;

vector<int> previous_smaller(int arr[],int n)
{
    stack<int>st;
    vector<int>ans;
    
    ans.push_back(-1);
    st.push(0);
    for(int i=1;i<n;i++)
    {
        while(st.empty()==false && arr[i]<=arr[st.top()])
        {
             st.pop();
        }
        st.empty()==true?ans.push_back(-1):ans.push_back(st.top());
       st.push(i);
    }

    return ans;
}

vector<int> next_smaller(int arr[], int n)
{
    stack<int>st;
    vector<int>ans;

    ans.push_back(n);
    st.push(n-1);
    for(int i=n-2;i>=0;i--)
    {
        while(st.empty()==false && arr[i]<=arr[st.top()])
        {
             st.pop();
        }
        st.empty()==true?ans.push_back(n):ans.push_back(st.top());
       st.push(i);
    }

    reverse(ans.begin(),ans.end());

    return ans;
}

int largest_area(int arr[], int n)
{
    vector<int>ps=previous_smaller(arr,n);
    vector<int>ns=next_smaller(arr,n);
    
    int ans=INT_MIN;

    for(int i=0;i<n;i++)
    {
        int curr=arr[i];
        curr+=arr[i]*(i-ps[i]-1);
        curr+=arr[i]*(ns[i]-i-1);
        cout<<curr<<endl;
        ans=max(curr,ans);
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