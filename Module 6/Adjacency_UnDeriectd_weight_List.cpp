#include<bits/stdc++.h>
using namespace std;
const int N=1e5+6;
vector<pair<int,int>>adj[N];
int main(){
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,w;cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	for(int i=1;i<=n;i++){
		cout<<"List "<<i<<": ";
		for(pair<int,int> val:adj[i]){
			cout<<"("<<val.first<<","<<val.second<<") ";
		}
		cout<<endl;
	}
}