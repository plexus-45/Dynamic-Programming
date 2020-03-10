//Little Elephant and T-Shirts : https://www.codechef.com/problems/TSHIRTS

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int stoi(string &s){
    stringstream ss(s);
    int x;
    ss>>x;
    return x;
}

int ALL_PERSON;
ll dp[(1<<10)+1][102];
vector<vector<int> > v;



ll func( int mask ,int id){
       
    if(mask==ALL_PERSON){
       return 1;
    }

    if(id==101){
        return 0;
    }

    if(dp[mask][id]!=-1){
        return dp[mask][id];
    }
    
    ll ans=0;
    ans= func(mask,id+1);
    for(int p: v[id]){
        if((mask&(1<<p))==0){
            ans+=func((mask|(1<<p)),id+1);
        }
    }
    ans%=mod;
    return dp[mask][id]=ans;
}



int main(){


    v.reserve(110);
    int t;
    cin>>t;

    while(t--){
        memset(dp,-1,sizeof(dp));
        int n;
        cin>>n;

        ALL_PERSON = (1<<n) - 1;

        string s;
        for(int i=0;i<=100;i++){
            v[i].clear();
        }

        cin.get();
        ///Created the Reverse Mapping from the input
        for(int i=0;i<n;i++){
            getline(cin,s);
            stringstream ss(s);
            string temp;
            while(ss>>temp){
                v[stoi(temp)].push_back(i);

            }

        }
         for(int i=0;i<=100;i++){
            sort(v[i].begin(),v[i].end());
        }
        cout<<func(0,1)<<endl;
    }
return 0;
}
