#include<bits/stdc++.h>
using namespace std;
const int N=1e5+8;
vector<int>adj[N];
bool visited[N];
int dfs(int u){
    visited[u]=true;
    int cnt=1;
    for(int val:adj[u]){
        if(visited[val])continue;
        cnt+=dfs(val);
    }
    return cnt;
}
int main()
{
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }
    int k;cin>>k;
    int ans=dfs(k);
    cout<<ans-1<<endl;
   return 0;
}