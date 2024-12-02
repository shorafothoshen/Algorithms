#include<bits/stdc++.h>
using namespace std;
int parent[1000];
int parentSize[1000];
void dsu_set(int n){
    for(int i=1;i<=n;i++){
        parent[i]=-1;
        parentSize[i]=1;
    }
}
int dsu_find(int node){
    while(parent[node]!=-1) node=parent[node];
    return node;
}
void dsu_union(int a,int b){
    if(dsu_find(a)!=dsu_find(b)){
        if(parentSize[dsu_find(a)]>parentSize[dsu_find(b)]){
            parent[dsu_find(b)]=dsu_find(a);
            parentSize[dsu_find(a)]+=parentSize[dsu_find(b)];
        }
        else{
            parent[dsu_find(a)]=dsu_find(b);
            parentSize[dsu_find(b)]+=parentSize[dsu_find(a)];
        }
    }
}
int main()
{
    int n,e;cin>>n>>e;
    dsu_set(n);
    while(e--){
        int a,b;cin>>a>>b;
        dsu_union(a,b);
    }
    for(int i=1;i<=n;i++){
        cout<<dsu_find(i)<<" ";
    }
   return 0;
}