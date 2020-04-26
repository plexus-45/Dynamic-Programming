// https://www.hackerrank.com/challenges/maximizing-xor/problem

#include <bits/stdc++.h> 
using namespace std; 

#define ll long long

int main(){

    ll l,r;
    cin>>l>>r;

    ll lxr=l^r;
    
    ll msb_pos=0;
    while(lxr){
        msb_pos++;
        lxr>>=1;
    }
    
    ll max_xor=0;
    ll one_mask=1;
    while(msb_pos--){
        max_xor+=one_mask;
        one_mask<<=1;
    }
    cout<<max_xor<<endl;
    return 0;
}
