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

        int n;
        cin>>n;

        vector<pi> a;

        a.pb(mp(0,0));

        bool ans = true;

        rep(i,0,n){
            int x,y;
            cin>>x>>y;

            if(x<0 or y<0)
            {
                ans = false;
                break;
            } 

            a.pb(mp(x,y));
        }

        sort(a.begin(),a.end());

        string s = "";

        if(ans){
            for(int i=1;i<a.size();i++){
                int x = a[i].F-a[i-1].F;
                int y = a[i].S-a[i-1].S;

                if(x<0 or y<0)
                {
                    ans=false;
                    break;
                }

                rep(i,0,x) s+="R";
                rep(i,0,y) s+="U";
            }
        } 

        if(ans)
        {
            cout<<"YES\n";
            cout<<s<<endl;
        }
        else
        {
            cout<<"NO\n";
        }
    }
}