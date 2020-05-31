#include <bits/stdc++.h>
using namespace std;

bool isMatch(const string A, const string B){
    int m=A.size(),n=B.size();
    vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
    dp[0][0]=true;
    for(int j=0;j<=n;j++){
        if(B[j-1]=='*')
            dp[0][j]=dp[0][j-1];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(B[j-1]=='*')
                dp[i][j]=dp[i-1][j]||dp[i][j-1];
            else if(B[j-1]=='?' || A[i-1]==B[j-1])
                dp[i][j]=dp[i-1][j-1];
        }
    }
    return dp[m][n];
}

int main(){

    string str,pat;
    cin>>str>>pat;
    bool val=isMatch(str,pat);
    if(val){
        cout<<1<<'\n';
    }
    else
       cout<<0<<'\n';
    return 0;
}
