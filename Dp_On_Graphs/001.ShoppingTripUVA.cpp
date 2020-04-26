//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=0&problem=2259&mosmsg=Submission+received+with+ID+24938147
//shopping trip-UVA
#include <bits/stdc++.h> 
using namespace std; 
#define ll long long


ll dist[55][55];
ll opera[55],save[55];
ll p;
ll dp[(1<<14)+10][14];

ll solve(ll mask,ll pos){


    if( mask==((1<<(p+1))-1) ) {
        return -dist[0][opera[pos]];
    }

    if(dp[mask][pos]!=-1){
        return dp[mask][pos];
    }

    ll ret=-dist[0][opera[pos]];
    for(ll i=1;i<=p;i++){
        if(!(mask&(1<<i))){
            ret=max(ret, solve(mask|(1<<i),i) + (save[i]-dist[opera[pos]][opera[i]]) );
        }
    }
    return dp[mask][pos]=ret;
}



int main(){
   

    #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif

    ll t;
    cin>>t;
    while(t--){
        ll roads,stores;
        cin>>stores>>roads;
        for(int i=0;i<=50;i++){
            for(int j=0;j<=50;j++){
                dist[i][j]=1e8;
            }
            dist[i][i]=0;
        }
        
        for(ll i=1;i<=roads;i++){
            ll u,v;
            double dollars;
            cin>>u>>v>>dollars;
            ll cost= (ll)round(dollars*100.0);
            dist[u][v]=min(dist[u][v],cost);
            dist[v][u]=min(dist[v][u],cost);
        }


        /* floyed warshal  */ 
        for(ll k=0;k<=stores;k++){
            for(ll i=0;i<=stores;i++){
                for(ll j=0;j<=stores;j++){
                   dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
       
        cin>>p;
        for(ll i=1;i<=p;i++){
            double dollars;
            cin>> opera[i]>>dollars;
            save[i]=(ll)round(dollars*100.0);
        } 
        memset(dp,-1,sizeof(dp));

        ll ans=solve(1,0);
        cout<<ans<<endl;
        if(ans<=0)
          cout<<"Don't leave the house\n";
        else
          cout<<"Daniel can save $"<<ans/100<<"."<<setw(2)<<setfill('0')<<ans%100<<"\n";
   }
   return 0; 
}
