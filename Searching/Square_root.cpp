#include<bits/stdc++.h>
using namespace std;


int square_root(int a)
{
    int low=1;
    int high=a;
    int res;
    while(low<=high)
    {
       int mid=(low+high)/2;

       if(mid*mid==a)
       {
        return mid;
       }
       else if(mid*mid>a)
       {
        high=mid-1;
       }
       else
       {
        low=mid+1;
        res=mid;
       }
    }

    return res;
}

int main()
{
    int a;
    cout<<"Enter the number=";
    cin>>a;

    cout<<"Square Root of a number="<<square_root(a);

    return 0;
}