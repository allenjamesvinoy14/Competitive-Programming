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
        int n;
        cin>>n;

        int a[n+1];

        vector<int> fours;
        vector<int> twos;

        twos.pb(0);

        fours.pb(0);

        int ans=0;

        int end=1;

        int tsz;

        rep(i,0,n){

            cin>>a[i];

            if(a[i]%4==0){ 

                fours.pb(i+1);

                tsz = twos.size();

                if(tsz>2){

                    for(int j = 1;j<tsz-1;j++){

                        int tot = (twos[j] - twos[j-1])*(end - twos[j+1]);
                        ans+=tot;

                    }

                }

                twos.clear();

                twos.pb(i+1);
                end++;

                continue;
            }

            if(a[i]%2==0){
                twos.pb(i+1);
            }

            end++;
        }

        //cout<<end<<endl;

        // for(auto j: twos) cout<<j<<" ";
        // cout<<endl;
        // cout<<endl;

        tsz = twos.size();

        if(tsz>2){

            for(int j = 1;j<tsz-1;j++){

                int tot = (twos[j] - twos[j-1])*(end - twos[j+1]);
                ans+=tot;

            }

        }


        fours.pb(n+1);

        a[n] = 0;

        int len=0;

        for(int i=0;i<=n;i++){
            if(a[i]&1) len++;
            else{
                ans += ((len*(len+1))>>1);
                len = 0;
            }
        }

        ans += ((n*(n+1))>>1);

        for(int i=1;i<fours.size();i++){

            int el = fours[i]-fours[i-1]-1;

            ans -= ((el*(el+1))>>1);

        }

        cout<<ans<<endl;
    }    
}