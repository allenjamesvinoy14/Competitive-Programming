#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int> 

int main(){
    int n,m;
    cin>>n>>m;

    int arr[n];
    int vis[100001] = {0};

    for(int i=0;i<n;i++) cin>>arr[i];

    int dp[n] = {0};

    dp[n-1] = 1;
    vis[arr[n-1]]=1;

    for(int i=n-2;i>=0;i--){
        if(vis[arr[i]]==0)
        {
            dp[i] = dp[i+1]+1;
            vis[arr[i]] = 1;
        }
        else
        {
            dp[i] = dp[i+1];
        }
    }

    int q;
    while(m--){
        cin>>q;
        cout<<dp[q-1]<<endl;;
    }   
}