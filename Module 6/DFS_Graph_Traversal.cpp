#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<int> adj[N];
bool visited[N];
void dfs(int u){
	visited[u]=true;
	cout<<u<<" ";

	for(int val:adj[u]){
		if(visited[val]==true) continue;
		dfs(val);
	}
}
int main(){
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
	}
	dfs(1);
	
}