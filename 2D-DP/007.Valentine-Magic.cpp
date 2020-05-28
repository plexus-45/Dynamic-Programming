/*
It's Valentine's Day in Russia today. as we all know number of girls in Russia is more than number of boys :P hence boys have an extra advantage while choosing girl for the valentine evening. Each boy has certain number of chocolates and each girl has certain number of candies. Now you being the anchor of evening wants to pair all the boys with girls such that the sum of absolute difference between boy's chocolate and girl's candy in a pair is minimized. Ofcourse some of the girls will remain unpaired but that's okay as we are in Russia :P
Input Format

The first line consists of two integers N and M. then follow N integers in second line. Then follow M integers in third line. M >= N
Constraints

1 <= N <= 5000 1 <= M <= 5000 M >= N 1 <= chocolates <= 1000000 1 <= candies <= 1000000
Output Format

The only line which consists of required sum of absolute differences.
Sample Input

2 5
4 5
1 2 3 4 5

Sample Output

0

Explanation

we can pair boy numbered 1 with girl numbered 4 and boy numbered 2 with girl numbered 5

*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 50000000000
#define ll long long int
ll dp[5005][5005];

ll valentine(vector<ll> &choc,vector<ll> &candy,ll i,ll j){
    if(i == choc.size()){
        return 0 ;
    }
    if(j == candy.size()){
        return MAX;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    ll diff = abs(choc[i] - candy[j]) ;
    ll q1 = valentine(choc,candy,i+1,j+1) + diff;     // Pair ith boy with jth girl
    ll q2 = valentine(choc,candy,i,j+1) ;                  // Do not pair

    dp[i][j] = min(q1,q2);
    return dp[i][j]; 
}

int main() {
    
    ll n ; //No of boys
    ll m ; //No of girls
    cin >> n >> m;
    vector<ll> choc;
    vector<ll> candy;
    for(ll i=0;i<n;i++){
        ll x;
        cin >> x;
        choc.push_back(x);
    }
    for(ll i=0;i<m;i++){
        ll x;
        cin >> x;
        candy.push_back(x);
    }

    memset(dp,-1,sizeof(dp));

    sort(choc.begin(),choc.end());
    sort(candy.begin(),candy.end());

    cout << valentine(choc,candy,0,0) ;


    return 0;
}
