#include<bits/stdc++.h>
using namespace std;


int maxfreqinrange(int left[], int right[], int n)
{
    int freq[101]={0};

    for(int i=0;i<n;i++)
    {
        freq[left[i]]++;
        freq[right[i]+1]--;
    }
    int res=0;
    for(int i=1;i<101;i++)
    {
        freq[i]=freq[i]+freq[i-1];

        if(freq[i]>freq[res])
        {
            res=i;
        }
    }


    return res;

}


int main()
{
    int n;
    cout<<"Enter the size of arrays=";
    cin>>n;

    int *left=new int[n];
    int *right=new int[n];
    cout<<"Enter the elements of left array\n";
    for(int i=0;i<n;i++)
    {
        cin>>left[i];
    }
    
    cout<<"Enter the elements of right array\n";
    for(int i=0;i<n;i++)
    {
        cin>>right[i];
    }

    cout<<"Maximum Element of range="<<maxfreqinrange(left,right,n);

    return 0;
}