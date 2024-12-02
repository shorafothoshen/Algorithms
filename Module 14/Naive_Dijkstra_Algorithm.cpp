#include<bits/stdc++.h>
using namespace std;
const int N=1e5+8;
vector<pair<int,int>>adj[N];
int dist[N];
void dikstra(int s){
   queue<int>q;
   q.push(s);
   dist[s]=0;
   while(!q.empty()){
      int u=q.front();
      q.pop();
      for(pair<int,int> child:adj[u]){
         int childNode=child.first;
         int childWeight=child.second;
         if(dist[u]+childWeight<dist[childNode]){
            dist[childNode]=dist[u]+childWeight;
            q.push(childNode);
         }
      }
   }
}
int main()
{
    int n,e;cin>>n>>e;
    for(int i=1;i<=e;i++){
      int a,b,w;cin>>a>>b>>w;
      adj[a].push_back({b,w});
      adj[b].push_back({a,w});
   }
   for(int i=1;i<=n;i++){
      dist[i]=INT_MAX;
   }
   dikstra(1);
   for(int i=1;i<=n;i++){
      cout<<"Node "<<i<<": "<<dist[i]<<endl;
   }
   return 0;
}