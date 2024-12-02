#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
vector<int>adj[N];
bool visited[N];
void dfs(int s){
    visited[s]=true;
    cout<<s<<" ";
    for(int val:adj[s]){
        if(!visited[val]){
            dfs(val);
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
    dfs(1);
   return 0;
}