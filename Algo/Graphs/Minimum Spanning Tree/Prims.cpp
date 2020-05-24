#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<pii>
#define pb push_back
#define INF INT_MAX

vector<vi> adj;
bool vis[100005];

void prims(int n,int src){

    priority_queue<pii,vector<pii>,greater<pii>> pq;

    int cost = 0;

    pii p;

    pq.push(make_pair(0,src));

    while(!pq.empty()){
        p = pq.top();
        pq.pop();

        int par = p.second;
        int wt = p.first;

        if(vis[par]) continue;

        cost += wt;
        vis[par] = true;

        for(int i = 0;i < adj[par].size();i++){
            int nbr = adj[par][i].second;
            if(!vis[nbr])
                pq.push(adj[par][i]);    
        }
    }
    //return the cost if needed
}

int main(){
    int n,e;

    cin>>n>>e;

    adj.resize(n,vi(0));

    for(int i=0;i<e;i++){
        int u,v,wt;

        cin>>u>>v>>wt;

        adj[u].pb(make_pair(wt,v));
        adj[v].pb(make_pair(wt,u));
    }

    prims(n,1); // considering source as 1st node
}