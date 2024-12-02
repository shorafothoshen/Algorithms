#include<bits/stdc++.h>
using namespace std;
void marge(int a[],int l,int m, int r){
    int Lsize=m-l+1;
    int L[Lsize];
    //int L[m-l+1];
    int Rsize=r-m;
    int R[Rsize];
    //int R[r-m];
    int k=0;
    for(int i=l;i<=m;i++){
        L[k]=a[i];
        k++;
    }
    k=0;
    for(int i=m+1;i<=r;i++){
        R[k]=a[i];
        k++;
    }
    int i=0,j=0;
    int crn=l;
    while(i<Lsize && j<Rsize){
        if(L[i]<=R[j]){
            a[crn]=L[i];
            i++;
        }
        else{
            a[crn]=R[j];
            j++;
        }
        crn++;
    }

    while(i<Lsize){
        a[crn]=L[i];
        i++;
        crn++;
    }
    while(j<Rsize){
        a[crn]=R[j];
        j++;
        crn++;
    }
}
int main()
{
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    marge(a,0,3,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
   return 0;
}