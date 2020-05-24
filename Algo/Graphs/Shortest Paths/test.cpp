#include<bits/stdc++.h>
using namespace std;

class Graph{
    unordered_map<int,list<pair<int,int>>> m;
public:
    void addEdge(int u,int v,int d){
        m[u].push_back(make_pair(v,d));
        m[v].push_back(make_pair(u,d));
    }

    void dijkstra(int src){
        map<int,int> dist;

        for(auto i:m){
            dist[i.first]=INT_MAX;
        }

        dist[src] = 0;

        set<pair<int,int>> items;

        items.insert(make_pair(0,src));

        while(!items.empty()){
            auto p = *(items.begin());

            items.erase(items.begin());

            int n = p.second;
            int d = p.first;

            for(auto j: m[n])
            {
                int nd = j.second+d;
                if(nd<dist[j.first]){

                    int des = j.first;
                    auto k = items.find(make_pair(dist[des],des));
                    if(k!=items.end()){
                        items.erase(make_pair(dist[des],des));
                    }

                    dist[des] = nd;
                    items.insert(make_pair(nd,des));
                }
            }
        }

        for(auto ans: dist){
            if(ans.first!=src){
                if(ans.second==INT_MAX)
                    cout<<-1<<" ";
                else
                    cout<<ans.second<<" ";
            }
        }

    }
};