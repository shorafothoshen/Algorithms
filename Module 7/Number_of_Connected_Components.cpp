#include<bits/stdc++.h>
using namespace std;

const int N=1e5+6;
vector<int> adj[N];
bool visited[N];
void dfs(int u){
	visited[u]=true;
	for(int val:adj[u]){
		if(visited[val])continue;
		dfs(val);
	}
}
void bfs(int s){
	queue<int>q;
	q.push(s);
	visited[s]=true;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		//cout<<u<<" ";
		for(int val:adj[u]){
			if(visited[val])continue;
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
	}
	//bfs(1);
	int cc=0;
	for(int i=1;i<=n;i++){
		if(visited[i])continue;
		dfs(i);
		cc++;
	}
	cout<<"Connected Components :"<<cc<<endl;
}