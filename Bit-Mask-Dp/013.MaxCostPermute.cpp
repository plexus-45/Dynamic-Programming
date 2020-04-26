/*


Given an array A we have to find a permutation with maximum cost where cost of a permutation P is defined as
P[i]*i for all i from 0 to n-1
Input Format

The first line contains an integer N, followed by N numbers in the next line denoting the elements of array A.
Constraints

N<=20
Ai<=20.
Output Format

Output is a single number denoting the maximum cost.
Sample Input

5
1 2 3 4 5

Sample Output

40

Explanation

Max cost can be obtained from permutation
{ 1, 2, 3, 4, 5 }



*/

#include <bits/stdc++.h> 
using namespace std; 

#define ll long long
int dp[(1<<20)];

int cnt_bit(int n){
    int ans=0;
    while(n){
        ans++;
        n>>=1;
    }
    return ans;
}

int solve(int mask,vector<int> &a,int n){

    if(mask==(1<<n)-1){
        return 0;
    }
    if(dp[mask]!=-1){
        return dp[mask];
    }
    int res=INT_MAX,cnt=cnt_bit(mask);
    for(int i=0;i<n;i++){
        if(!(mask & (1<<i))){
            res=min(res,solve(mask|(1<<i),a,n)+a[i]*cnt);
        }
    }
    return dp[mask]=res;
}



int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,a,n)<<endl;
	return 0;
}
