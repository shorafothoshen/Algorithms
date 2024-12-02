#include<bits/stdc++.h>
using namespace std;
const int INF=1e7;
int main()
{
    int n,e;cin>>n>>e;
    int dist[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dist[i][j]=INF;
            if(i==j) dist[i][j]=0;
        }
    }
    while(e--){
        int a,b,w;cin>>a>>b>>w;
        dist[a][b]=w;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k]==INF||dist[k][j]==INF)continue;
                // if(dist[i][k]+dist[k][j]<dist[i][j])
                // dist[i][j]=dist[i][k]+dist[k][j];
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j]==INF){
                cout<<"INF"<<" ";
            }
            else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }
   return 0;
}