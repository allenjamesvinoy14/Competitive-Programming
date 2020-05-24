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

    int t;
    scanf("%llu",&t);

    while(t--){
        int n;
        scanf("%llu",&n);

        int a[n],b[n];
        rep(i,0,n){
            scanf("%llu %llu", &a[i], &b[i]);
        }

        uint rem[n];

        uint remsum = 0;

        for(int i=0;i<n-1;i++){
            rem[i+1] = max(0LL,(a[i+1]-b[i]));
            remsum+=rem[i+1];
        }

        rem[0] = max(0LL,a[0]-b[n-1]);
        remsum+=rem[0];

        uint pre[n]={0};

        pre[0] = rem[0];

        for(int i=1;i<n;i++){
            pre[i]+=(rem[i]+pre[i-1]);
        }

        uint min = 1e19;

        for(int i=0;i<n;i++){

            uint cost = a[i];

            if(i-1>=0){
                cost+=pre[i-1];
            }

            uint sufcost = remsum-pre[i];

            cost+=sufcost;
            if(cost<min) min = cost;

        }

        cout<<min<<"\n";
    }
    
}