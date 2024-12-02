#include <bits/stdc++.h>
using namespace std;
const int N=1005;
bool dp[N][N];
int main() {
    int t;cin>>t;
    while (t--) {
        int n,marks;cin>>n>>marks;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin>>arr[i];
        }
        int s=1000-marks;
        dp[0][0]=1;

        for (int i=1;i<=s;i++){
            dp[0][i]=0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= s; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
                } else {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        if (dp[n][s])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}