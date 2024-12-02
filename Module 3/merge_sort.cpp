#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int mid,int r){
    int Lsize=mid-l+1;
    int Rsize=r-mid;
    int L[Lsize],R[Rsize];
    int k=0;
    for(int i=l;i<=mid;i++){
        L[k]=a[i];
        k++;
    }
    k=0;
    for(int i=mid+1;i<=r;i++){
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
void mergeSort(int a[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
int main()
{
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergeSort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
   return 0;
}