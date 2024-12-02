#include<bits/stdc++.h>
using namespace std;
const int N=10e5+5;
vector<int>v[N];
int dis[N];
bool vist[N];
void bfs(int src){
    queue<int> q;
    q.push(src);
    vist[src]=true;
    dis[src]=0;
    while(!q.empty()){
        int perent=q.front();
        q.pop();
        for(int i=0;i<v[perent].size();i++){
            int child=v[perent][i];
            if(vist[child]==false){
                q.push(child);
                dis[child]=dis[perent]+1;
                vist[child]=true;
            }
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
    bfs(1);
    for(int i=0;i<=n;i++){
        cout<<dis[i]<<endl;
    }
}