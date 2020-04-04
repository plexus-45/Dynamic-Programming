/*


Two friends Alice and Bob decided to start coffee shops in TreeLand. TreeLand is a country consisting of N cities 
arranged in the form of a Tree .(Undirected Connected Acyclic Graph) .Both friends wanted build their shops at same
place but they were told that to avoid competition,the shops must be exactly K units away from each other .(The distance 
between two cities is the number of edges in the path between the two cities) Now Alice and Bob wonders ,what can be the 
possible number of pairs of cities so that distance between them is exactly K units. Can you help them?

Input Format

First line of the input contains two integer numbers representing the number of cities N present in TreeLand and
required distance K. Next N-1 lines contains two integers A and B ,representing that city A and city B are connected
by a direct edge.

Constraints

0<N<=100000
0<K<=10
Output Format

Output a single integer representing the number of pairs of cities having distance exactly K.
Sample Input

6 2
1 2
1 3
3 4
3 5
4 6

Sample Output

5

Explanation

(The required pairs will be {1,4} , {2,3} , {3,6} , {4,5} , {1,5}.)



*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g(100005);
vector<int> vis(100005);
int ans=0;

vector<int> dfs(int cur,int k){
    

     vis[cur]=1;
     vector<vector<int>> p;
     for(int i : g[cur]){
          if(!vis[i]){
               p.push_back(dfs(i,k));
          }
     }

     //dp[i] represents the number of nodes at distance i from the current node in its subtree
     vector<int> dp(12);
     for(int i=0;i<12;i++){
        for(int j=0;j<p.size();j++){
           dp[i+1]+=p[j][i];
        }
     }
    

     dp[0]=1;
     int t=0;
     t+=dp[k]*2;  ///number of pairs starting from current vertex and ending at another node in subtree
     for(int i=0;i<=k;i++){
          for(int j=0;j<p.size();j++){                    
              if(k-i-2>=0){
                 t+=p[j][i]*(dp[k-1-i]-p[j][k-i-2]); //number of pairs starting and ending in the subtree
              }

          }
      }
      ans+=t/2;
      return dp;

}

int main(){
    
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    dfs(1,k);
    cout<<ans;
}

