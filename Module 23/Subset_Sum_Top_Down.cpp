#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool Subset_sum(int n,int s,int a[]){
   if(n==0){
      if(s==0){
         return true;
      }
      else{
         return false;
      }
   }
   if(a[n-1]<=s){
      bool opt=Subset_sum(n-1,s-a[n-1],a);
      bool opt1=Subset_sum(n-1,s,a);
      return opt || opt1;
   }
   else{
      return Subset_sum(n-1,s,a);
   }
}
int main()
{
   int n;cin>>n;
   int a[n];
   for(int i=0;i<n;i++){
      cin>>a[i];
   }
   int s;cin>>s;
   if(Subset_sum(n,s,a)==true){
      cout<<"Yes"<<endl;
   }
   else{
      cout<<"No"<<endl;
   }
   return 0;
}