#include<bits/stdc++.h>
using namespace std;

const int N=1e3+5;
vector<int> adj[N];
bool visited[N];
void bfs(int s){
	queue<int> q;
	q.push(s);
	visited[s]=true;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		cout<<u<<" ";
		for(int val:adj[u]){
			if(visited[val]==true)continue;
			q.push(val);
			visited[val]=true;
		}
	}
}

int main(){
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfs(1);
}