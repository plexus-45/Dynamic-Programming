// https://www.geeksforgeeks.org/sum-of-bitwise-or-of-all-subarrays/

#include <bits/stdc++.h> 
using namespace std; 
#define ll long long

int solve(int a[],int n){
    int ans=0,sum=0;
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum=sum|a[j];
            ans+=sum;
        }
    }
    return ans;
}

int main(){
   
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<solve(a,n)<<endl;
    return 0; 
}
