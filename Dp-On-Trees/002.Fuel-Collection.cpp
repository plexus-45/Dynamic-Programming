/*


In the great Battle of Blocksland ,Private X and his battalion were pinned down by the enemy forces .Lack of fuel in their tanks corps made the retreat of his battalion impossible .Luckily ,a fuel dump was discovered by some soldiers . The fuel dump consisted of N fuel drills which are connected by
N-1 link roads .Travelling each link node requires a specific amount of fuel .Each fuel drill contains a specified amount of oil represented by ai ( fuel in the ith drill ). The fuel dump was unreachable by land ,so the airforce offered to airdrop Private X with a fuel container on a specific location and airlift him back from another different location. Airdrop and airlift location can be same . What is the maximum fuel that Private X can get considering the size of fuel container as infinite ?
Input Format

The first line contains a single integer N – the number of fuel drills . The second line contains N integers a1,a2,a3…….an representing the fuel in each of N drills. Each of the next n-1 lines describes link roads and contains three integers A,B,C representing fuel drill A and B are connected by a link road which take C amount of fuel to traverse .
Constraints

0<N<=100000

0<=ai<=1000000000(amount of fuel on ith drill)

1<=A,B<=N
Output Format

Print a single integer representing the maximum fuel that Private X can get .
Sample Input

5
6 3 2 5 0
1 2 10
2 3 3
2 4 1
1 5 1

Sample Output

7

Explanation

The optimal way will be 2->4 .
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int


const int N = 100005;
int n;
vector<int> fuel(N);
vector<vector<int>> g(N);
vector<int> vis1(N),vis2(N);
vector<vector<int>> val(N);
map<pair<int,int>,int> m;


void dfs1(int a,int b){
    if(vis1[a]){
      return;
    }
    vis1[a]=1;
    if(b<0){
     b=0;
    }
    val[a].push_back(b);
    b+=fuel[a];
    for(auto i : g[a]){
        dfs1(i,b-m[{i,a}]);
    }
}


int dfs2(int a){
   
    if(vis2[a]){
      return 0;
    }
   
    vis2[a]=1;
    int mx=0;
    for(auto i : g[a]){
        int k=dfs2(i)-m[{i,a}];
        if(k>-1){
          val[a].push_back(k);
        }
        mx=max(mx,k);
    }
    return mx+fuel[a];
}




int main() {

     #ifndef ONLINE_JUDGE
       freopen("input.txt",  "r",  stdin);
       freopen("output.txt", "w", stdout);
     #endif

    cin>>n;
    for(int i=1;i<=n;i++)cin>>fuel[i];
    for(int i=0;i<n-1;i++){
        int a,b,d;cin>>a>>b>>d;
        m[{a,b}]=d;
        m[{b,a}]=d;
        g[a].push_back(b);
        g[b].push_back(a);
    }
   
    dfs1(1,0);//dfs to kedane algo on tree
    dfs2(1);//dfs to fill max value paths starting from a particular node
    int ans=0;
    
    for(int i=1;i<=n;i++){
        sort(val[i].rbegin(),val[i].rend());
        if(val[i].size()==1){
            ans=max(ans,fuel[i]+val[i][0]);
        }
        else if(val[i].size()>1){
            int k=fuel[i];
            if(val[i][0]>0)k+=val[i][0];
            if(val[i][1]>0)k+=val[i][1];//picking best two values and making the current node as the central node
            ans=max(ans,k);
        }
    }
    cout<<ans;
    return 0;
}  
