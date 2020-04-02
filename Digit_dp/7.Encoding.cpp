//https://www.codechef.com/problems/ENCODING

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007


const int N=100005;
ll ps[101];
ll pw[N],lv[N],rv[N],a[N];

ll digit_dp(string s){

   int n=s.size()+1;
   

   for(int i=0;i<n;i++){
        a[i]=( i==0? 0 :s[i-1]-'0');
        lv[i+1]=( lv[i]*10+a[i])%mod;
   }

   rv[n]=0;
   for(int i=n-1;i>=0;i--){
       rv[i]=(rv[i+1]+ a[i] * pw[n-1-i])%mod;
   }


   ll ans=0;
   for(int i=1;i<n;i++){
 
      ll x= a[i-1]*10+a[i],ca=0;

      ca= lv[i-1]*pw[n-1-i] % mod *ps[100] % mod;
      ca=(ca+ ps[x]* pw[n-1-i])%mod;
    
      if(a[i-1]!=a[i]){
        ca=(ca+ a[i]*(rv[i+1]+1) )%mod;
      }
      ans = (ans + ca * pw[n - 1 - i]) % mod;
   }
   return ans;
}


int main(){

  #ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout); 
  #endif
 
  //gen _pow
  pw[0]=1;
  for(int i=0;i<N-1;i++){
    pw[i+1]=pw[i]*10 % mod;
  }

  for(int i=0;i<100;i++){
    ps[i+1]=ps[i]+( i/10 != i%10 ?  i%10 : 0);
  } 

  int t,nl,nr;
  string sl,sr;
  cin>>t;
  for(int i=0;i<t;i++){
    cin>>nl>>sl>>nr>>sr;
    for(int i=nl-1;i>=0;i--){
        if(sl[i]=='0'){
           sl[i]='9';
        }
        else{
          --sl[i];
          break;
        }
    }
    cout<<(digit_dp(sr)-digit_dp(sl)+mod)%mod<<"\n";
  }

}
