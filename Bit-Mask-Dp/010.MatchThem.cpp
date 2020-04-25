//https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/string-matching-google-3dc355a5/
//String Matching-HackerEarth

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll cnt[100005][10],hm[10],ans;

int main(){

    memset(hm,0,sizeof(hm));
    memset(cnt,0,sizeof(cnt));
    ans=0;
    string x;
    cin>>x;
    ll n=x.size();
    ll m;
    cin>>m;
    for(ll i=0;i<m;i++){
    	ll y;
    	cin>>y;
    	hm[y]++;
    }

    for(int i=0;i<n;i++){
    	cnt[i][x[i]-'0']++;
    	if(i>=1){
    		for(int j=0;j<=9;j++){
    			cnt[i][j]+=cnt[i-1][j];
    		}
    	}
    }


    for(int i=0;i<n;i++){

        ll lo=i,hi=n-1,id=-1;
        while(lo<=hi){
            ll mid=(lo+hi)/2;
            bool check=1;
            for(int j=0;j<=9;j++){
            	if(i>=1){
            		if(hm[j]>cnt[mid][j]-cnt[i-1][j]){
            		   check=0;
            		}
            	}
            	else{
            		if(hm[j]>cnt[mid][j]){
            			check=0;
            		}
            	}
            }
            if(check){
            	id=mid;
            	hi=mid-1;
            }
            else{
            	lo=mid+1;
            }
        }


        if(id!=-1){
        	ans+=(n-id);
        }
    }
    cout<<ans<<endl;
    return 0;
}
