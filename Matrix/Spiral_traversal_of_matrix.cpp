#include<bits/stdc++.h>
using namespace std;


void spiral(int **arr,int r, int c)
{
    int top=0;
    int left=0;
    int bottom=r-1;
    int right=c-1;

   while(left<=right && top<=bottom)
   {
    for(int i=left;i<=right;i++)
    {
        cout<<arr[top][i]<<" ";
    }
    top++;

    for(int i=top;i<=bottom;i++)
    {
        cout<<arr[i][right]<<" ";
    }
    
     right--;
    

    if(top<=bottom)
    {
        for(int i=right;i>=left;i--)
        {
            cout<<arr[bottom][i]<<" ";
        }
        bottom--;
    }

    if(left<=right)
    {
        for(int i=bottom;i>=top;i--)
        {
            cout<<arr[i][left]<<" ";
        }
        left++;
    }
   }
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
    
    cout<<"Spiral Traversal of a martix\n";

   spiral(arr, m , n);
    return 0;

}
