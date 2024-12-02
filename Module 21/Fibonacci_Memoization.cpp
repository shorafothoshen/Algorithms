#include<bits/stdc++.h>
using namespace std;
const int N=1e5+4;
int save[N];
void minas(){
    for(int i=0;i<N;i++){
        save[i]=-1;
    }
}
int cnt=0;
int fibo(int n){
    cnt++;
    if(n==0||n==1) return 1;
    if(save[n]!=-1) return save[n];
    return save[n]= fibo(n-1)+fibo(n-2);
}
int main(){
    minas();
    int n;cin>>n;
    cout<<fibo(n)<<endl;
    cout<<cnt<<endl;
    return 0;
}