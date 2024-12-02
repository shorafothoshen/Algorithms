#include<bits/stdc++.h>
using namespace std;

const int N=1e5+8;
vector<int>adj[N];
bool visited[N];
int level[N];
int perent[N];
void bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s]=true;
    level[s]=0;
    perent[s]=-1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int val:adj[u]){
            if(visited[val])continue;
            q.push(val);
            visited[val]=true;
            level[val]=level[u]+1;
            perent[val]=u;
        }        
    }
}
int main()
{
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s,d;cin>>s>>d;
    bfs(s);
    cout<<"Distance: "<<level[d]<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<"Perent Node"<<i<<" :"<<perent[i]<<endl;
    // }
    vector<int>path;
    int current=d;
    while(current!=-1){
        path.push_back(current);
        current=perent[current];
    }
    reverse(path.begin(),path.end());
    cout<<"Path: ";
    for(int Node:path){
        cout<<Node<<" ";
    }
   return 0;
}