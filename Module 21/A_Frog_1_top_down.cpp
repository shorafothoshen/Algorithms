#include<bits/stdc++.h>
using namespace std;
const int N=1e5+8;
int dp[N];
void mainas(){
    for(int i=1;i<=N;i++){
        dp[i]=-1;
    }
}
int save(int a[],int n){
    if(n==1){
        return 0;
    }
    if(dp[n]!=-1) return dp[n];
    else if(n==2){
        return dp[n]= abs(a[2]-a[1]);
    }
    else{
        int chaice1=save(a,n-1)+abs(a[n]-a[n-1]);
        int chaice2=save(a,n-2)+abs(a[n]-a[n-2]);
        return dp[n]= min(chaice1,chaice2);
    }
}
int main()
{
    mainas();
    int n;cin>>n;
    int ar[n+1];
    for(int i=1;i<=n;i++){
        cin>>ar[i];
    }
    cout<<save(ar,n)<<endl;
   return 0;
}