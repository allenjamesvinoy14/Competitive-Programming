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
#define MAXN 100005

int vis[100005];
int cost[100005];

int depth[MAXN];
int parent[MAXN];

vector<map<int,int>> factors(100005);

set<int> primes; // to store prime numbers occuring till now

int n, l;

void dfs(int cur, int prev,vector<int> adj[]) 
{ 
	parent[cur] = prev; 
 
	depth[cur] = depth[prev] + 1; 

	for (int i=0; i<adj[cur].size(); i++) 
		if (adj[cur][i] != prev) 
			dfs(adj[cur][i],cur,adj); 
} 

void preprocess(vector<int> adj[]) 
{ 
	depth[0] = -1; 
	dfs(1,0,adj); 
} 

int lca(int u,int v) 
{ 
	if (u == v) return u; 
	if (depth[u] > depth[v]) 
		swap(u, v); 
	v = parent[v]; 
	return lca(u,v); 
} 

map<int,int> factorise(int num){

    int limit = num;

    map<int,int> pc;

    //an area to optimise by just covering the odd eles
    for(int i=2;i<=sqrt(num);i++){

        int cnt = 0;

        if(num%i==0) primes.insert(i);

        while(num%i == 0){

            num /= i;
            ++cnt;

        }

        pc[i] = cnt;

    }
    if(num>1){
        primes.insert(num);
        pc[num] = 1LL; 
    }

    return pc;

}
map<int,int> mult_factors(map<int,int> &a,map<int,int> &b){

    map<int,int> ans;

    for(auto i: primes){
        ans[i] = a[i]+b[i];
    }

    return ans;
}
map<int,int> div_factors(map<int,int> &a,map<int,int> &b){

    map<int,int> ans;

    for(auto i: primes){
        ans[i] = max(0LL, abs(a[i]-b[i]));
    }

    return ans;

}

void calc_prod(int root,vector<int> adj[]){

    for(auto i: adj[root]){

        if(!vis[i]){
            map<int,int> cur_cost = factorise(cost[i]);
            factors[i] = mult_factors(factors[root],cur_cost);
            vis[i] = 1;
            calc_prod(i,adj);
        }

    }

}

int totcost(int u,int v){

    int root = lca(u,v);

    //cout<<root<<endl;

    map<int,int> div = factors[root];

    map<int,int> a = div_factors(factors[u],div);
    map<int,int> b = div_factors(factors[v],div);

    map<int,int> temp = mult_factors(b,div);
    map<int,int> ans = mult_factors(a,temp);

    int tot_cost = 1;

    for(auto i: ans){
        tot_cost = (tot_cost*(i.S+1))%M;
    }
    return tot_cost;
}

int fctr(int val){

    int limit = sqrt(val);

    int ans = 1;

    for(int i=2;i<=limit;i++){
        if(val%i==0) ans = (ans+1)%M;
    }

    ans = (ans*2)%M;

    if(limit*limit == val) ans--;

    return ans;
}

int32_t main(){

    int t;
    scanf("%llu",&t);

    while(t--){

        primes.clear();

        memset(depth,0,sizeof depth);
        memset(parent,0,sizeof parent);

        scanf("%llu",&n);

        int k = n-1;

        vector<int> adj[n+1];

        while(k--){
            int u,v;
            scanf("%llu %llu",&u,&v);

            u--;
            v--;

            adj[u].pb(v);
            adj[v].pb(u);
        }

        preprocess(adj); 

        rep(i,0,n) scanf("%llu",&cost[i]);

        memset(vis,0,sizeof vis);

        factors[0] = factorise(cost[0]);
        vis[0] = 1;

        calc_prod(0,adj);

        int q;
        scanf("%llu",&q);

        while(q--){
            int u,v;
            scanf("%llu %llu",&u,&v);
            u--;
            v--;

            if(u==v){
                printf("%llu\n",fctr(cost[u])%M);
            }
            else{
                int tcost = totcost(u,v);
                printf("%llu\n",tcost%M);
            }
        }
    }
}