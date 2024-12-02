#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> adj[N];
int level[N];
bool visited[N];
void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
       cout<<u<<" ";
        for(int i=0;i<adj[u].size();i++){
            int chail=adj[u][i];
            if(!visited[chail]){
                q.push(chail);
                visited[chail]=true;
                level[chail]=level[u]+1;
            }
        }
    }
}
int main()
{
    int n,e;cin>>n>>e;
    while(e--){
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);

   return 0;
}