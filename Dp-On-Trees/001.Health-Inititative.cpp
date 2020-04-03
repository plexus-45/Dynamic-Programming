/*


Mr. Stark decided to go for morning walk everyday for a healthy lifestyle .He chose a community park which was near to his house .The park has multiple entrances and resting places in it collectively called as junctions of the park. All entrances and resting places are connected by walking tracks such that it is possible to go from each junction to other either directly or by a path. There are total N junctions in the park and N-1 walking tracks. Mr. Stark decided to enter from one entrance and exit from the other and walk the longest distance. Can you tell the longest distance Mr. Stark can walk in the park ?
Input Format

First line of the input contains a single integer representing the number of junctions N in the park. Next N-1 lines contains three integers A , B and C ,representing that junction A and junction B are connected by a bidirectional path of length C.
Constraints

0< N <=100000
1<= A,B <=N
1<= C <=100000
Output Format

Print a single integer representing the maximum distance Mr. Stark can walk .
Sample Input

5
1 2 1
2 5 10
2 3 2
3 4 3

Sample Output

15


*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int ans=0;
vector<vector<int>>g(100005);
map<pair<int,int>,int> m;

int dfs(int cur,int par){

     vector<int> ans_v;
     for(auto  i : g[cur]){
        if(i!=par)
          ans_v.push_back(m[{i,cur}]+dfs(i,cur));
     }
     sort(ans_v.rbegin(),ans_v.rend());
     if(ans_v.size()>1){
          ans=max(ans,ans_v[0]+ans_v[1]);
     }
     if(ans_v.size()==1){
          ans=max(ans,ans_v[0]);
     }
     if(ans_v.size()==0){
       return 0;
     }
     return ans_v[0];
}

int main() {

     #ifndef ONLINE_JUDGE
       freopen("input.txt",  "r",  stdin);
       freopen("output.txt", "w", stdout);
     #endif

     int n;
     cin>>n;

     for(int i=0;i<n-1;i++){
        int a,b,c;cin>>a>>b>>c;
        g[a].push_back(b);
        g[b].push_back(a);
        m[{a,b}]=c;
        m[{b,a}]=c;
     }
     dfs(1,0);
     cout<<ans;

     return 0;
}  
