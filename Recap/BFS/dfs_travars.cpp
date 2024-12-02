#include<bits/stdc++.h>
using namespace std;
const int N=10e5+5;
vector<int>v[N];
bool vist[N];
void dfs(int src){ 
    vist[src]=true;
    cout<<src<<endl;
    for(int i=0;i<v[src].size();i++){
        int child=v[src][i];
        if(vist[child]==false){
            dfs(child);
        }
    }
}
int main(){
    int n,e;cin>>n>>e;
    while(e--){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    
}