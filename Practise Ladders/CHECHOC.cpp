#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define MX 1e19
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

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){

        int n,m,x,y;
        cin>>n>>m>>x>>y;

        if(x>y and n==1 and m==1){
            cout<<x<<endl;
            continue;
        }

        if(2*x<=y){
            cout<<n*m*x<<endl;
            continue;
        }
        
        if(n>m) swap(n,m);

        x = min(x,y);

        int a = x;
        int b = y-x;

        x = max(a,b);
        y = min(a,b);

        int ans = (((m+1)/2)*((n+1)/2) + (m/2)*(n/2))*x + ((m/2)*((n+1)/2) + ((m+1)/2)*(n/2))*y;

        cout<<ans<<endl;

    }
}