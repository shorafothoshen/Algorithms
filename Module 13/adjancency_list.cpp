#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;cin>>n>>e;
    vector<int>adj[n+1];
    while(e--){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<=n;i++){
        cout<<"List "<<i<<": ";
        for(auto val:adj[i]){
            cout<<val<<" ";
        }
        cout<<endl;
    }
   return 0;
}