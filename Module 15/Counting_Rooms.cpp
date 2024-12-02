#include<bits/stdc++.h>
#define pi pair<int,int>
using namespace std;
int n,e;
const int N=1e3+4;
char a[N][N];
vector<pi> path={{-1,0},{1,0},{0,-1},{0,1}};
bool visited[N][N];
bool isVaild(int si,int sj){
    if(si>=0 && si<n && sj>=0 && sj<e && a[si][sj]=='.'){
        return true;
    }
    else{
        return false;
    }
}
void dfs(int si,int sj ){
    visited[si][sj]=true;
    for(auto child:path){
        int ci=si+child.first;
        int cj=sj+child.second;
        if(isVaild(ci,cj) && !visited[ci][cj]){
            dfs(ci,cj);
        }
    }
}
int main()
{
    cin>>n>>e;
    for(int i=0;i<n;i++){
        for(int j=0;j<e;j++){
            cin>>a[i][j];
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<e;j++){
    //         cout<<a[i][j];
    //     }
    //     cout<<endl;
    // }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<e;j++){
            if(!visited[i][j] && a[i][j]=='.'){
              cnt++;
              dfs(i,j);  
            }
        }
    }
    cout<<cnt<<endl;
   return 0;
}