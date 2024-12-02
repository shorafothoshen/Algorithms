#include<bits/stdc++.h>
using namespace std;
void marge(int a[],int l,int m, int r){
    int Lsize=m-l+1;
    int Rsize=r-m;
    int Larr[Lsize], Rarr[Rsize];
    int k=0;
    for(int i=l;i<=m;i++){
        Larr[k]=a[i];
        k++;
    }
    k=0;
    for(int i=m+1;i<=r;i++){
        Rarr[k]=a[i];
        k++;
    }
    int i=0,j=0;
    int cur=l;
    while(i<Lsize && j<Rsize){
        if(Larr[i]<=Rarr[j]){
            a[cur]=Larr[i];
            i++;
        }
        else{
            a[cur]=Rarr[j];
            j++;
        }
        cur++;
    }
    while(i<Lsize){
        a[cur]=Larr[i];
        i++;
        cur++;
    }
    while(j<Rsize){
        a[cur]=Rarr[i];
        j++;
        cur++;
    }
    
}
void marge_sort(int a[],int l, int r){
    if(l<r){
        int mid=(l+r)/2;
        marge_sort(a,l,mid);
        marge_sort(a,mid+1,r);
        marge(a,l,mid,r);
        for(int i=l;i<=mid;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        cout<<"New"<<endl;
        for(int i=mid+1;i<=r;i++){
            cout<<a[i]<<" ";
        }
    }
}
int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    marge_sort(a,0,n-1);
    // for(int i=0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
}