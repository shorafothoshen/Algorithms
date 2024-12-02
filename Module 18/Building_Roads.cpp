#include<bits/stdc++.h>
using namespace std;
const int N=1e5+4;
vector < int > parent(N, -1), parentSize(N, 1);
int dsu_find(int Node){
    while(parent[Node]!=-1){
        Node=parent[Node];
    }
    return Node;
}
void dsu_union(int a,int b){
    if(dsu_find(a)!=dsu_find(b)){
        if(dsu_find(a)>dsu_find(b)){
            parent[dsu_find(b)]=dsu_find(a);
            parentSize[dsu_find(a)]+=parentSize[dsu_find(b)];
        }
        else if(dsu_find(b)>dsu_find(a)){
            parent[dsu_find(a)]=dsu_find(b);
            parentSize[dsu_find(b)]+=parentSize[dsu_find(a)];
        }
        else{
            parent[dsu_find(b)]=dsu_find(a);
        }
    }
}

int main()
{
    int n,e;cin>>n>>e;
    while(e--){
        int a,b;cin>>a>>b;
        dsu_union(a,b);
    }
    map<int,bool>mp;
    for(int i=1;i<=n;i++){
        int ldr = dsu_find(i);
        mp[ldr]=true;
    }
    vector<int>v;
    for(auto Ld:mp){
       v.push_back(Ld.first); 
    }

    cout<<v.size()-1<<endl;
    for(int i=0;i<v.size()-1;i++){
        cout<<v[i]<<" "<<v[i+1]<<endl;
    }
   return 0;
}