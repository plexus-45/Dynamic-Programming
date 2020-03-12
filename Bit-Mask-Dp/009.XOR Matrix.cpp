/*


You are given a matrix A of size nxm. Find any suitable integer sequence C of size n such that A[1][c[1]]^A[2][c[2]]^….^A[n][c[n]] is greater than 0. Output Format : IF there is no solution , just print “NIE” , otherwise first print “TAK” and then print configuration.
Input Format

Given a matrix of A of size (n X m)
Constraints

n, m<=500, A[i][j]<1024
Output Format

If there is no solution , just print “NIE” , otherwise first print “TAK” and then print configuration.
Sample Input

3 2
0 0
0 0
0 0

Sample Output

NIE





*/


#include <iostream>
using namespace std;
int n,a[555][555],b[555],i,j,m,x;
int main(){
    cin>>n>>m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++) 
          cin>>a[i][j];
        x^=a[i][0];
        b[i]=1;
    }
    if(!x){
        for(i=0;i<n;i++)
            for(j=1;j<m;j++)
                if(a[i][j]!=a[i][0]){
                   b[i]=j+1; 
                   j=m;
                   i=n;
                   x=1;
                 }
    }
    if(!x) {cout<<"NIE"; return 0;}
    cout<<"TAK\n";
    for(i=0;i<n;i++) cout<<b[i]<<" ";
    return 0;
}
