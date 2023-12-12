#include<bits/stdc++.h>
using namespace std;


int oneodd(vector<int>vec)
{
    int res=vec[0];

    for(int i=1;i<vec.size();i++)
    {
        res=res^vec[i];
    }

    return res;
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

    cout<<"One odd is="<<oneodd(vec);

    return 0;

}