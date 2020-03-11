/*
https://hack.codingblocks.com/app/contests/204/p/814
Its Diwali time and everyone is busy decorating there homes using light bulbs. The light bulbs are arranged in a row. Little bob is bored of participating in contests so he decided to write 1 for every bulb which is on and 0 for every bulb which is off and creates an array of size equal to number of light bulbs. Since he is a bright kid he looks at his array and calculates the sum of all the adjacent pairwise products and wonders how many such combinations exist. More formally you are given an array of size n (consisting of 0 and 1 only) and k = a1a2 + a2a3 + a3a4 + … an-1an. You have to find out how many combinations of these light bulbs of size n (on and off) will give the sum of products equal to given value k. You have to calculate this value modulo 10^6+3.

Input Format
The first line consists of number of test cases. The second line consists of two values n and k.

Constraints
test cases <= 100 n <= 100 k <= 100

Output Format
The number of combinations modulo 10^6+3.

Sample Input
6
5 3
10 9
99 87
23 34
66 23
23 12
Sample Output
2
1
185141
0
375215
84498


*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000003

ll n,x;
ll dp[105][3][105];


ll f(ll i,ll prev,ll cnt){

  if(i==n){
    if(cnt==x){
      return 1;
    }
    return 0;
  }
  if(dp[i][prev][cnt]!=-1){
    return dp[i][prev][cnt];
  }
  ll ans=0;
  if(prev==1){
     ans=ans+ f(i+1,1,cnt+1);
  }
  else{
     ans=ans+ f(i+1,1,cnt);
  }
  ans%=mod;
  ans= ans+ f(i+1,0,cnt);
  ans%=mod;

  return dp[i][prev][cnt]=ans;

}

int main(){

    ll t;
    cin>>t;
    while(t--){
      memset(dp,-1,sizeof(dp));
      cin>>n>>x;
      cout<<(f(1,0,0)+f(1,1,0))%mod<<endl;
    }
    return 0;
}
