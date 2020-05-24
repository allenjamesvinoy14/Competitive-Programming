// Naive C++ implementation to find LCA in a tree 
#include<bits/stdc++.h> 
using namespace std; 
#define MAXN 1001 

int depth[MAXN];		 // stores depth for each node 
int parent[MAXN];		 // stores first parent for each node 

vector <int> adj[MAXN]; 

void addEdge(int u,int v) 
{ 
	adj[u].push_back(v); 
	adj[v].push_back(u); 
} 

void dfs(int cur, int prev) 
{ 
	parent[cur] = prev; 
 
	depth[cur] = depth[prev] + 1; 

	for (int i=0; i<adj[cur].size(); i++) 
		if (adj[cur][i] != prev) 
			dfs(adj[cur][i],cur); 
} 

void preprocess() 
{ 
	depth[0] = -1; 
	dfs(1,0); 
} 

int LCANaive(int u,int v) 
{ 
	if (u == v) return u; 
	if (depth[u] > depth[v]) 
		swap(u, v); 
	v = parent[v]; 
	return LCANaive(u,v); 
} 
int main(int argc, char const *argv[]) 
{ 
	addEdge(1,2); 
	addEdge(1,3); 
	addEdge(1,4); 
	addEdge(2,5); 
	addEdge(2,6); 
	addEdge(3,7); 
	addEdge(4,8); 
	addEdge(4,9); 
	addEdge(9,10); 
	addEdge(9,11); 
	addEdge(7,12); 
	addEdge(7,13); 

	preprocess(); 

	cout << "LCA(11,8) : " << LCANaive(11,8) << endl; 
	cout << "LCA(3,13) : " << LCANaive(3,13) << endl; 

	return 0; 
} 
