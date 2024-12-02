#include<bits/stdc++.h>
using namespace std;

const int N=1e5+8;
vector<int>adj[N];
bool visited[N];
int level[N];
void bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int val:adj[u]){
            if(visited[val])continue;
            q.push(val);
            visited[val]=true;
            level[val]=level[u]+1;
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
    bfs(0);
    int l;cin>>l;
    vector<int>ans;
    for(int i=0;i<=N;i++){
        if(level[i]==l&&visited[i])
        ans.push_back(i);
    }
    if(ans.size()==0){
        cout<<"-1";
    }
    else{
        for(auto val:ans){
            cout<<val<<" ";
        }
    }
   return 0;
}