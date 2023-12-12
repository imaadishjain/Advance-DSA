#include<bits/stdc++.h>
using namespace std;

struct Triplet
    {
        int val, aPos, vPos;
        Triplet(int v,int ap,int vp)
        {
            val=v;
            aPos=ap;
            vPos=vp;
        }
    };
    
    struct MyComp
    {
        bool operator() (Triplet &t1, Triplet &t2)
        {
            return t1.val>t2.val;
        }
    };
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> res; 
      
    priority_queue <Triplet, vector<Triplet>,MyComp> pq;
    
    for(int i=0;i<arr.size();i++){
        Triplet t(arr[i][0],i,0);
        pq.push(t);
    }
    
    while(pq.empty()==false){
        Triplet curr=pq.top();pq.pop();
        res.push_back(curr.val);
        int ap=curr.aPos;int vp=curr.vPos;
        if(vp+1<arr[ap].size()){
            Triplet t(arr[ap][vp+1],ap,vp+1);
            pq.push(t);
        }
    }

    return res;
    }


int  main()
{
    vector<vector<int>>res={{10,20,30},
                            {5,15},
                            {1,9,11,18}};
    
    vector<int>ans=mergeKArrays(res,res.size());


    for(auto it:ans)
    {
        cout<<it<<" ";
    }

    return 0;
                                 
} 