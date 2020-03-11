/*
https://codeforces.com/problemset/problem/1168/C
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
const int N = 3e5 + 7;
ll n,q,ar[N];
ll dist1to1[22][22];
ll mindist[N][22];
int main(){
 
    cin>>n>>q;
    for(ll i=1;i<=n;i++){
      cin>>ar[i];
    }
 
    for(ll i=0;i<=20;i++){
      for(ll j=0;j<=20;j++){
        if(i!=j){
          dist1to1[i][j]=INT_MAX;
        }
      }
    }
 
    for(ll i=n;i>=1;i--){
      vector<int> ones,zeros;
      for(ll j=0;j<=20;j++){
          if((1<<j)& ar[i]){
            mindist[i][j]=0;
            ones.push_back(j);
            for(ll k=0;k<=20;k++){
                if((1<<k)&ar[i]){
                   dist1to1[j][k]=0;
                }
            }
          }
          else{
            zeros.push_back(j);
          }
      }
      for(ll it0 : zeros){
        ll mi=INT_MAX;
        for(ll it1 : ones){
          mi =min(mi,dist1to1[it1][it0]);
        }
        for(ll it1 : ones){
            dist1to1[it1][it0]=mi;
        }
        mindist[i][it0]=mi;
      }
 
      for(ll j=0;j<=20;j++){
        for(ll k=0;k<=20;k++){
          if(k!=j)
            dist1to1[j][k]++;
        }
      }
    }
 
    while(q--){
       ll x,y;
       cin>>x>>y;
       ll mi =INT_MAX;
       for(ll j=0;j<=20;j++){
           if(ar[y] &(1<<j)){
              mi=min(mi,mindist[x][j]);
           }
       }
       if(mi<=(y-x)){
         cout<<"Shi"<<'\n';
       }
       else{
        cout<<"Fou"<<'\n';
       }
    }
    return 0;
 
}
