//https://www.codechef.com/problems/WITBIT

#include "bits/stdc++.h"
using namespace std;
using ll = long long;


const int N=70;
int base[N],idx;
ll dp[N][2][2][2][2];

void make_bin(ll x){
     idx=0;
     do{
        base[++idx]=x&1;
        x/=2;
     }while(x>0);

     while(idx<66){
          base[++idx]=0;
     }
     reverse(base+1,base+1+idx);
}

bool pat_110(bool a,bool b,bool c){
     return a && b && !c;
}



ll digit_dp(int pos,bool lo,bool yet,bool prev,bool pre_prev){

     if(pos>idx){
        return yet;
     }
     if (dp[pos][lo][yet][prev][pre_prev] != -1)
       return dp[pos][lo][yet][prev][pre_prev];

     ll ret=0;
     int to=lo?1:base[pos];
     for(int cur=0;cur<=to;cur++){
            ret+=digit_dp(pos+1,lo|(cur<base[pos]),yet|pat_110(pre_prev,prev,cur),cur,prev);
     }
     return dp[pos][lo][yet][prev][pre_prev] = ret;
}


ll get(ll x){
     if(!x)
       return 0;
     make_bin(x);
     memset(dp,-1,sizeof(dp));
     return digit_dp(1,0,0,0,0);
}

int main(){
    #ifndef ONLINE_JUDGE
     freopen("input.txt",  "r",  stdin);
     freopen("output.txt", "w", stdout);
    #endif
     
     int tt;
     scanf("%d" , &tt);
     while (tt--) {
          ll l , r;
          scanf("%lld %lld", &l, &r);
          printf("%lld\n" , get(r) - get(l - 1));
     }
     return 0;
}
