#include<bits/stdc++.h>
using namespace std;
const int N=1e3+8;
const int INF=1e9+4;
vector<pair<int,int>>adj[N];
vector < int > dist(N, INF);
bool visited[N];
void dikstra(int s){
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
   pq.push({0,s});
   dist[s]=0;
   while(!pq.empty()){
      pair<int,int> p=pq.top();
      pq.pop();
      int pNode=p.second;
      if(visited[pNode]){
         continue;
      }
      visited[pNode]=true;
      int pCost=p.first;
      for(pair<int,int> child:adj[pNode]){
         int childNode=child.first;
         int childCost=child.second;
         if(pCost+childCost<dist[childNode]){
            dist[childNode]=pCost+childCost;
            pq.push({dist[childNode],childNode});
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
   }
   int s;cin>>s;
   dikstra(s);
   int t;cin>>t;
   while(t--){
        int d,dw;cin>>d>>dw;
        if(dist[d]<=dw){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
   }
   return 0;
}