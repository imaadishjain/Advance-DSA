#include<bits/stdc++.h>
using namespace std;

void boundarytraversal(int **arr,int m ,int n)
{
  if(m==1)
  {
    for(int i=0;i<n;i++)
    {
        cout<<arr[0][i]<<" ";
    }
  }

  else if(n==1)
  {
    for(int i=0;i<m;i++)
    {
        cout<<arr[i][0]<<" ";
    }
  }

  else
  {
    for(int i=0;i<n;i++)
    {
        cout<<arr[0][i]<<" ";
    }

    for(int i=1;i<m;i++)
    {
        cout<<arr[i][n-1]<<" ";
    }

    for(int i=n-2;i>=0;i--)
    {
        cout<<arr[m-1][i]<<" ";
    }

    for(int i=m-2;i>=1;i--)
    {
        cout<<arr[i][0]<<" ";
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
    
    cout<<"Boundary Traversal \n";

    boundarytraversal(arr, m , n);

    return 0;

}