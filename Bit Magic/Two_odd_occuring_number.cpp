#include<bits/stdc++.h>
using namespace std;


void twoodd(vector<int>vec)
{
    int x=vec[0];

    for(int i=1;i<vec.size();i++)
    {
        x=x^vec[i];
    }

    int k=x&(~(x-1));
    int res1=0;
    int res2=0;
    for(int i=0;i<vec.size();i++)
    {
        if((vec[i]&k)==1)
        {
            res1=res1^vec[i];
        }
        else
        {
            res2=res2^vec[i];
        }
    }

    cout<<res1<<" "<<res2<<endl;
}

int main()
{
    vector<int>vec;
    int n;
    cout<<"Enter the size=";
    cin>>n;
    int a;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        vec.push_back(a);
    }

    cout<<"Two odd number is\n";

    twoodd(vec);


    return 0;

}