#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define vvi vector<vector<ll>>
#define MOD 1000000007
#define M 1000000007
#define T ll

//assuming adjacenecy matrix implementation
void bfs(T src,vector<T> adj[])
{
    queue<T> q;
    vector<bool> vis;

    vis[src] = 1;
    q.push(src);

    while(!q.empty())
    {
        T node = q.front();
        q.pop();

        for(auto i: adj[node])
        {
            if(!vis[i])
            {
                vis[i]=1;
                q.push(i);
            }
        }
    }
}
