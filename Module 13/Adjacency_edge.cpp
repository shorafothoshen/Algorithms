#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;cin>>n>>e;
    vector<pair<int,int>>v;
    while(e--){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    for(auto val:v){
        cout<<val.first<<" "<<val.second<<endl;
    }
   return 0;
}