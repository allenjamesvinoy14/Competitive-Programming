#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int> 

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++) cin>>arr[i];

    int dp[n] = {0};

    dp[0] = (arr[0]==1)?0:1;

    for(int i=1;i<n;i++){
        if(arr[i] == 1)
            dp[i]=0;
        else
        {
            dp[i] = dp[i-1]+1;
        }
    }

    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        ans = max(ans,dp[i]+2);
    }
}