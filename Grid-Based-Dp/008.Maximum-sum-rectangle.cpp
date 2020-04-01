#include<bits/stdc++.h>  
using namespace std;  

int tt,n,m;
int a[12][12];

int kadane(int *arr){

	int sum=0,max_sum=INT_MIN;
  int fin=-1;
	for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum<0){
           	sum=0;
        }
        else if(sum>max_sum){
        	max_sum=sum;
        	fin=i;
        }
	}

	if(fin!=-1){
		return max_sum;
	}

    max_sum = *max_element(arr,arr+n);
	return max_sum; 
}

void solve(){

	int max_sum=INT_MIN,sum;
	int temp[n];
	for(int l=0;l<m;l++){
		memset(temp,0,sizeof(temp));
	    for(int r=l;r<m;r++){
	    	for(int i=0;i<n;i++){
	    		temp[i]+=a[i][r];
	    	}
            sum=kadane(temp);
            if(sum>max_sum){
            	max_sum=sum;
            }
	    }
	}
    cout<<max_sum<<endl;
}


int main(){
   
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
   cin>>tt;
   while(tt--){
      cin>>n>>m;
      for(int i=0;i<n;i++){
   	     for(int j=0;j<m;j++){
   	  	  cin>>a[i][j];
   	     }
      }
      solve();
   }
   return 0;

}
