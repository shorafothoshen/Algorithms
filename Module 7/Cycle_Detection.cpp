#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
vector<int>adj[N];
int visited[N];
int level[N];
void bsf(int s){
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
        int s,d;cin>>s>>d;
        bsf(s);
       cout<<level[d]<<endl;
    }
   return 0;
}