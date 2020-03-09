/*
*Beautiful Pen*
You are given strings P1,P2,…,PK (each of which consists of characters from 'a', 'b', …, 't') ; for each valid i, the i-th pen can only write letters from the string Pi.You want to write a word S of length N. All the characters of S are between 'a' and 't' inclusive. This string must be written from left to right. To write it, you pick up some pen and start writing; after you've written some prefix of S, you can put down that pen, pick up another pen, continue writing S from the point where you put down the previous pen, later pick up another pen (any pen) and continue writing S with that pen, and so on until you write the whole string S. You may pick up each pen any number of times, including zero.

You have to find a way of writing the word S such that the number of times you change the pen (put down the pen you're currently writing with and pick up another) is the smallest possible. If there are multiple solutions, you may find any one. It is guaranteed that it is possible to write S with the given pens.
Input Format

The first line contains an integer T, followed by N numbers in the next line followed by characters in the next line
Constraints

There will T test cases, 1≤T≤10, 1<=N<=10^6 , 1<=K<=10^5, S, P1, P2, …Pk contains only characters ‘a’,’b’,….’t’. Length of Pi <=20 For each valid i, all characters of Pi are pairwise distinct. The sum of lengths of all the strings on the input does not exceed 2*10^6
Output Format

Output are numbers seprated by ' ' and followed by next line.
Sample Input

3
4 2
abcd
ab
cd
4 2
baab
ab
ca
4 2
acaa
ab
cd

Sample Output

1 1 2 2
1 1 1 1
1 2 1 1

------------------------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace std;


int n,k;
int pos[1<<20];
char s[1<<20];
char g[233];
#define lowbit(x) ((x)&(-x))
 

int main(){
     

     int t;
     cin>>t;
     while(t--){
        memset(pos,0,sizeof(pos));
        cin>>n>>k;
        cin>>s;
        for(int i=0;i<n;i++){
          s[i] -='a';
        }
        for(int i=0;i<k;i++){
          cin>>g;
          int mask=0,len=strlen(g);
          for(int j=0;j<len;j++){
              mask |=1<<(g[j]-'a');
          }
          pos[mask]=i+1;
        }

        for(int mask=(1<<20);mask>0;mask--){
            if(pos[mask]){
                 int temp=mask;
                 while(temp){
                     pos[mask^lowbit(temp)]=pos[mask];
                     temp^=lowbit(temp);
                 }
            }
        }


        int last=0;
        int mask=0;
        for(int i=0;i<n;i++){
           mask|=1<<s[i];
           if(!pos[mask]){
              int temp=pos[mask^1<<s[i]];
              for(int j=last;j!=i;j++){
                cout<< temp <<' ';
              }
              last=i;
              mask=1<<s[i];
           }
        }
        
        for(int i=last;i<n;i++){
          cout<<pos[mask]<<' '; 
        }
        cout<<'\n';
     }
     return 0;
 
}
