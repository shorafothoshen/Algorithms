#include<bits/stdc++.h>
using namespace std;
const int N=1e5+4;
vector < int > parent(N, -1), parentSize(N, 1);
int dsu_find(int Node){
    while(parent[Node]!=-1){
        Node=parent[Node];
    }
    return Node;
}
int mx=0;
void dsu_union(int a,int b){
    int ld_a = dsu_find(a);
    int ld_b = dsu_find(b);
    if(a!=b){
        if(parentSize[ld_a]>=parentSize[ld_b]){
            parent[ld_b]=a;
            parentSize[ld_a]+=parentSize[ld_b];
            mx=max(mx,parentSize[ld_a]);
        }
        else{
            parent[ld_a]=ld_b;
            parentSize[ld_b]+=parentSize[ld_a];
            mx=max(mx,parentSize[ld_b]);
        }
    }
}

int main()
{
    int n,e;cin>>n>>e;
    int cmpn=n;
    while(e--){
        int a,b;cin>>a>>b;
        int ld_a=dsu_find(a);
        int ld_b=dsu_find(b);
        if(ld_a!=ld_b){
            cmpn--;
            dsu_union(a,b);
        }
        cout<<cmpn<<" "<<mx<<endl;
    }
   return 0;
}