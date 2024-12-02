#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int parent[N];
int parentSize[N];
class Edge{
    public:
    int u,v,w;
    Edge(int u,int v,int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
};
bool cmp(Edge a,Edge b){
    return a.w<b.w;
}
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
    int Ld_a=dsu_find(a);
    int Ld_b=dsu_find(b);
    if(Ld_a!=Ld_b){
        if(parentSize[Ld_a]>parentSize[Ld_b]){
            parent[Ld_b]=Ld_a;
            parentSize[Ld_a]+=parentSize[Ld_b];
        }
        else{
            parent[Ld_a]=Ld_b;
            parentSize[Ld_b]+=parentSize[Ld_a];
        }
    }
}
int main()
{
    int n,e;cin>>n>>e;
    dsu_set(n);
    vector<Edge> v;
    vector<Edge> ans;
    while(e--){
        int a,b,w;cin>>a>>b>>w;
        v.push_back(Edge(a,b,w));
    }
    sort(v.begin(),v.end(),cmp);
    for(Edge val:v){
        int u=val.u;
        int v=val.v;
        int LeaderA=dsu_find(u);
        int LeaderB=dsu_find(v);
        if(LeaderA==LeaderB)continue;
        ans.push_back(val);
        dsu_union(u,v);
    }
    for(Edge val:ans){
        cout<<val.u<<" "<<val.v<<" "<<val.w<<endl;
    }
   return 0;
}