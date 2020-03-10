/*
    * Trie or Bitmasks *


Initially you are given an empty list.Furthermore you will be given some query to perform. There are three types of query, first "add s" that means you should add s to your list, second "del s" that means you should delete one occurence of s from your list , and last will be "count s" that asks you for count of integers which are there in the list such that (s&a)=a.For each thrd type of query , you should output answer in a new line.
Input Format

The first line contains N integer followed by N queries in the next lines
Constraints

Q<=200000 , 1<=s<=(2^16)
Output Format

Output numbers separated by a new line
Sample Input

7
add 11
cnt 15
add 4
add 0
cnt 6
del 4
cnt 15

Sample Output

1
2
2


Explaination:

     Let's look at the numbers in their binary representation ,since all numbers are less than 2^16 then binary 
    representation of each number will have at most 16 bits note that A and B = A if and only if for every i: If
    the i'th bit of A is 1 then i'th bit of B is 1 so if i'th bit of B is 0 , then i'th bit of A must be 0 , but 
    if i'th bit of B is 1 then i'th bit of A can be 0 or 1 so for a fixed B the number of numbers A which satisify 
    A and B = A is 2^(number of 1 bits in B

    So let's try this solution: Let's have an array C with indices from 0 to 2^16-1 , initially all values are zero
    Whenever we have to add a number S then we increment the value of C[S] by 1 Whenever we have to do cnt operation
    with the given number S , then generate all numbers X such that X and S = X And compute the sum Of C[X] for all 
    numbers X Add operation is O(1) but cnt operation is O(2^16) worst case so the solution will not fit in time limit
    

    Let's try another solution: We have the same array C as previous solution During add S operation we generate all
    numbers X such that X and S = S and for each X we increment C[x] by 1 During cnt S operation we only output C[S] 
    This solution have O(2^16) for add operation worst case but for cnt operation is it O(1) so this solution is slow 
    in worst case too Now we have two solutions , the first one is slow on cnt operations and the second is slow on add
    operations

    So let's try to combine both solution to get a solution that is fast on both add and cnt operations We have to use
    two arrays C and D , each with indices between 0 and 2^16-1

    During add S operation: If S have more than 8 1-bits then generate all numbers X such that S and X = S For each X ,
    add one to C[X] This is O(8 * 2^8) worst case If S have at most 8 1-bits then just add one to D[X] This is also O(1)

    During cnt S operation: If S have at most 8 1-bits then the numbers that we want to count will have at most 8 1-bits
    so we deal only with array D, generate all numbers X such that X and S = X then find the sum of values of D[x] and 
    output it This is O(8 * 2^8) If S have more than 8 1-bits then we need to count numbers that have more than 8 1-bits 
    and numbers that have at most 8 1-bits separately

     First, the number of numbers that have more than 8 1-bits is just C[S] Second, to count the numbers that have at most
     8 1-bits we need to count the numbers X in the list that have at most 8 1-bits that doesn't satisfy X and S = X Then 
     subtract it from total number of numbers in our list that have at most 8 1-bits Now to count the numbers X that 
     doesn't satisfy X and S = X we flip the digits of S (change every 0 to 1 and every 1 to 0) (note that S become to 
     have at most 8 1-bits) Then count the numbers X that have at least one common 1-bit with S by inclusion - exclusion
     principle This step is O(8 * 2^8) Now sum up two values to have final answer In total cnt operation is O(8 * 2^8)
     worst case

     So our solution now run in total complexity O(8 * 2^8 * Q)

     Final note: dealing with delete operation is the same as adding operation but after changing any step that 
     add a value to an array or variable we subtract that value instead

----------------------------------------------------------------
*/
#include<bits/stdc++.h>
using namespace std;


int N,Q,val;
string s;
int A[(1<<20)+100];
int B[(1<<20)+100];
int C[(1<<20)+100];
int D=0;
int sum=0;
int cnt=1;
void add1(){
    A[val]++;
}

void add2(){
    int ar[33],k=0;
    for(int i=0;i<N;i++){
        if((val &(1<<i))==0){
            ar[k++]=i;
        }
    }
    for(int i=0;i<(1<<k);i++){
        int bit=0;
        for(int j=0;j<k;j++){
            if(i&(1<<j))
                bit|=1<<ar[j];
        }
        B[bit|val]++;
    }
}


void add3(){
    D++;
    int ar[33],k=0;
    for(int i=0;i<N;i++){
        if(val &(1<<i))
            ar[k++]=i;
    }
    for(int i=1;i<(1<<k);i++){
        int bit=0;
        for(int j=0;j<k;j++){
            if(i&(1<<j))
                bit|=1<<ar[j];
        }
        C[bit]++;
    }
}



void del1(){
    A[val]--;
}

void del2(){

    int ar[33],k=0;
    for(int i=0;i<N;i++){
        if((val &(1<<i))==0){
            ar[k++]=i;
        }
    }
    for(int i=0;i<(1<<k);i++){
        int bit=0;
        for(int j=0;j<k;j++){
            if(i&(1<<j))
                bit|=1<<ar[j];
        }
        B[bit|val]--;
    }
}



void del3(){
    D--;
    int ar[33],k=0;
    for(int i=0;i<N;i++){
        if(val&(1<<i))
            ar[k++]=i;
    }
    for(int i=1;i<(1<<k);i++){
        int bit=0;
        for(int j=0;j<k;j++){
            if(i&(1<<j))
                bit|=1<<ar[j];
        }
        C[bit]--;
    }
}

int query1(){
    int ret=0;
    int ar[33],k=0;
    for(int i=0;i<N;i++){
        if(val &(1<<i))
            ar[k++]=i;
    }
    for(int i=0;i<(1<<k);i++){
        int bit=0;
        for(int j=0;j<k;j++){
            if(i&(1<<j))
                bit|=1<<ar[j];
        }
        ret+=A[bit];
    }
    return ret;
}

int query2(){
    return B[val];
}

int query3(){
    int ar[33],k=0;
    for(int i=0;i<N;i++){
        if((val &(1<<i))==0)
            ar[k++]=i;
    }
    int ret=0;
    for(int i=1;i<(1<<k);i++){
        int bit=0;
        int cnt=0;
        for(int j=0;j<k;j++){
            if(i&(1<<j))
                bit|=1<<ar[j],cnt++;
        }
        if(cnt%2)
            ret+=C[bit];
        else 
            ret-=C[bit];
    }
    return D-ret;
}

int main(){
    cin>>Q;
    N=16;
    while(Q--){
        
        cin>>s>>val;
        int h=0;
        for(int i=0;i<N;i++)
            if(val &(1<<i))
                h++;
        if(s=="add"){
            if(h<=N/2){

                add1();
                add3();
            } else {
                add2();
            }
        } else if(s=="cnt") {
            if(h<=N/2){
                int sol=query1();
                cout<<sol<<endl;
            } else {
                int sol=query2()+query3();
                cout<<sol<<endl;
            }
        } else {
            if(h<=N/2){

                del1();
                del3();
            } else {
                del2();
            }
        }
    }
}
