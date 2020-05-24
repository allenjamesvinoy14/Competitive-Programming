#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define vii vector<pi>
#define vi vector<int>
#define vvi vector<vector<int>>
#define mp make_pair
#define pb push_back
#define INF (1<<25)

map<string,int> names;
vi dist;
vector<vii> adj;
int n;

typedef bool (*comp)(pi,pi);

bool compare(pi a,pi b){
    return a.second>b.second;
}

void sp(int source,int destination){

    priority_queue<pi,vii,comp> pq(compare);

    pq.push(pi(source,0));
    dist[source]=0;

    while(!pq.empty()){

        pi x = pq.top();
        int top=x.first;
        pq.pop();

        if(top==destination)break; //breaks the iteration over neigbhours of destination

        for(int i=0;i<adj[top].size();++i){

            pi neighbor = adj[top][i];

            int in = neighbor.first, cost = neighbor.second;

            if(dist[in]>dist[top]+cost){

                dist[in]=dist[top]+cost;
                pq.push(pi(in,dist[in]));

            }
        }

    }
}

int main()
{
    int t;
    scanf("%d",&t);

    names.clear();

    while(t--){
        scanf("%d",&n);

        adj = vector<vii> (n+1,vii());

        for(int i=1;i<=n;i++){

            char city[11];
            scanf("%s",city);

            names[string(city)]=i;

            int k;

            scanf("%d",&k);

            while(k--){
                
                int v,c;

                scanf("%d %d",&v,&c);

                adj[i].pb(mp(v,c));
            }
        }

        int tt;
        scanf("%d",&tt);

        while(tt--){
            char city1[11],city2[11];

            scanf("%s %s",city1,city2);

            int u = names[string(city1)];
            int v = names[string(city2)];

            dist = vi(n+1,INF);

            sp(u,v);

            printf("%d \n",dist[v]);
        }
    }
}