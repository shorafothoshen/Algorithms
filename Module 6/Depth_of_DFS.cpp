#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
vector<int> adj[N];
bool visited[N];
int Depth[N];
void dfs(int u){
	visited[u]=true;
	for(int val:adj[u]){

		if(visited[val]==true) continue;
		Depth[val]=Depth[u]+1;
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
	for(int i=1;i<=n;i++){
		cout<<"Depth "<<i<<" : "<<Depth[i]<<endl;
	}
}