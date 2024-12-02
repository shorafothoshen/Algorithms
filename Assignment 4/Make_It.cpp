#include<bits/stdc++.h>
using namespace std;
int const N = 1e5+7;
int dp[N];
void dp_set(){
    for(int i=0;i<N;i++){
        dp[i]=-1;
    }
}
bool fun(int n,int s){
    if(n==s){
        return true;
    } 
    else if(n < s){
        return false;
    }
    if(dp[s] != -1){
        return dp[s];
    }
    int  co1 = fun(n,s+3);
    int co2 = fun(n,s*2);
    return dp[s] = (co1 || co2);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        dp_set();
        if(fun(n,1)) {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}