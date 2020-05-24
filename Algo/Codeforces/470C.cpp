#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int knapSack(int k, int sum[], int n,int m) 
{ 
   int i, w; 
   int K[n+1][k+1]; 

   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= k; w++) 
       { 
           if (i==0 || w==0){ 
               K[i][w] = 0; 
               continue;
           }
           if(w>=m)
                K[i][w] = max(sum[i-1] + K[i-1][w-m],  K[i-1][w]);
            else
                K[i][w] = max(sum[i-1],  K[i-1][w]);
       } 
   } 
   return K[n][k]; 
} 
int main(){
    int n,m,k;

    cin>>n>>m>>k;

    int arr[n];

    for(int i=0;i<n;i++) cin>>arr[i];

    int sum[n-m+1]={0};

    for(int i=0;i<m;i++)
        sum[0]+=arr[i];

    for(int i=1;i<n-m+1;i++){
        sum[i] = sum[i-1]-arr[i-1]+arr[i+m-1];
    }

    cout<<knapSack(k,sum,n,m)<<endl;
}

