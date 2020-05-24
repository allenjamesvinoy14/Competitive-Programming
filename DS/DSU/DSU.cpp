#include<bits/stdc++.h>

 using namespace std;

 const int mx=101;
 int parent[mx];
 int rnk[mx]={0};
 int freq[mx]={0};

 int Find(int x)
 {
     if(x!=parent[x])
        parent[x]=Find(parent[x]);

     return parent[x];
 }

 void Union(int x,int y)

 {
     int a=Find(x);
     int b=Find(y);

     if(a==b) return;

     if(rnk[a]<rnk[b])
     {
         parent[a]=b;
     }
     else
       {
           parent[b]=a;
           if(rnk[a]==rnk[b])
            rnk[b]++;
       }
 }

 int main(){
    for(int i=0;i<=mx;i++)
    {
        parent[i]=i;
    }
 }