#include<bits/stdc++.h>
using namespace std;
  struct Job
  {
    int id;
    int dead;
    int profit;
  };
 static  bool myCmp(Job J1,Job J2)
    {
        if(J1.profit==J2.profit)
        {
            return J1.dead<J2.dead;
        }
        return J1.profit>J2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
       sort(arr,arr+n,myCmp);      
       int dl=0;
       for(int i=0;i<n;i++)
       {
           //cout<<arr[i].dead<<" "<<arr[i].profit<<endl;
           dl=max(dl,arr[i].dead);
       }
       
       int setup[n]={0};
       int p=0;
       int count=0;
       for(int i=0;i<n;i++)
       {
           int j=arr[i].dead-1;
           while(j>=0)
           {
               if(setup[j]==0)
               {
                   setup[j]=1;
                   p+=arr[i].profit;
                   count++;
                   break;
               }
               j--;
           }
           
       }
       
       vector<int>ans;
       ans.push_back(count);
       ans.push_back(p);
       
       return ans;
    } 

int main()
{
    int n;
    cout<<"Enter the total number of Jobs\n";
    cin>>n;

    Job *arr=new Job[n];
    cout<<"Enter the job deadline and Profit\n";
    for(int i=0;i<n;i++)
    {
       cin>>arr[i].dead;
       cin>>arr[i].profit;
    }

    vector<int>ans=JobScheduling(arr,n);

    cout<<"Total jobs done="<<ans[0];
    cout<<"Total Profits="<<ans[1];

    return 0;
}