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
bool Subset_sum(int n,int s,int a[]){
   if(n==0){
      if(s==0){
         return true;
      }
      else{
         return false;
      }
   }
   if(dp[n][s]!=-1){
    return dp[n][s];
   }
   if(a[n-1]<=s){
      bool opt=Subset_sum(n-1,s-a[n-1],a);
      bool opt1=Subset_sum(n-1,s,a);
      return dp[n][s]=opt || opt1;
   }
   else{
      return dp[n][s]= Subset_sum(n-1,s,a);
   }
}
int main()
{
   int n;cin>>n;
   int a[n];
   for(int i=0;i<n;i++){
      cin>>a[i];
   }
   dp_set();
   int s;cin>>s;
   if(Subset_sum(n,s,a)){
      cout<<"Yes"<<endl;
   }
   else{
      cout<<"No"<<endl;
   }
   return 0;
}