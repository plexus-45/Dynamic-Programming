//https://www.spoj.com/problems/DAGCNT2/

#include <bits/stdc++.h>
using namespace std;
#define ll int

const int N=20010;
vector<vector<ll>> g(N);
vector<ll> top_vec;
ll n,m;
ll id[N];
ll weight[N];
bitset<20010> reach[N];

void topsort(){
   
    stack<ll> st;
    for(ll i=1;i<=n;i++){
        if(id[i]==0){
            st.push(i);
        }
    }
    while(!st.empty()){
        ll x=st.top();
        top_vec.push_back(x);
        st.pop();
        for(auto it: g[x]){
            id[it]--;
            if(id[it]==0){
                st.push(it);
            }
        }
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){ 
        cin>>n>>m;
        for(ll i=1;i<=n;i++){
            cin>>weight[i];
        }

        for(ll i=1;i<=m;i++){
            ll a,b;
            cin>>a>>b;
            g[a].push_back(b);
            id[b]++;
        }

        topsort();
        for(ll i=1;i<=n;i++){
            reach[i].set(i);
        }

        for(ll i=top_vec.size()-1;i>=0;i--){
            for(auto it : g[top_vec[i]]){
                 reach[top_vec[i]] |=reach[it];
            }
        }

       for(ll i=1;i<=n;i++){
            ll val=0;
            for(ll j=1;j<=n;j++){
                if(reach[i][j]){
                    val+=weight[j];
                }
            }
            cout<<val<<" ";
       }
       cout<<"\n";

       for(ll i=1;i<=n;i++){
            g[i].clear(),id[i]=0,reach[i].reset();
        }
        top_vec.clear();
    } 
    return 0;
}
