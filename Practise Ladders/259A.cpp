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

int32_t main(){

    // int t;
    // cin>>t;

    // while(t--){
        string s;

        bool ans = true;

        for(int i = 0;i<8;i++){
            cin>>s;

            for(int j=0;j<7;j++){
                if(s[j]==s[j+1]) ans = false;
            }
        }

        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    // }
    
}