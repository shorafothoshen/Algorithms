#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
vector<int>adj[N];
int visited[N];
int level[N];
void bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int val:adj[u]){
            if(visited[val])continue;
            q.push(val);
            visited[val]=1;
            level[val]=level[u]+1;
        }
    }
}
void BackUp(){
    for(int i=0;i<N;i++){
        level[i]=0;
        visited[i]=0;
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
    int t;cin>>t;
    while(t--){
        BackUp();
        int s,d;cin>>s>>d;
        bfs(s);
        if(visited[d]==0){
            cout<<"-1"<<endl;
            continue;
        }
        cout<<level[d]<<endl;
    }
   return 0;
}