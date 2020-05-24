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

        int odd;
        int eve;

        odd=eve=0;

        int a[n];
        rep(i,0,n){

            cin>>a[i];
            int x=a[i];

            x ^= x >> 16;
            x ^= x >> 8;
            x ^= x >> 4;
            x ^= x >> 2;
            x ^= x >> 1;

            if(x&1) odd++;
            else eve++;

        }

        cout<<eve<<" "<<odd<<endl;

        while(m--){
            int x;
            cin>>x;

            x ^= x >> 16;
            x ^= x >> 8;
            x ^= x >> 4;
            x ^= x >> 2;
            x ^= x >> 1;

            if(x&1){
                cout<<odd<<" "<<eve<<endl;
            }
            else
            {
                cout<<eve<<" "<<odd<<endl;
            }
            
        }
    }   
}