#include <bits/stdc++.h> 
using namespace std; 
#define ll int
 
#define INTMAX 1000000100
const int N=5005;
 
 
vector< vector<pair<ll,ll>>> adjlist(N);
pair<ll,ll> dp[N][N];
ll n,m,t;
ll id[N];
vector<ll> tsort;
 
void topsort(){
      stack<ll>s;
      for(ll i=1;i<=n;i++){
           if(id[i]==0){
            s.push(i);
           }
      }
      while(!s.empty()){
           int x=s.top();
           tsort.push_back(x);
           s.pop();
 
           for(auto it :adjlist[x]){
                id[it.first]--;
                if(id[it.first]==0){
                   s.push(it.first);
                }
           }
      }
}
 
 
int main(){
 
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        #endif
    cin>>n>>m>>t;
    while(m--){
        ll a,b,c;
        cin>>a>>b>>c;
        adjlist[a].push_back({b,c});
        id[b]++;
    }
    topsort();
   
    ll st=0;
 
   for(ll i=0;i<=n;i++){
      for(ll j=0;j<=n;j++){
        dp[i][j]={INTMAX,INTMAX};
      }
   }
 
 
    for(ll i=0;i<n;i++){
        if(tsort[i]==1){
            st=i;
            dp[1][1]={0,0};
            break;
        }
     }
   
     for(ll i=0;i<n;i++){
        for(ll j=1;j<=n;j++){
            ll node=tsort[i];
            if(dp[node][j].first != INTMAX){
               for(auto it: adjlist[node]){
                   ll mintime=dp[node][j].first + it.second;
                   if(mintime< dp[it.first][j+1].first){
                      dp[it.first][j+1].first=mintime;
                      dp[it.first][j+1].second=tsort[i];
                   }
                }
            }
        }
     }
    
    ll number_of_nodes=0;
    for(ll j=1;j<=n;j++){
        if(dp[n][j].first<=t){
           number_of_nodes=j;
        }
    }
 
    cout<< number_of_nodes<< endl;
    ll node=n;
    stack<ll> stac;
    while(number_of_nodes){
        stac.push(node);
        node=dp[node][number_of_nodes].second;
        number_of_nodes--;
    }
    
    while(!stac.empty()){
        cout<<stac.top()<<" ";
        stac.pop();
    }
    return 0;
}
 
