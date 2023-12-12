#include<bits/stdc++.h>
using namespace std;

int mincoin(int coins[],int n ,int amount)
{
    sort(coins,coins+n,greater<int>());

    int res=0;
    for(int i=0;i<n;i++)
    {
        if(coins[i]<=amount)
        {
            int calci=floor(amount/coins[i]);
            res+=calci;
            amount-=calci*coins[i];
        }
        if(amount==0)
         {
            break;
         }
    }

    return res;
}


int main()
{
    int n;
    cout<<"Enter the number of coins=";
    cin>>n;

    int *coins=new int[n];

    cout<<"Enter the coins\n";

    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }

    int amount;
    cout<<"Enter the value of amount\n";
    cin>>amount;

    cout<<"Total number of coins="<<mincoin(coins,n ,amount);
    
    return 0;
}
