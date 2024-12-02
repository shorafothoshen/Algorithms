#include<bits/stdc++.h>
using namespace std;
const int N=1e5+4;
vector<int> adj[N];
bool visited[N];
vector<int>value;
void dfs(int s){
    visited[s]=true;
    value.push_back(s);
    for(auto val:adj[s]){
        if(visited[val]) continue;
        dfs(val);
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
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
            for(auto X:value){
                cout<<X<<" ";
            }
            cout<<endl;
            value.clear();
        }
    }
    cout<<cnt<<endl;
   return 0;
}