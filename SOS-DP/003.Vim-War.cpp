//https://www.hackerrank.com/contests/w16/challenges/vim-war/submissions/code/1321628847
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007

const int N=1048580;
ll cnt[N],dp[N][21];
ll po[N],n;
int x;
char str[100];

ll solve(ll mask,ll pos){

     if(pos==-1){
      return cnt[mask];
     }
     if(dp[mask][pos]!=-1){
      return dp[mask][pos];
     }
     ll ret=0;
     if((1<<pos) & mask){
      ret+= solve(mask^(1<<pos),pos-1);
      ret+= solve(mask,pos-1);
     }
     else{
       ret+=solve(mask,pos-1);
     }
     return dp[mask][pos]=ret;

}


int main(){
    
    memset(dp,-1,sizeof(dp));

    po[0]=1;
    for(int i=1;i<N;i++){ 
      po[i]=(po[i-1]*2)%mod;
    }



    cin>>n>>m;
    for(int i=0;i<n;i++) {
        ll val = 0;
        scanf("%s",str);
        for(int j=0;j<m;j++) {
            x = str[j]-'0';
            val = val*2 + x;
        }
        cnt[val]++;
    }

    ll reqmask = 0;
    scanf("%s",str);
    for(int j=0;j<m;j++) {
         x = str[j]-'0';
         reqmask = reqmask*2 + x;
    }

    ll ans=0;

    for(ll i=0;i<(1<<m);i++){
        if((i & reqmask)!=i){
          continue;
        }
        if((__builtin_popcount(i) - __builtin_popcount(reqmask))%2){
           ans=(ans -  po[solve(i,m-1)]+mod)%mod;
        }
        else{
           ans=(ans + po[solve(i,m-1)]+mod)%mod;
        }
    }


    if(reqmask==0){
      ans--;
    }
    cout<<ans;
}




















//------------------------------------
#include<bits/stdc++.h>
#define MOD 1000000007
#define LLD long long int
#define si(x) scanf("%d",&x);
#define MAXV 1048576
using namespace std;
char str[100];
int p[MAXV+3];
int mp[MAXV+3];
int main() {
    p[0] = 1;
    for(int i=1;i<=MAXV;i++)
      p[i] = (p[i-1]*2)%MOD;
for(int i=0;i<=MAXV;i++)
 {
    p[i]--;
    p[i] += MOD;
    p[i] %= MOD;
}
int n, m, t=1, x;
while(t--) {
    memset(mp,0,sizeof mp);
    si(n);
    si(m);
    for(int i=0;i<n;i++) {
        int val = 0;
        scanf("%s",str);
        for(int j=0;j<m;j++) {
            x = str[j]-'0';
            val = val*2 + x;
        }
        mp[val]++;
    }

    int req = 0;
    scanf("%s",str);
    for(int j=0;j<m;j++) {
         x = str[j]-'0';
         req = req*2 + x;
    }

      for(int i=0;i<20;i++)
        for(int j=0; j<=MAXV; j++) {
            if(j&(1<<i)) {
               mp[j] += mp[j^(1<<i)];
            }
        }

      int ans = 0;
      for(int j=req; j>=0; j--) {
        if((j|req)!=req)
            continue;
        if(__builtin_popcount(j^req)%2)
            ans = (ans - p[mp[j]] + MOD)%MOD;
        else
            ans = (ans + p[mp[j]])%MOD;
      }
      cout<<ans<<endl;
  }

}
