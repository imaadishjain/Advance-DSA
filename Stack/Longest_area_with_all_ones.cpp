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


int longest_area(int **mat, int n)
{
    int *arr=new int[n];
    fill(arr,arr+n,0);
    
    int ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]==0)
            {
                arr[j]=0;
            }
            else
            {
                arr[j]++;
            }
        }
       ans=max(ans,largest_area(arr,n));
    }

    return ans;
}

int main()
{
   int n;
    int m;
    cout<<"Enter  the row=";
    cin>>m;
    
    cout<<"Enter  the coloumn=";
    cin>>n;

    int **arr;
    arr=new int*[m];

    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
    }
    cout<<"Enter the elements\n";


    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    } 
    
   
   cout<<"Longest area with all ones="<<longest_area(arr,n);

   return 0;
}