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

        int a,b,q;

        cin>>a>>b>>q;

        while(q--){
            int l,r;
            cin>>l>>r;

            for(int i=l;i<=r;i++){
                if((i%a)%b == (i%b)%a) cout<<i<<endl;
            }
        }
    }    
}