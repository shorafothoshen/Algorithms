#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
    int n;cin>>n;
    int s=0;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        s += arr[i]; 
    }
    if(s%2 == 0){
        int sum = s/2;
        int dp[n+1][s+1];
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(int i=1;i<=sum;i++){
            dp[0][i] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(arr[i-1] <= j){
                    int op1 = dp[i-1][j-arr[i-1]];
                    int op2 = dp[i-1][j];
                    dp[i][j] = op1 || op2;
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        if(dp[n][sum]){
        cout<<"YES"<<endl;
        }
        else{
        cout<<"NO"<<endl;
        }
    }
        else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}