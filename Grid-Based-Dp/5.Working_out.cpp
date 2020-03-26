#include <bits/stdc++.h>
using namespace std;

const int N=1005;

int dp1[N][N]={0};
int dp2[N][N]={0};
int dp3[N][N]={0};
int dp4[N][N]={0};
int cal[N][N]={0};
int n,m;
void solve(){

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp1[i][j]=cal[i][j]+max(dp1[i-1][j],dp1[i][j-1]);
        }
    }

    for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++){
            dp2[i][j]=cal[i][j]+max(dp2[i+1][j],dp2[i][j-1]);
        }
    }

    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
            dp3[i][j]=cal[i][j]+max(dp3[i+1][j],dp3[i][j+1]);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            dp4[i][j]=cal[i][j]+max(dp4[i-1][j],dp4[i][j+1]);
        }
    }

    int ans=0;
    for(int i=2;i<n;i++){
        for(int j=2;j<m;j++){
            int ans1=dp1[i][j-1]+dp3[i][j+1]+dp2[i+1][j]+dp4[i-1][j];
            int ans2=dp1[i-1][j]+dp3[i+1][j]+dp2[i][j-1]+dp4[i][j+1];
            ans=max(ans,max(ans1,ans2));
        }
    }

    cout<<ans<<endl;
}


int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
          cin>>cal[i][j];
        }
    }
    solve();
    return 0;
}








