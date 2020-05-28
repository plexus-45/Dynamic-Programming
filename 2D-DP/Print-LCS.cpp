#include <bits/stdc++.h>
using namespace std;
#define ll long long int

string lcs(string a ,string b){

    int la=a.size();
    int lb=b.size();
    int dp[1001][1001]={0};

    for(int i=0;i<=la;i++){
      dp[i][0]=0;
    }
    for(int i=0;i<=lb;i++){
      dp[0][i]=0;
    }
   
    for(int i=1;i<=la;i++){
      for(int j=1;j<=lb;j++){
        if(a[i-1]==b[j-1]){
          dp[i][j]=dp[i-1][j-1]+1;
        }
        else{
          dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
      }
    }

    int i=la,j=lb;
    string ans="";
    while(i>0 && j>0){
     
       if(a[i-1]==b[j-1]){
          ans=a[i-1]+ans;
          i--;
          j--;
       }
       else if(dp[i-1][j]>dp[i][j-1]){
          i--;
       }
       else{
          j--;
       }
    }
    return ans;
}    

int main(){
   
   string a,b;
   cin>>a>>b;
   string ans=lcs(a,b);
   cout<<ans<<'\n';

}
