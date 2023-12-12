#include<bits/stdc++.h>
using namespace std;


bool pair_sum(int arr[], int n, int sum)
{
    int i=0;
    int j=n-1;

    while(i<j)
    {
        if(sum==arr[i]+arr[j])
        {
            return 1;
        }
        else if(arr[i]+arr[j]>sum)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return 0;
}


int main()
{
    int n;
    cout<<"Enter the size of array=";
    cin>>n;
    int *arr=new int[n];
    cout<<"Enter the element in sorted order\n";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int x;
    cout<<"Enter the element  to be sum=";
    cin>>x;

    cout<<std::boolalpha;

    cout<<"Pair is present="<<pair_sum(arr,n,x);

    return 0;

}