//https://www.hackerearth.com/problem/algorithm/pr-numbers-160aa0c9/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[19][2][2][2][2][2][2][3][5][7];

string number;
string to_string_(ll num){
    stringstream ss_var;
    ss_var<<num;
    return ss_var.str();
}

ll digit_dp(int pos,int flag,int two,int three,int five,int seven,int r2,int r3,int r5,int r7,int prev){
   
     if(number.size()==pos){
          if(two && (r2!=0)) return 0;
          if (two && (r2 != 0)) return 0;
          if (three && (r3 != 0)) return 0;
          if (five && (r5 != 0)) return 0;
          if (seven && (r7 != 0)) return 0;
          return 1; 
     }     
     if (dp[pos][flag][two][three][five][seven][r2][r3][r5][r7] != -1)
       return dp[pos][flag][two][three][five][seven][r2][r3][r5][r7];
     
     ll ans=0;
     int limit = number[pos] - '0';
     for(int i=0;i<10;i++){
          if (!flag && i>limit) break;
          if (__gcd(prev,i) == 1) continue;
          ans+=digit_dp(pos+1,flag|(i<limit),(i==2)|two,(i==3)|three,(i==5)|five,(i==7)|seven,(r2*10+i)%2,(r3*10+i)%3,(r5*10+i)%5,(r7*10+i)%7,i);
     }
     return dp[pos][flag][two][three][five][seven][r2][r3][r5][r7] = ans;

}

int main() {
     #ifndef ONLINE_JUDGE
       freopen("input.txt",  "r",  stdin);
       freopen("output.txt", "w", stdout);
     #endif
  
    // int t;
    // cin>>t;
    // while(t--){
          ll l,r;
          cin>>l>>r;
          number=to_string_(r);
          memset(dp,-1,sizeof(dp));
          ll pr_less_r=digit_dp(0,0,0,0,0,0,0,0,0,0,0);
          number=to_string(l-1);
          memset(dp,-1,sizeof(dp));
          ll pr_less_l=digit_dp(0,0,0,0,0,0,0,0,0,0,0);
          if(l==1){
               pr_less_l=0;
          }
          cout<<pr_less_r - pr_less_l<<endl;
    // }
     return 0;
}  
