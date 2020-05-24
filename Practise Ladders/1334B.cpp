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
        int n,x;
        cin>>n>>x;

        int a[n];
        rep(i,0,n) cin>>a[i];

        sort(a,a+n,greater<int>());

        double tot = 0;
        int sum = 0;
        int i;

        for(i=0;i<n;i++){

            sum+=a[i];
            tot = (double(sum))/(i+1);

            //cout<<i<<" "<<tot<<endl;

            if(tot<x) break;

        }

        cout<<i<<endl;
    }
    
}