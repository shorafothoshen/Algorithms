#include<bits/stdc++.h>
#define pr pair<int,int>
using namespace std;
const int N=1e5+6;
vector<pr> Vct[N];
bool visited[N];
class Edge{
    public:
    int u,v,w;
    Edge(int u,int v,int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
};
vector<Edge>EdgeList;
class cmp
{
    public:
    bool operator()(Edge a,Edge b){
        return a.w>b.w;
    }
};
int prims(int s){
    priority_queue<Edge,vector<Edge>,cmp> pq;
    pq.push(Edge(s,s,0));
    while(!pq.empty()){
        Edge parent=pq.top();
        pq.pop();
        int u=parent.u;
        int v=parent.v;
        int w=parent.w;
        if(visited[v]) continue;
        visited[v]=true;
        EdgeList.push_back(parent);
        for(auto child:Vct[v]){
            if(!visited[child.first]){
                pq.push(Edge(v,child.first,child.second));
            }
        }
    }
}
int main()
{
    int n,e;cin>>n>>e;
    while(e--){
        int a,b,w;cin>>a>>b>>w;
        Vct[a].push_back({b,w});
        Vct[b].push_back({a,w});
    }
    prims(1);
    EdgeList.erase(EdgeList.begin());
    for(Edge val:EdgeList){
        cout<<val.u<<" "<<val.v<<" "<<val.w<<endl;
    }
   return 0;
}