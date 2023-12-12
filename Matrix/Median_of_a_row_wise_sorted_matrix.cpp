#include<bits/stdc++.h>
using namespace std;

int median(int **arr, int r, int c)
{
    int minn=INT_MAX;
    int maxx=INT_MIN;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            maxx=max(maxx,arr[i][j]);
            minn=min(minn,arr[i][j]);
        }
    }

    int medPos=(r*c+1)/2;

    while(minn<maxx)
    {
        int mid=(minn+maxx)/2;

        int midPos=0;

        for(int i=0;i<r;i++)
        { 
        
           midPos+=upper_bound(arr[i],arr[i]+c,mid)-arr[i];
        }

        if(midPos<medPos)
        {
            minn=mid+1;
        }
        else
        {
            maxx=mid;
        }
    }
  return minn;
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
    cout<<"Enter the elements(row wise sorted)\n";


    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    } 
    
    cout<<"Median of a martix="<<median(arr, m , n);;

   median(arr, m , n);
    return 0;

}
