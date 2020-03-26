#include <bits/stdc++.h>
using namespace std;
const int N=1002;

int mat[N][N]={0};
int dp[N][N]={0};
int n,m,x,y;

void gen_dp(){

    dp[0][0]=mat[0][0];
    for(int j=1;j<n;j++){
        dp[0][j]=dp[0][j-1]+mat[0][j];
    }

    for(int i=1;i<n;i++){
        dp[i][0]=dp[i-1][0]+mat[i][0];
    }
     
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1])+mat[i][j];
        }
    } 
    return;

}


int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
       cin>>x>>y;
       mat[x-1][y-1]=1;
    }
    gen_dp();
    //calculating the ans
     int ans=0;
     for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            int as1=dp[x][y];
            int as2=dp[x][n-1]-dp[x][y];
            int as3=dp[n-1][y]-dp[x][y];
            int as4=dp[n-1][n-1]-as1-as2-as3;
            ans=max(ans,min(min(as1,as2),min(as3,as4)));        
        }
    }     
    cout<<ans<<endl;
    return 0;
}

