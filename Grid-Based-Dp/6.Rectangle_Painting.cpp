//https://codeforces.com/problemset/problem/1198/D

#include<bits/stdc++.h>
using namespace std;
#define ll long long int


const int N = 55;
int dp[N][N][N][N],n;
char s[N][N];

int dfs(int x,int y,int z,int w){

   if(dp[x][y][z][w]!=-1){
     return dp[x][y][z][w];
   }

   if(x==z && y==w){
     return dp[x][y][z][w]=(s[x][y]=='#');
   }

   int ret=max(z-x+1,w-y+1);
   for(int i=x;i<z;i++){
          ret=min(dfs(x,y,i,w)+dfs(i+1,y,z,w),ret);
   }
   for(int i=y;i<w;i++){
          ret=min(dfs(x,y,z,i)+dfs(x,i+1,z,w),ret);
   }
   return dp[x][y][z][w]=ret;
}

int main(){
   scanf("%d",&n);
   memset(dp,-1,sizeof(dp));
   for(int i=1;i<=n;i++){
       scanf("%s",s[i]+1);
   }
   printf("%d\n",dfs(1,1,n,n));
   return 0;
}
