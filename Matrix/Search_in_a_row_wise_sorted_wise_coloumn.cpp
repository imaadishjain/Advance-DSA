#include<bits/stdc++.h>
using namespace std;


void searchsorted(int **arr, int r, int c, int x)
{
    int i=0;
    int j=c-1;


    while(i<r && j>=0)
    {
        if(arr[i][j]==x)
        {
            cout<<"Found and Position="<<"("<<i<<","<<j<<")"<<endl;
            return;
        }

        else if(arr[i][j]>x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    cout<<"Not Foud\n";
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
    cout<<"Enter the elements in row wise and coloumn wise sorted order\n";


    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    } 
    int x;
    cout<<"Enter the element to be searched=\n";
    cin>>x;
   searchsorted(arr,m,n,x);

    return 0;

}