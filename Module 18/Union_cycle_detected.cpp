#include<bits/stdc++.h>
using namespace std;
int parent[1000];
int parentLevel[1000];
void dsu_set(int n){
    for(int i=1;i<=n;i++){
        parent[i]=-1;
        parentLevel[i]=1;
    }
}
int dsu_find(int node){
    while(parent[node]!=-1) node=parent[node];
    return node;
}
void dsu_union(int a,int b){
    if(dsu_find(a)!=dsu_find(b)){
        if(parentLevel[dsu_find(a)]>parentLevel[dsu_find(b)]){
            parent[dsu_find(b)]=dsu_find(a);
        }
        else if(parentLevel[dsu_find(a)]<parentLevel[dsu_find(b)]){
            parent[dsu_find(a)]=dsu_find(b);
        }
        else{
            parent[dsu_find(b)]=dsu_find(a);
            parentLevel[dsu_find(a)]++;
        }
    }
}
int main()
{
    int n,e;cin>>n>>e;
    dsu_set(n);
    while(e--){
        int a,b;cin>>a>>b;
        if(dsu_find(a)==dsu_find(b)){
            cout<<"Cycle Detected"<<endl;
            cout<<a<<" "<<b<<endl;
        }
        else{
            dsu_union(a,b);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dsu_find(i)<<" ";
    }
   return 0;
}