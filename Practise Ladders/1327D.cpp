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

        int p[n],c[n];
        rep(i,1,n+1) cin>>p[i];
        rep(i,1,n+1) cin>>c[i];

        vector<bool> vis(n+1,0);

        // walk stores all the cycles
        map<int,vi> walk;

        for(int i=1;i<=n;i++){
            if(vis[i]) continue;

            vis[i] = 1;
            walk[i].pb(i);

            int cur = i;

            while(p[cur]!=i){
                cur = p[cur];

                vis[cur] = 1;

                walk[i].pb(cur);
            }
        }

        int ans = n; // obtained from observation

        for(auto el: walk){
            int s = el.S.size();

            for(int i=1;i*i<=s;i++){

                int k = i;

                if(s%k) continue;

                vector<bool> pos(k,1);

                rep(i,0,s){
                    if(c[el.S[i]]!=c[el.S[i%k]]){

                        pos[i%k]=0;

                    }
                }

                for(auto j: pos) 
                    if(j==1){
                        ans = min(ans,k);
                        break;
                    }

                k = s/k;

                pos.assign(k,1);

                rep(i,0,s){
                    if(c[el.S[i]]!=c[el.S[i%k]]){

                        pos[i%k]=0;

                    }
                }

                for(auto j: pos) 
                    if(j==1){
                        ans = min(ans,k);
                        break;
                    }


            }
        }


        cout<<ans<<endl;

    }
    
}