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

    ll sum=0;

    while(t--){
        int n;
        cin>>n;

        if(n==0)
        {
            sum-=400;
            cout<<-400<<endl;
            continue;
        }
        if(n==1)
        {
            sum-=200;
            cout<<-200<<endl;
            continue;
        }

        int a[4][4] = {0};

        int count = 4;

        rep(i,0,n){
            char c;
            int m;

            cin>>c>>m;

            a[c-65][m/3-1]++;
        }

        ll ans;

        vector<pi> s;

        for(int j=0;j<4;j++)
        {
            for(int i=0;i<4;i++){
                
            }
        }
    }    
}