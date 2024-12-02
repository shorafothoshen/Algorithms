#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1004;
int dp[N][N];
void dp_set(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i][j]=-1;
        }
    }
}
int knapsack(int n,int s,int val[],int w[]){
    if(n==0||s==0){
        return 0;
    }
    if(dp[n][s]!=-1){
        return dp[n][s];
    }
    if(w[n-1]<=s){
        int op1=knapsack(n-1,s-w[n-1],val,w)+val[n-1];
        int op2=knapsack(n-1,s,val,w);
        return dp[n][s]= max(op1,op2);
    }
    else{
        return dp[n][s]= knapsack(n-1,s,val,w);
    }
}
int main()
{
    int t;cin>>t;
    while(t--){
        dp_set();
        int n,s;cin>>n>>s;
        int val[n],w[n];
        for(int i=0;i<n;i++){
            cin>>w[i];
        }
        for(int i=0;i<n;i++){
            cin>>val[i];
        }
        cout<<knapsack(n,s,val,w)<<endl;
        }
   return 0;
}