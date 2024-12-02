#include<bits/stdc++.h>
using namespace std;
const int N=1e3+3;
int level[N][N];
bool visited[N][N];
int n,m;
vector<pair<int,int>>path={{-1,0},{1,0},{0,-1},{0,1}};
bool isValid(int cI, int cJ)
{
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m)
        return true;
    else
        return false;
}
void bfs(int sI,int sJ){
    queue<pair<int,int>>q;
    q.push({sI,sJ});
    level[sI][sJ]=0;
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
            level[X][Y]=level[pI][pJ]+1;
        }
    }
}
int main()
{
    cin>>n>>m;
    char a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int sI,sJ;cin>>sI>>sJ;
    bfs(sI,sJ);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<level[i][j]<<" ";
        }
        cout<<endl;
    }
   return 0;
}