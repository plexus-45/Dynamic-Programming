//https://www.codechef.com/problems/FAMTREE
#include <bits/stdc++.h> 
using namespace std; 
#define ll long long

const int N=200010;
ll ans = 0,n;
vector < vector < ll > > g( N );
ll W[ N ], P[ N ];
ll ma[ N ], mi[ N ];



void dfs ( ll i, ll par ){
    for ( auto it : g[i] ){
        if ( it != par ){
            dfs(it,i);
            ma[i] = max(ma[i],ma[it]);
            mi[i] = min(mi[i],mi[it]);
        }
    }
    ma[i] = max(ma[i],W[i]);
    mi[i] = min(mi[i],W[i]);
    ans = max(ans,abs(W[i]-ma[i]));
    ans = max(ans,abs(W[i]-mi[i]));
}


int main(){

    cin >> n ;
    for ( ll i = 1; i <= n; i ++){
        ma[i] = INT_MIN;
        mi[i] = INT_MAX;
    }
    ll root = 0;
    for ( ll i = 1; i <= n; i ++){
        cin >> W[i];
    }
    for ( ll i = 1; i <= n; i ++){
        cin >> P[i];
        if ( P[i] == -1 ){
            root = i;
        }
        else{
            g[P[i]].push_back(i);
        }
    }
    dfs(root,0);
    cout << ans;
}
