//https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/U
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1004;
int dp[N][N];
int knapsack(int n,int w,int wt[],int val[]){
    if(n==0 || w==0){
        return 0;
    }
    if(wt[n-1]<=w){
        return dp[n][w]= max(knapsack(n-1,w-wt[n-1],wt,val)+val[n-1],knapsack(n-1,w,wt,val));
    }
    else{
        return dp[n][w]=knapsack(n-1,w,wt,val);
    }
}
int main()
{
    int n,w;cin>>n>>w;
    int val[n],wt[n];
    for(int i=0;i<n;i++){
        cin>>wt[i];
        cin>>val[i];
    }
    int ans=knapsack(n,w,wt,val);
    cout<<ans<<endl;
   return 0;
}