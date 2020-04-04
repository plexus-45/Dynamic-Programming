/*


During a fierce storm ,the great sailor Popeye got shipwrecked .He ,being the only survivor from the crew got marooned 
on a strange uninhabited island . In search of food ,he found a magic tree with N nodes in it .The tree was protected by 
a golden fairy.On each node ,there is an integer written on it . The fairy promised Popeye that if he is able to select 
exactly two non intersecting subtrees of this tree ,then she will give Popeye gold coins equal to the sum of values on all
nodes of both the subtrees .Popeye being poor in mathematics asks you to find the maximum coins he can get (if any).
Popeye cannot select only one subtree .He must select two subtrees or none at all .
(Two subtrees are non intersecting if they do not have any node in common.)

Note: The nodes can have negative values .If total sum is negative , Popeye will not get any coins .

Input Format
First line of the input contains single integer representing the number of nodes N in the tree . Second
line contains N integers a1,a2,a3…..an representing the value on each node . Next N-1 lines contains two
integers A and B ,representing that node A and node B are connected .

Constraints
0<N<=100000
-100000<=ai<=100000 (Value on node)

Output Format
Print a single integer representing the maximum coins Popeye can get .

Sample Input
5
-20 -1 8 1 7
1 2
1 4
2 3
2 5

Sample Output
15

Explanation
The best choice is to choose subtrees having node 3 and node 4 only .
*/

#include<bits/stdc++.h>
using namespace std;

const int N=100005;
vector<int> values(N),subtree_sum(N),max_subtree(N);
vector<vector<int>> g(N),directed_tree(N);

int dfs1(int a,int par){
     int tmp=0;
     for(int i: g[a]){
        if(i!=par){
          directed_tree[a].push_back(i);
          tmp+=dfs1(i,a);
        }
     }
     subtree_sum[a]=values[a]+tmp;
     return values[a]+tmp;
}


int dfs2(int a,int par){
     int tmp=subtree_sum[a];
     for(int i :g[a]){
        if(i!=par){
          tmp=max(tmp,dfs2(i,a));
       }
     }
     max_subtree[a]=tmp;
     return tmp;
}

int main(){
    
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++){
       cin>>values[i];
     } 
     
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(1,0);
    dfs2(1,0);
    int ans=0;
    for(auto a:directed_tree){
        vector<int>all_values;
        for(auto b:a){
            all_values.push_back(max_subtree[b]);
        }
        sort(all_values.rbegin(),all_values.rend());
        if(all_values.size()>1){
            ans=max(ans,all_values[0]+all_values[1]);
        }
    }
    cout<<ans;
}
