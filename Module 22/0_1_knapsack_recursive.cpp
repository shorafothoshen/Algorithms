#include<bits/stdc++.h>
#define ll long long
using namespace std;
int knapsack(int n,int s,int val[],int w[]){
   if(n==0||s==0) return 0;
   if(w[n-1]<=s){
   int op1=knapsack(n-1,s-w[n-1],val,w)+val[n-1];
   int op2=knapsack(n-1,s,val,w);
   return max(op1,op2);
   }
   else{
      return knapsack(n-1,s,val,w);
   }
}
int main()
{
    int n;cin>>n;
    int val[n],w[n];
    for(int i=0;i<n;i++){
      cin>>val[i];
    }
    for(int i=0;i<n;i++){
      cin>>w[i];
    }
    int s;cin>>s;
    cout<<knapsack(n,s,val,w)<<endl;
   return 0;
}