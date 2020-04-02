#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007


int mx;
string v;
ll dp[50][18][18][18];

ll digit_dp(int pos,bool flag,int cn3,int cn6,int cn9){

    if(cn3>=18 or cn6 >=18 or cn9>=18){
      return 0;
    }
    if(pos==-1){
      return cn3==cn6 and cn6==cn9 and (cn3!=0);
    }
    ll &ret=dp[pos][cn3][cn6][cn9];
    
    if(!flag and ret !=-1){
       return ret % mod;
    }
   
    ll ans=0;
    int k=flag? v[pos]-'0':9;
    for(int i=0;i<=k;i++){
         ans+= (digit_dp(pos-1,flag and (i==k),(i==3)+cn3,(i==6)+cn6,(i==9)+cn9)%mod)%mod;
    }
    return flag? ans : ret=ans;

}



ll  process(string x){
   v=x;
   mx=v.size();
   reverse(v.begin(),v.end());
   return digit_dp(mx-1,true,0,0,0);
}

int main(){

  #ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout); 
  #endif

  int t;
  cin>>t;
  char a[100],b[100];
  memset(dp,-1,sizeof(dp));
  while(t--){
    scanf("%s %s",a,b);
    ll ans=process(b)-process(a);
    int sz=strlen(a),c3=0,c6=0,c9=0;
    for(int i=0;i<sz;i++){
      if(a[i]=='3') c3++;
      if(a[i]=='6') c6++;
      if(a[i]=='9') c9++;
    }
    if(c3==c6 and c6==c9 and c3!=0){
      ans++;
    }
    printf("%lli\n",(ans+mod)%mod);
  }

}
