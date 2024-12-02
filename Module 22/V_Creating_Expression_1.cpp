//https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/V
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dp[23][23];
bool equalSum(int n,int k,int a[]){
    if(n==0){
        return false;
    }
    equalSum(n-1,k,a);
    return true;
}
int main()
{
    int n,x;cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
   return 0;
}