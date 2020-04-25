// https://www.spoj.com/problems/PT07Z/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
vector<vector<ll>> g(10002);
ll max_depth[10002];
ll ans=0;

void dfs(ll i,ll par){
    ll mx1=0,mx2=0;
    for(ll it : g[i]){
        if(it!=par){
            dfs(it,i);
            if(max_depth[it]+1>=mx1){
                ll temp=mx1;
                mx1=max_depth[it]+1;
                mx2=temp;
            }
            else if(max_depth[it]+1>mx2){
                mx2=max_depth[it]+1;
            }
        }
    }
    max_depth[i]=mx1;
    ans=max(ans,mx1+mx2);
}
int main() {

    cin>>n;
    for(int i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    cout<<ans<<"\n";
    return 0;
}
