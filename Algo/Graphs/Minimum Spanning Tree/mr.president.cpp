#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pii pair<int,int>
#define vi vector<pii>
#define pb push_back
#define inf INT_MAX
#define edge pair<pii,int>
#define me(v,u,c) mp(mp(v,u),c)
#define S second
#define F first

const int MAXN = 1000000;
int parent[MAXN];
int cnt[MAXN];

int Find(int n){
    if(parent[n] == n) 
        return n;

    int p = Find(parent[n]);
    parent[n] = p;
    
    return parent[n];
}
bool Union(int u,int v){

    int pu = Find(u);
    int pv = Find(v);

    if(pu==pv) return false;

    if(cnt[pu]<cnt[pv]){
        cnt[pv] += cnt[pu];
        parent[pu] = pv;
    }
    else{
        cnt[pu] += cnt[pv];
        parent[pv] = pu;
    }

    return true;
}

bool cmp(edge e1,edge e2){

    return e1.S<e2.S;

}

int32_t main(){

    int n,m;

    int k;

    cin>>n>>m>>k;

    for(int i=0;i<n;i++) parent[i] = i;
    for(int i=0;i<n;i++) cnt[i] = 1;

    vector<edge> g;

    for(int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        u--;
        v--;
        g.push_back({{u,v},c});
    }

    sort(g.begin(),g.end(),cmp);

    int ans = (n-1 <= k)? n-1:-1;

    int rem = n;

    int cost = 0;
    
    for(int i=0;i<m;i++){
        int u = g[i].F.F;
        int v = g[i].F.S;
        int c = g[i].S;

        if(Union(u,v)){
            rem--;

            cost+=c;

            if(cost + rem-1 <= k){
                ans = rem-1;
            }
        }
    }

    if(rem>1) cout<<-1<<endl;
    else cout<<ans<<endl;
}