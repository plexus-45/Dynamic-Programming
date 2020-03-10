/*
//Submasks of Masks


You are given 3 arrays F,G,H each of size 2^N.

The value of the function R of a subset X of S is equal to the sum of F(A) × G(B) × H(C) for all triples (A, B, C) of subsets of S that cover X.

Your task is to calculate R(0) + R(1) + … + R(2^N - 1) modulo 1000000007(10^9 + 7).
Input Format

The first line contains an integer N, followed by N numbers in the next lines.
Constraints

N<=20 All other inputs are between 0 and 1000000007.
Output Format

Output is a single integer denoting the value.
Sample Input

2
1 3 9 12
0 5 1 2
2 3 4 1

Sample Output

7680
-----------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;

const int N=1<<20,P=1e9+7;
int n,f[N],g[N],h[N],dp[N];

 
int main(){

    ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=0;i<(1<<n);i++){
      cin>>f[i];
    }
    for(int i=0;i<(1<<n);i++){
      cin>>g[i];
    }
     for(int i=0;i<(1<<n);i++){
      cin>>h[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<n);j++){
           if(j>>i & 1){
              (f[j]+=f[j^(1<<i)])%=P;
              (g[j]+=g[j^(1<<i)])%=P;
              (h[j]+=h[j^(1<<i)])%=P;
           }
        }
    }

    for(int i=0;i< (1<<n);i++){
        dp[i]=1LL*f[i]*g[i]*h[i] % P;
        if(__builtin_popcount(i) & 1){
            dp[i]=P-dp[i];
        }
    }

    for(int i=0;i<n;i++){
      for(int j=0;j<(1<<n);j++){
        if(j>>i &1){
          (dp[j]+=dp[j^(1<<i)])%=P;
        }
      }
    }

    int ans=0;

    for(int i=0;i<(1<<n);i++){
        int cnt= __builtin_popcount(i);
        if(cnt & 1){
            dp[i]=P-dp[i];
        }
        (ans+=(1LL<<cnt)*dp[i]%P)%=P;
      }

      cout<<ans;

}
