#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int fibo(int n){
    cnt++;
    if(n==0||n==1){
        return 1;
    }
    // int fibo_n=fibo(n-1);
    // int fibo_n2=fibo(n-2);
    // return fibo_n+fibo_n2;
    return fibo(n-1)+fibo(n-2);
}
int main()
{
    int n;cin>>n;
    int ans=fibo(n);
    cout<<ans<<endl;
    cout<<cnt<<endl;
   return 0;
}