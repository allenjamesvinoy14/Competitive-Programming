#include<bits/stdc++.h>
using namespace std;

//generating a range containing prime numbers alone
void prime_sieve(int *p){

    //first mark all odd numbers as prime
    for(int i=3;i<=1000000;i+=2)
        p[i]=1;

    //sieve
    for(int i = 3;i<=1000000;i+=2){
        if(p[i] == 1){
            for(int j= i*i; j<=1000000; j=j+i){
                p[j]=0;
            }
        }
    }

    //special case
    p[2]=1;
    p[0] = p[1] = 0;
}
int main()
{
    int p[1000005] = {0};
    prime_sieve(p);
}