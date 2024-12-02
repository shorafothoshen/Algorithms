#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<pair<int,int>>v;
    int e;cin>>e;
    while(e--){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    for(auto val:v){
        cout<<val.first<<" "<<val.second<<endl;
    }
   return 0;
}