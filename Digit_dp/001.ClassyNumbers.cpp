// Classy Numbers
//https://codeforces.com/problemset/problem/1036/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
string s;
ll l,r;
ll dp[20][5][2];
 
 
ll solve(ll pos,ll cnt,bool tight){
 
    if(pos==s.size()){
       return 1;
    }
    if(dp[pos][cnt][tight]!=-1){
        return dp[pos][cnt][tight];
    }
    ll ret=0;
    ll en=tight ? (s[pos]-'0') : 9;
    for(ll i=0;i<=en;i++){
        ll cntupd=cnt+(i>0);
        if(cntupd<=3){
            ret =(ret+solve(pos+1,cntupd,tight & (i==en)));
        }
    }
    return dp[pos][cnt][tight]=ret;
}
 
int main() {
    ll t;
    cin>>t;
    while(t--){
       cin>>l>>r;
       s=to_string(r);
       memset(dp,-1,sizeof(dp));
       ll r_ans=solve(0,0,1);
       l-=1;
       s=to_string(l);
       memset(dp,-1,sizeof(dp));
       ll l_ans=solve(0,0,1);
       cout<<r_ans-l_ans<<"\n";
    }
    return 0;
}
