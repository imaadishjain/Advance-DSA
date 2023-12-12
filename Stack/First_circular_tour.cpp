#include<bits/stdc++.h>
using namespace std;


int firstcircular(vector<int>pet,vector<int>&dist)
{
    int start=0;
    int curr_petrol=0;
    int prev_petrol=0;

    for(int i=0;i<pet.size();i++)
    {
        curr_petrol+=pet[i]-dist[i];

        if(curr_petrol<0)
        {
            start=i+1;
            prev_petrol=curr_petrol;
            curr_petrol=0;
        }
    }

    return prev_petrol+curr_petrol>=0?start+1:-1;
}

int  main()
{
    vector<int>pet;
    vector<int>dis;
    cout<<"Enter the quantity of petrol(-1 for exits)\n";

    int n;
    while(1)
    {
        cin>>n;
        if(n==-1)
        {
            break;
        }
        pet.push_back(n);
    }

    cout<<"Enter the distance(-1 for exits)\n";

    while(1)
    {
        cin>>n;
        if(n==-1)
        {
            break;
        }
        dis.push_back(n);
    }

    cout<<"First Circular Tour start from="<<firstcircular(pet,dis);
    
    return 0;
}