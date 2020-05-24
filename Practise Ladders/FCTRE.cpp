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

vector<vi> adj;
vi cost,prod,vis;

int n, l;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

void calc_prod(int root){

    for(auto i: adj[root]){

        if(!vis[i]){
            prod[i] = (prod[root]*cost[i])%M;
            vis[i] = 1;
            calc_prod(i);
        }

    }

}

int totcost(int u,int v){

    int root = lca(u,v);

    int div;

    if(root == 0){
        div = prod[root];
    }
    else{
        div = (2*prod[root])%M;
    }

    int ans = ((prod[u]*prod[v])%M)/div;

    return ans;
}

int fctr(int val){

    int limit = sqrt(val);

    int ans = 1;

    for(int i=2;i<=limit;i++){
        if(val%i==0) ans++;
    }

    ans = ans*2;

    if(limit*limit == val) ans--;

    return ans;
}

int32_t main(){

    int t;
    cin>>t;

    while(t--){
        cin>>n;

        adj.resize(n+1,vi(0));

        int k = n-1;

        while(k--){
            int u,v;
            cin>>u>>v;

            u--;
            v--;

            adj[u].pb(v);
            adj[v].pb(u);
        }

        cost.resize(n+1,0);

        rep(i,0,n) cin>>cost[i];

        prod.resize(n+1,0);
        vis.resize(n+1,0);

        prod[0] = cost[0];
        vis[0] = 1;

        calc_prod(0);

        preprocess(0);

        int q;
        cin>>q;

        while(q--){
            int u,v;
            cin>>u>>v;
            u--;
            v--;

            if(u==v){
                cout<<fctr(cost[u])%M<<endl;
            }
            else{
                int tcost = totcost(u,v);
                cout<<fctr(tcost)%M<<endl;
            }
        }
    }
    
}