// https://www.codechef.com/problems/AOPN

#include <bits/stdc++.h> 
using namespace std; 
#define ll long long

ll t;
string s;
ll dp[ 20 ][ 11 ][ 11 ][ 2 ][ 2 ][ 2 ][ 2 ];


ll solve(ll pos,ll las,ll slas,bool tight,bool odd,bool even,bool st ){
   
    if ( pos == s.size() )
        return (odd and even);

    if ( dp[pos][las][slas][tight][odd][even][st] != -1 )
        return dp[pos][las][slas][tight][odd][even][st];
        
    ll ret = 0;
    if ( st == 0 ){
        ret = solve(pos+1,las,slas,tight&(s[pos]=='0'),odd,even,st);
        ll en = (tight?(s[pos]-'0'):9);
        for ( ll i = 1; i <= en; i ++){
            ret += solve(pos+1,i,slas,tight&(i==en),odd,even,1);
        }
    }
    else{
        ll en = (tight?(s[pos]-'0'):9);
        for ( ll i = 0; i <= en; i ++){
            ret += solve(pos+1,i,las,tight&(i==en),odd|(i==slas),even|(i==las),1);
        }
    }
    return dp[pos][las][slas][tight][odd][even][st] = ret;
}


int main(){

    cin >> t;
    while ( t-- ){
        string a,b;
        cin >> a >> b;
        s = b;
        memset(dp,-1,sizeof dp);
        ll ans = 0;
        ans = solve(0,10,10,1,0,0,0);
        s = a;
        memset(dp,-1,sizeof dp);
        ans -= solve(0,10,10,1,0,0,0);
        cout << ans <<"\n";
    }
    return 0;
}
