#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define vvi vector<vector<ll>>
#define MOD 1000000007
#define M 1000000007
#define T ll


void dfsHelper(T src,vector<T> adj[],map<T,bool> &vis){
    if(vis[src])
        return;
    

    vis[src]=1;

    for(auto i: adj[src])
    {
        if(!vis[i])
        {
            dfsHelper(i,adj,vis);
        }
    }
}
//assuming adjacenecy matrix implementation
void dfs(T src,vector<T> adj[])
{
    map<T,bool> vis;
    dfsHelper(src,adj,vis);
}
