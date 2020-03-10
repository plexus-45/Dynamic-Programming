https://hack.codingblocks.com/app/contests/141/p/1025

/*

Vipul wants to buy his favourite bike Royal Enfield.
The bike is priced at N dollars. He already has the amount with him and wants to take his girlfriend for a ride but she poses a condition and asks him a question.
She always gives him challenging tasks and this time she gives him a number M and asks him to find out how many numbers can be formed by rearranging digits of number N whose modulo M is 0?
NOTE :- You have to permute digits of N and only consider the numbers which do not have leading zeroes.

Input Format
First line consists of number of test cases T. Each test case consists of number N and M.

Constraints
1 <= N <= 10^18 1 <= M <= 100

Output Format
The answer for every test case in a new line.

Sample Input
1
223 4
Sample Output
1
Explanation
The numbers formed on rearrangement are 232 , 223 , 322 out of which only 232 % 4 = 0.

---------------------------------------------
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

string s;
ll dp[(1<<19)+1][101];
ll MOD;

ll solve(ll mask,ll m){
     
    if(mask==(1<<s.size())-1){
        return (m==0);
    }
    if(dp[mask][m]!= -1){
        return dp[mask][m];
    } 
    ll ans=0;
    bool ch[10];
    memset(ch,0,sizeof(ch));
    for(ll i=0;i<s.size();i++){
        if(s[i]=='0'){
            if(mask==0){
                continue;
            }
        }
        if((!(mask&(1<<i))) and (!(ch[s[i]-'0']))){
            ans =(ans+solve(mask|(1<<i),(m*10+(s[i]-'0'))%MOD));
            ch[s[i]-'0']=1;
        }

    }
    return dp[mask][m]=ans;
}

int main(){
 
   int t;
   cin>>t;
   while(t--){
       memset(dp,-1,sizeof(dp));
       cin>>s>>MOD;
       cout<<solve(0,0)<<"\n";
   }
    
   return 0;
}

