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
        //cout<<u<<" ";
        for(int val: adj[u]){
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
    int k;cin>>k;
    bfs(k);
    int cnt=0;
    for(int i=0;i<N;i++){
        if(level[i]==1)
        cnt++;
    }
    cout<<cnt<<endl;
   return 0;
}