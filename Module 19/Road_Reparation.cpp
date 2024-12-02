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
void prims(int s,int n){
    priority_queue<Edge,vector<Edge>,cmp> pq;
    pq.push(Edge(s,s,0));
    int cnt=0;
    while(!pq.empty()){
        Edge parent=pq.top();
        pq.pop();
        int v=parent.v;
        if(visited[v]) continue;
        visited[v]=true;
        cnt++;
        EdgeList.push_back(parent);
        for(auto child:Vct[v]){
            if(!visited[child.first]){
                pq.push(Edge(v,child.first,child.second));
            }
        }
    }
    EdgeList.erase(EdgeList.begin());
    long long sum=0;
    for(Edge val:EdgeList){
        sum+=(long long)(val.w);
    }
    if(cnt==n){
        cout<<sum<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
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
    prims(1,n);
   return 0;
}