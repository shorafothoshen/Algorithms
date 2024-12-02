#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adj[N];
int level[N];
bool visited[N];
int par[N];
void bfs(int s){
    queue<int>q;
    q.push(s);
    par[s]=-1;
    visited[s]=true;
    while(!q.empty()){
        int p=q.front();
        q.pop();
        for(auto child:adj[p]){
            if(visited[child])continue;
            q.push(child);
            par[child]=p;
            visited[child]=true;
            level[child]=level[p]+1;
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
    // for(int i=1;i<=n;i++){
    //     cout<<"Node "<<i<<": "<<par[i]<<endl;
    // }
    int d;cin>>d;
    if(visited[d]){
        vector<int>path;
        int x=d;
        while(x!=-1){
            path.push_back(x);
            x=par[x];
        }
        reverse(path.begin(),path.end());
        for(int val:path){
            cout<<val<<" ";
        }
    }
    else{
        cout<<"Path Nai"<<endl;
    }
   return 0;
}