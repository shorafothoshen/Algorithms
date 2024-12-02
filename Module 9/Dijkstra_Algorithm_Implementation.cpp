#include<bits/stdc++.h>
using namespace std;

const int N=1e5+6;
const int INF=1e9+8;
vector<pair<int,int>> adj[N];
vector<int>Distance(N,INF);
vector<bool>visited(N);

void dijkstra(int s){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	Distance[s]=0;
	//pq.push_back({0,s});
	pq.push({Distance[s],s});
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		visited[u]=true;
		for(pair<int,int> valPair:adj[u]){
			int v=valPair.first;
			int w=valPair.second;
			if(visited[v]) continue;
			if(Distance[v]>Distance[u]+w){
				Distance[v]=Distance[u]+w;
				pq.push({Distance[v],v});
			}
		}
	}
}
int main(){
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,w;cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	dijkstra(1);
	for(int i=1;i<=n;i++){
		cout<<"Distance of Node"<<i<<" : "<<Distance[i]<<endl;
	}
}