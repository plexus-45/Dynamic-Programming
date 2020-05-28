#include <bits/stdc++.h> 
using namespace std; 

int dp[2001][2001];

int min(int x, int y, int z) { 
    return min(min(x, y), z); 
} 
  
int editDist(string str1, string str2, int m, int n) { 
    if(m == 0) 
        return n; 
    if(n == 0) 
        return m; 
    
    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    if(str1[m - 1] == str2[n - 1]){ 
        dp[n][m]=editDist(str1, str2, m - 1, n - 1); 
    }
    else{
        dp[n][m]=1+ min(editDist(str1, str2, m, n - 1), // Insert 
                     editDist(str1, str2, m - 1, n), // Remove 
                     editDist(str1, str2, m - 1, n - 1) // Replace 
                    );
    }             
    return dp[n][m]; 
} 
  
int main(){
    string a,b;
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    cout<<editDist(a,b,a.size(),b.size())<<endl;
    return 0;
}

