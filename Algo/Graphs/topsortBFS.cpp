#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll nx=3e5,mx=5e5;
ll indeg[nx],outdeg[nx];
vector<ll> adj[nx];
double ways[mx];

int main()
{
	ll n,m,r;cin>>n>>m>>r;
	--r;

	for(ll i=0;i<m;i++)
	{
		ll u,v;
		cin>>u>>v;
		--u;
		--v;
		adj[u].push_back(v);
		indeg[v]++,
		outdeg[u]++;
	}

	queue<ll> q;

	for(ll i=0;i<n;i++) if(indeg[i]==0) q.push(i);

	while(!q.empty())
	{
		ll a=q.front();q.pop();

		cout<<a<<" ";
		
		for(auto i:adj[a])
		{
			indeg[i]--;
			if(indeg[i]==0) q.push(i);
		}
	}
}