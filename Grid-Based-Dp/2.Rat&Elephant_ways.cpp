//Rat_version--single way for single possible path
// rat _(can be used in case of blocked cell)
int min_ways(int R,int C){

   for(int i=0;i<R;i++){
      for(int j=0;j<C;j++){
           
        if(i==0 and j==0){
          dp[i][j]=1;
        }
        else if(i==0){
            dp[i][j]=1;
        }
        else if(j==0){
            dp[i][j]=1;
        }
        else{
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
      }
   }
   return dp[R-1][C-1];
}

//rat- can't be used when any cell is blocked
long long int fact(int n){
    long long int fac=1;
    for(int i=1;i<=n;i++){
        fac*=i;
    }
    return fac;
}
long long int min_ways(int R,int C){
   return fact(R+C-2)/fact(R-1)*fact(C-1);
}

