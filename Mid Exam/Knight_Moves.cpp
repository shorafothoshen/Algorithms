#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,e;
bool visited[N][N];
int dist[N][N];
vector<pair<int,int>> path={{1,2},{2,1},{2,-1},{1,-2},{-1,2},{-2,1},{-2,-1},{-1,-2}};
bool isValid(int si,int sj){
    if(si>=0 && si<n && sj>=0 && sj<e){
        return true;
    }
    else{
        return false;
    }
}
void bfs(int sI,int sJ){
    queue<pair<int,int>>q;
    q.push({sI,sJ});
    dist[sI][sJ]=0;
    visited[sI][sJ]=true;
    while(!q.empty()){
        pair<int,int> par=q.front();
        int pI=par.first;
        int pJ=par.second;
        q.pop();
        for(auto child:path){
            int X=pI+child.first;
            int Y=pJ+child.second;
            if(!isValid(X,Y))continue;
            if(visited[X][Y])continue;
            visited[X][Y]=true;
            q.push({X,Y});
            dist[X][Y]=dist[pI][pJ]+1;
        }
    }
}
int main()
{
    int t;cin>>t;
    while(t--){
        for(int i=0;i<n;i++){
            for(int j=0;j<e;j++){
                dist[i][j]=-1;
                visited[i][j]=false;
            }
        }
        cin>>n>>e;
        int ki,kj,qi,qj;cin>>ki>>kj>>qi>>qj;
        bfs(ki,kj);
        cout<<dist[qi][qj]<<endl;
    }
   return 0;
}