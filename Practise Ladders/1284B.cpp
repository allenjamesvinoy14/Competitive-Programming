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
#define sz(v) ((int)(v).size())

int main(){

    // while(t--){
        int n;
        cin>>n;

        vector<int> arr;

        vector<pi> ij;

        rep(i,0,n){
            
            int m;
            cin>>m;

            while(m--){
                int temp;
                cin>>temp;
                arr.pb(temp);
                reverse(arr.begin(),arr.end());

                if(is_sorted(arr.begin(),arr.end())){
                    ij.pb(mp(arr[0],arr.back()));
                }
            }
        }

        sort(ij.begin(),ij.end());

        int ans = n*n;

        for(int i=0;i<sz(ij);i++){
            ans-= ij.end()-lower_bound(ij.begin(),ij.end(),mp(ij[i].S,-1));
        }

        cout<<ans<<endl;
}