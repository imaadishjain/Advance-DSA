#include<bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

static bool myCmp(Item i1,Item i2)
    {
        double r1=(double)i1.value/(double)i1.weight;
        double r2=(double)i2.value/(double)i2.weight;
        
        return r1>r2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,myCmp);
        
        
        double res=0;
        
        for(int i=0;i<n;i++)
        {
            if(W>=arr[i].weight)
            {
                res+=arr[i].value;
                W-=arr[i].weight;
            }
            else
            {
                res+=(arr[i].value)*((double)W/arr[i].weight);
                break;
            }
        }
        
        return res;
    }

int main()
{
    int n;
    cout<<"Enter the number of items\n";
    cin>>n;

    Item *arr=new Item[n];
    
    cout<<"Enter Value and Weight of product\n";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i].value;
        cin>>arr[i].weight;
    }
    int W;
    cout<<"Enter the capacity\n";
    cin>>W;  
    cout<<"Total Profit="<<fractionalKnapsack(W,arr, n);

    return 0;
}