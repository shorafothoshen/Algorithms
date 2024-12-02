#include<bits/stdc++.h>
using namespace std;
void divide(int a[],int l, int r){
    if(l<r){
        int mid=(l+r)/2;
        divide(a,l,mid);
        divide(a,mid+1,r);
    }
}
int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    divide(a,0,n-1);
}