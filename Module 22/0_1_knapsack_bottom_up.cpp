#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1004;
int dp[N][N];
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
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if(w[i-1]<=j){
                //dp state
                int opt=dp[i-1][j-w[i-1]]+val[i-1];
                int opt2=dp[i-1][j];
                dp[i][j]=max(opt,opt2);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][s]<<endl<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
   return 0;
}