//SPECIAL PAIRS : https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/special-pairs-7/

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const int N=1ll<<20;
int cnt[N],dp[N][20];

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
     ll n,t;
     cin>>t;
     while(t--){
         memset(dp,-1,sizeof(dp));
         memset(cnt,0,sizeof(cnt));
         cin>>n;
         ll arr[n];
         for(int i=1;i<=n;i++){
            cin>>arr[i];
            cnt[arr[i]]++;
         }
         ll xo=(1<<20)-1,ans=0;
         for(int i=1;i<=n;i++){
             ll comp=xo^arr[i];
             ans+=solve(comp,19); 
         }

        cout<<ans<<endl;
     } 

 return 0;
}
