#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vvl vector<vector<ll>>
#define pl pair<ll,ll>
#define vvi vector<vector<int>>
#define pi pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define mpc map<char,int>
#define MOD 1000000007
#define M 1000000007
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<b;i++)
#define all(t) t.begin(),t.end()
#define sz size()

int dp[1005];

int32_t main(){

    int t;
    cin>>t;

    while(t--){

        string s;
        cin>>s;

        int n = s.length();

        memset(dp,0,sizeof dp);

        dp[1] = (s[0]=='0')?1:0;

        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1]+(s[i-1]=='0');
        }

        int mn = n;

        for(int i = 1;i<=n;i++){
            for(int j=i;j<=n;j++){

                int del = dp[i-1] + j-i+1 - (dp[j]-dp[i-1]) + (dp[n] - dp[j]);

                mn = min(mn, del);
                mn = min(mn, n - del);

            }
        }

        cout<<mn<<endl;
    }  
}