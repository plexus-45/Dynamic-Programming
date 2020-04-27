//https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/mehta-and-the-tricky-triplets/description/
//Mehta and the Tricky Triplets


#include <bits/stdc++.h> 
using namespace std; 
#define ll long long


ll n;
ll arr [100000 + 1];
ll dp [100000 + 1][4 + 1][16 + 1];
ll sett [100000 + 1];



ll solve(ll index,ll order,ll mask){

    if(index==n){
        if(order==3 && mask){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[index][order][mask]!=-1){
        return dp[index][order][mask];
    }

    ll ans= solve(index+1,order,mask);
    if(order<=2){
        ans+=solve(index+1,order+1,mask& sett[index]);
    }
    return dp[index][order][mask]=ans;
}



int main(){

    memset(dp, -1, sizeof dp);                      
    cin >>n;

    for(int i=0;i<n;i++){
        cin >> arr[i];
        while(arr[i] != 0){                         
            int digit = arr[i] % 10;                
            if(digit == 2) sett[i] |= (1 << 0);
            else if (digit == 3) sett[i] |= (1 << 1);
            else if (digit == 5) sett[i] |= (1 << 2);
            else if (digit == 7) sett[i] |= (1 << 3);
            arr[i] /= 10;
        }
    }
    cout << solve(0 , 0,(1<<4)-1) << "\n"; 
    return 0;
}
