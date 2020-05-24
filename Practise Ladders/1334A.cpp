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

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        if(n==1){
            int x,y;
            cin>>x>>y;

            if(y<=x) cout<<"yes\n";
            else cout<<"no\n";
            continue;
        }

        vector<pair<int,int>> p;

        while(n--){
            int x,y;
            cin>>x>>y;

            p.pb({x,y});
        }

        bool ans = true;

        for(int i=1;i<p.sz;i++){
            int x1 = p[i-1].F;
            int x2 = p[i].F;

            int y1 = p[i-1].S;
            int y2 = p[i].S;

            if(x2<x1 or y2<y1) ans = false;

            if(y2-y1>x2-x1) ans = false;

            if(y2>x2 or y1>x1) ans = false;

        }

        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
}