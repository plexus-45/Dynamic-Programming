// https://discuss.codechef.com/t/colorful-knapsack-problem-directi-interview/19980

#include <bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>> color;
int ans;
int dp[101][10001];

int solve(int pos,int x){

    if(dp[pos][x]!=-1){
        return dp[pos][x];
    }

    int res=0;
    if(pos>color.size()){
        ans=min(ans,x);
        return 0;
    }

    for(auto it: color[pos]){
        if(x>=it){
            res=max(res,solve(pos+1,x-it));
        }
    }
    return dp[pos][x]=res;
}


int main(){

    int n,m,x;
    cin>>n>>m>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    memset(dp,-1,sizeof dp);
    color.clear();
   
    for(int i=0;i<n;i++){
        int y;
        cin>>y;
        color[y].push_back(a[i]);
    }
    ans=INT_MAX;
    for(auto it: color){
        sort(it.second.begin(),it.second.end());
    }

    int xx=solve(1,x);
    if(ans==INT_MAX){
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;
    return 0;
}
