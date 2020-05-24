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

        int a[n];
        int p[n];

        int b[m+1];

        rep(i,0,n){
             cin>>a[i];
             p[i]=a[i];
        }

        rep(i,0,m){
            cin>>b[i];
        }

        sort(b,b+m);

        b[m] = INT_MAX;
        m++;

        vector<pi> idx;
        
        int i,j;

        for(i=0;i<m-1;i++){
            for(j=i+1;j<m;j++)
            {
                if(b[j]-b[j-1]>1){
                    idx.pb(mp(b[i],b[j-1]));
                    i=j-1;
                    break;
                }
            }
        }

        for(auto i: idx)
        {   
            sort(a+i.first-1,a+i.second+1);
        }

        sort(p,p+n);

        bool ans = true;

        for(int i=0;i<n;i++)
        {
            if(p[i]!=a[i])
            {
                ans=false;
                break;
            }
        }

        if(ans)
            cout<<"YES\n";
        else
        {
            cout<<"NO\n";
        }
        
    }
    
}