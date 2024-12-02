#include<bits/stdc++.h>
using namespace std;

const int N=1007;
vector<int> adj[N];
bool visited[N];
int cnt;
void bfs(int s){
	queue<int>q;
	q.push(s);
	visited[s]=true;
	while(!q.empty()){
		int u=q.front();
		q.pop();
        cnt++;
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
        adj[v].push_back(u);
	}
    vector<int>ans;
	for(int i=0;i<N;i++){
		if(visited[i])continue;
        cnt=0;
		bfs(i);
        if(cnt>1){
            ans.push_back(cnt);
        }
    }
    sort(ans.begin(),ans.end());
    for(int val:ans){
        cout<<val<<" ";
    }
	return 0;
}