#include<bits/stdc++.h>
using namespace std;

bool dfs_helper(int node,vector<int> adj[],map<int,bool> &vis,map<int,bool> &instack,int v){
    vis[node]=true;
    instack[node]=true;

    for(auto i: adj[node]){
        if((!vis[i] and dfs_helper(i,adj,vis,instack,v)) || instack[i])
            return true;
    }

    instack[node]=false;
    return false;
}
bool isCycleDirDFS(vector<int> adj[],int v)
{
    map<int,bool> vis;
    map<int,bool> instack;

    for(int i=0;i<v;i++){
        if(!vis[i]){
            vis[i]=true;

            bool ans = dfs_helper(i,adj,vis,instack,v);

            if(ans)
            {
                return true;
            }
        }
    }

    return false;
}