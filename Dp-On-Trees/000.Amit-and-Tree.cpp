/*
Amit has a rooted tree with root in the vertex 1, every vertex and every edge of which has a number written on. Let's call vertex v unstable if there is a vertex u in subtree of vertex v such that dist(v,u)>au, where au is the number written on vertex u, dist(v,u) is the sum of the numbers written on the edges on the path from v to u. Leaves of a tree are vertices connected to a single vertex by a single edge, but the root of a tree is a leaf if and only if the tree consists of a single vertex — root. Thus Amit decided to remove some of tree leaves until there will be no any unstable vertex left in the tree. What is the minimum number of leaves Amit needs to remove?
Input Format

In the first line of the input integer n is given — the number of vertices in the tree. In the second line the sequence of n integers a1,a2,…,an is given, where ai is the number written on vertex i. The next n-1 lines describe tree edges: ith of them consists of three integers ui ,vi and ci meaning that there is an edge between ui and vi with number ci written on it.
Constraints

1<=n<=10^5

1<=ai<=10^9

1<=ui,vi<=n

-10^9<=ci<=10^9
Output Format

Print the only integer — the minimum number of leaves Amit needs to remove such that there will be no any unstable vertex left in the tree.
Sample Input

9
88 22 83 14 95 91 98 53 11
2 3 24
3 7 -8
4 1 67
5 1 64
6 9 65
7 5 12
8 6 -80
9 3 8

Sample Output

5

Explanation

Final tree will have nodes 1,5,7,3 rest all nodes will be removed.




*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int n,x=0;
map<pair<int,int>,int> m;
vector<int> temp ;

void dfs(int start,int val,vector<int> &value,vector<vector<int>> &g,vector<int> &vis){
     
    vis[start]=1;
    if(value[start-1]<val){
        temp.push_back(start);
        return;
    }
    x++;
    for(int i: g[start]){
        if(vis[i]==1){
          continue;
        }
        vis[i]=1;
        int v=val;
        v+=m[{start,i}];
        if(v<0)
          v=0;
        dfs(i,v,value,g,vis);
    }

}


int main() {


     #ifndef ONLINE_JUDGE
       freopen("input.txt",  "r",  stdin);
       freopen("output.txt", "w", stdout);
     #endif

     cin>>n;
     vector<vector<int>> g(n+1);
     vector<int> vis(n+1);
     vector<int> value(n);
     for(int i=0;i<n;i++){
          cin>>value[i];
     }
     for(int i=0;i<n-1;i++){
          int a,b,c;
          cin>>a>>b>>c;
          g[a].push_back(b);
          g[b].push_back(a);
          m[{a,b}]=c;
          m[{b,a}]=c;
     }
    dfs(1,0,value,g,vis);
    cout<<n-x<<endl;

     return 0;
}  
