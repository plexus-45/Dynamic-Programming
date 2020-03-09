
/*-----------------------------------------------------------------
Find the count of subarrays A[i..j] and A[k…l] such that bitwise AND of both subarrays is 0.
Input Format

The first line contains an integer N, followed by N numbers in the next line.
Constraints

N, size of array A is less than 2*100000

Ai<=100000
Output Format

Output a single number denoting the count of subarrays.
Sample Input
5
41 47 34 40 29

Sample Output
1

---------------------------------------------------------------------------------------------------*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007

const int N=1048576+5;

ll dp[N][22];
int cnt[N]{0};
int ar[N]{0};

int main(){
  
        int n,x,mask;
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>ar[i];
        }
        for(int i=1;i<=n;i++){
            ar[i]+=ar[i-1];
            cnt[ar[i]]++;
        }
        ll ans=0;
        for(int mask=0;mask<(1ll<<20);++mask){
            dp[mask][0]=cnt[mask];
            if(mask&1)
                dp[mask][0]+=cnt[mask^1];
            for(int p=1;p<=20;++p){
                dp[mask][p]=dp[mask][p-1];
                if(mask&(1<<p)){
                    dp[mask][p]+=dp[mask^(1<<p)][p-1];
                }
            }
        }
        for(int i=1;i<=n;++i){
            ans+=dp[(1LL<<20LL)-1LL-ar[i]][20];
        }
        cout<<ans/2<<endl;
    
}
