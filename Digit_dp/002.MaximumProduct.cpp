//https://codeforces.com/gym/100886/problem/G

#include <bits/stdc++.h> 
using namespace std; 
#define ll long long
 
pair<ll,string> dp[20][2][2][2];
string a,b;
 
 
pair<ll,string> solve( ll pos,ll t1,ll t2, ll st){
 
    if(pos==a.size()){
        return {1,""};
    }
    if(dp[pos][t1][t2][st].first!= -1){
        return dp[pos][t1][t2][st];
    }
    ll ret=-1;
    string ans;
    ll lb=t1?(a[pos]-'0'):0;
    ll ub=t2?(b[pos]-'0'):9;
    for(ll i=lb;i<=ub;i++){
        ll val;
        if(st==0 and i==0){
            val=1;
        }
        else{
            val=i;
        }
        pair<ll,string> dpans=solve(pos+1,t1&(i==lb),t2&(i==ub),st|(i>0));
        if((val*dpans.first)>ret){
            ret=(val*dpans.first);
            if(st==0 and i==0){
              ans=dpans.second;
            }
            else{
                reverse(dpans.second.begin(),dpans.second.end());
                dpans.second.push_back('0'+i);
                reverse(dpans.second.begin(),dpans.second.end());
                ans=dpans.second;
            }
        }
    }
    return dp[pos][t1][t2][st]={ret,ans};
}
 
 
 
int main(){
 
   cin>>a>>b;
   reverse(a.begin(),a.end());
   while(a.size()<b.size()){
    a.push_back('0');
   }
   reverse(a.begin(),a.end());
   
   for(ll i=0;i<20;i++){
      for(ll j=0;j<2;j++){
        for(ll k=0;k<2;k++){
           for(ll l=0;l<2;l++){
              dp[i][j][k][l].first=-1;
           }
        }
      }
   }
 
 
   cout<<solve(0,1,1,0).second;
 
}
