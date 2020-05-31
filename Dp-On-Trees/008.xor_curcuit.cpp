/*https://www.codechef.com/problems/DAGXOR */

#include<bits/stdc++.h>
using namespace std;
#define ll long long int


ll t,n;
ll dp[ N ][ 4 ];
vector < vector < ll > > adjlist ( N );

ll dfs ( ll i, ll xo, ll par ){
    if ( i == n )
        return (xo==0);
    if ( dp[i][xo] != -1 )
        return dp[i][xo];
    ll ch = 0;
    ll ret = 0;
    for ( ll k = 0; k <= 3; k ++){
        ll vl = 1;
        for ( auto it : adjlist[i] ){
            if ( it != par ){
                ch ++;
                vl = (vl*1LL*dfs(it,xo^k,i))%mod;
            }
        }
        ret = ( ret + vl )%mod;
    }
    if ( ch == 0 ){
        ll ret = 0;
        for ( ll k = 0; k <= 3; k ++){
            ret = ( ret + dfs(n,xo^k,i))%mod;
        }
        return dp[i][xo] = ret;
    }
    return dp[i][xo] = ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    // 00 01 01 01 
    // 10 01 01 11
    // 11 01 01 10
    cin >> t;
    while ( t-- ){
        cin >> n;
        for ( ll i = 1; i <= n-2; i ++){
            ll a,b;
            cin >> a >> b;
            adjlist[a].pb(b);
            adjlist[b].pb(a);
        }
        ll ans = 0;
        memset(dp,-1,sizeof dp);
        ans = (dfs(1,0,0)*4LL)%mod;
        cout << ans <<"\n";
        for ( ll i = 1; i <= n; i ++)
            adjlist[i].clear();
    }
}
