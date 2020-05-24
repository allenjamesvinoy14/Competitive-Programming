#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>

vi *adj;
bool bipart(int u,vi &color,vi &vis){
    for(auto v: adj[u]){
        if(!vis[v])
        {
            color[v] = !color[u];
            vis[v]=1;

            if(!bipart(v,color,vis)) return false;
        }
        else if(color[v]==color[u]) return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;

    for(int p = 0;p<t;p++){
        int n,k;
        cin>>n>>k;

        adj=new vi[n+1];

        while(k--){
            int u,v;
            cin>>u>>v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vi color(n+1);

        vi vis(n+1,0);

        bool ans = true;

        for(int i=1;i<=n;i++){

            if(!vis[i])
            {
                vis[i]=1;
                color[i]=0;

                if(!bipart(i,color,vis)){
                    ans = false;        
                    break;
                }
            }
        }

        cout<<"Scenario #"<<p+1<<":"<<endl;

        if(ans) cout<<"No suspicious bugs found!\n";
        else cout<<"Suspicious bugs found!\n";
    }
}

