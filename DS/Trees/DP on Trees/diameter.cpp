// Longest path starts from node x and goes into its subtree(denoted by blue lines in the image). 
// Lets define by f(x) this path length.
// Longest path starts in subtree of x, passes through x and ends in subtree of x(denoted by red line in image). 
// Lets define by g(x) this path length.


#include<bits/stdc++.h>
using namespace std;

const int N = 10005;

vector<int> adj[N];

int diameter;

int f[N],g[N];

void dfs(int v,int p){
    vector<int> fvals;

    for(auto c: adj[v]){
        if(v==p) continue;

        dfs(c,v);
        fvals.push_back(c);
    }

    sort(fvals.begin(),fvals.end());

    f[v] = 1;

    if(!fvals.empty()) f[v]+=fvals.back();

    if(fvals.size()>=2)
        g[v] = 1+fvals.back()+fvals[fvals.size()-2];

    diameter = max(diameter,max(f[v],g[v]));
}

int main(){

}