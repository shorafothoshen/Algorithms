#include<bits/stdc++.h>
using namespace std;

const int N=1e5+8;
vector<int> adj[N]; 
bool visited[N];
int Height[N];
void dfs(int u){
	visited[u]=true;
	
	for(int val: adj[u]){
		if(visited[val]==true) continue;
		dfs(val);
		if(Height[val]+1>Height[u]){
			Height[u]=Height[val]+1;
		}
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
		cout<<"Height "<<i<<" :"<<Height[i]<<endl;
	}
}