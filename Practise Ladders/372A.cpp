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

    // int t;
    // cin>>t;

    // while(t--){
        int n;
        cin>>n;

        vi v;

        rep(i,0,n){

            int temp;
            cin>>temp;

            v.pb(temp);
        }

        sort(v.begin(),v.end());


        int pt = n/2;

        int ans = n;

        for(int i=0;i<n/2;i++){

            while(pt!=n){

                if(v[i]*2<=v[pt]){
                    ans--;
                    pt++;
                    break;
                }
                else{
                    pt++;
                }
            }
            if(pt==n) break;
        }

        cout<<ans<<endl;
    // }
    
}