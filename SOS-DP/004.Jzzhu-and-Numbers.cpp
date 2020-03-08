//https://codeforces.com/problemset/problem/449/D

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007
 
const int N=1048580;
ll dp[N][22];
ll ar[N],cnt[N],po[N];
ll n;
 
 
int main(){
 
    po[0]=1;
    for(int i=1;i<N;i++){ 
      po[i]=(po[i-1]*2)%mod;
    }
 
   
    cin>>n;
    for(ll i=1;i<=n;i++){
      cin>>ar[i],dp[ar[i]][19]++;
      
    }
    //sum over super set not subset
    for(ll i=19;i>=0;i--){
      //as -1 make no sense we cosiderthe leaf pos as the 20 th pos
       ll nex=(i>0)?i-1:20;
       for(ll  mask=0;mask<(1<<20);mask++){
            if(mask & (1<<i))
               dp[mask^(1<<i)][nex]+=dp[mask][i];
            dp[mask][nex]+=dp[mask][i]; 
       }
 
    }
    // inclusion-exclusion
    ll ans=0;
    for(ll  mask=0;mask<(1<<20);mask++){
        if(__builtin_popcount(mask)%2){
           ans = (ans - po[dp[mask][20]]+mod)%mod;
        }
        else{
           ans = (ans + po[dp[mask][20]]+mod)%mod;
        }
    }
 
    cout<<ans;
}
