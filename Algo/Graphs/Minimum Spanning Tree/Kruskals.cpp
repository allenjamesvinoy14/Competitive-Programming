// Note that the Kruskals is used for cycle detection. 

#include<bits/stdc++.h>
using namespace std;

class Edge{
    public: 
        int src,dest,wt;
};

bool cmp(Edge e1,Edge e2){
    return e1.wt<e2.wt; 
}

vector<Edge> output; // MST using Kruskals


class Disjoint_Set{
    public: 
        int rank,parent;
};

int find(Disjoint_Set *set,int i){

    if(set[i].parent!=i){
        set[i].parent = find(set,set[i].parent);
    }
    return set[i].parent;

}

void Union(Disjoint_Set *set,int v1,int v2){

    int v1_root = find(set,v1);
    int v2_root = find(set,v2);

    if(set[v1_root].rank < set[v2_root].rank){
        set[v1_root].parent = v2_root;
    }
    else if(set[v2_root].rank < set[v1_root].rank){
        set[v2_root].parent = v1_root;
    }
    else
    {
        set[v2_root].parent = v1_root;
        set[v1_root].rank++;   
    }
}

void Kruskals(vector<Edge> &edges,int n){

    sort(edges.begin(),edges.end(),cmp);

    output.resize(n-1);

    Disjoint_Set *set = new Disjoint_Set[n];

    for(int i = 0; i<n;i++){
        set[i].rank = 0;
        set[i].parent = i;
    }

    int counter = 0;
    int i = 0;

    while(counter<n-1){
        Edge cur = edges[i++];

        int sp = find(set,cur.src);
        int dp = find(set,cur.dest);

        if(sp!=dp){
            output[counter++] = cur;
            Union(set,sp,dp);
        }
    }
}

int main(){

    vector<Edge> edges;

    int n,e;
    cin>>n>>e;

    for(int i=0;i<e;i++){
        int s,d,w;

        cin>>s>>d>>w;

        Edge edge;
        edge.src = s;
        edge.dest = d;
        edge.wt = w;

        edges.push_back(edge);        
    }

    Kruskals(edges,n);


    // print the sum of weights of the output vector to get TOTAL COST of MST

    
    return 0;
}