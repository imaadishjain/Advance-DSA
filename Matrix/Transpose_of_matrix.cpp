#include<bits/stdc++.h>
using namespace std;

void print(int **arr, int r, int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
           cout<<arr[i][j]<<" ";
        }

        cout<<endl;
    }
}
void transpose(int **arr, int r, int c)
{
    int m=1;
    for(int i=0;i<r;i++)
    {
        for(int j=m;j<c;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
        m++;
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
    
    cout<<"Transpose of a martix \n";

   transpose(arr, m , n);

   print(arr,m,n);

    return 0;

}