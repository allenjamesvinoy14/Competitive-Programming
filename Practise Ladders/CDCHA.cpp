#include<bits/stdc++.h>
using namespace std;
#define ll long long int
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

int main(){

    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;

        int a[n],b[n];
        rep(i,0,n) cin>>a[i];
        rep(i,0,n) cin>>b[i];

        map<int,int> cost;

        for(int i=0;i<n;i++) cost[a[i]]+=b[i];

        set<pi> ans;

        for(auto i: cost){
            ans.insert(mp(i.S,i.F));
        }

        pi an = *ans.begin();
        cout<<an.F<<endl;
    }
}