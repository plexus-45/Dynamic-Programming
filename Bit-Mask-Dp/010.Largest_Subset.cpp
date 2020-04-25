//https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/sherlock-and-coprime-subset/description/
//Sherlock and Coprime Subset

#include<bits/stdc++.h>
using namespace std;

int n,p;
int prime[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int dp[105][(1<<15)+10];
int arr[105];


int solve(int cur,int mask){
     
    if(cur==n || mask==p){
        return 0;
    }


    if(dp[cur][mask]!=-1){
       return dp[cur][mask];
    }
    
    int q=solve(cur+1,mask);
    
    if(arr[cur]==1){
        return dp[cur][mask]=q+1;
    }

    int temp=mask;
    for(int i=0;i<15;i++){
        if(arr[curr]%prime[i]==0){
            if(mask & (1<<i)){
                dp[cur][temp]=q;
            }
            mask=mask|(1<<i);
        }
    }
    return dp[cur][temp]=max(1+solve(cur+1,mask),q);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        p=(1<<n)-1;
        memset(dp,-1,sizeof(dp));
        cout<<solve(0,0)<<endl;
    }
    return 0;
}
