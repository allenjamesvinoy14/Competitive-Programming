//DSU using union by rank

#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll int mod = 1000000007;
struct subset
{
    int parent,sz;
};
vector< subset> subsets;

int find( int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets[i].parent);
    return subsets[i].parent;
}
void uniona(int x, int y){
    if( x == y)
        return ;
    int xroot = find( x);
    int yroot = find( y);
    if (subsets[xroot].sz < subsets[yroot].sz){
        subsets[xroot].parent = yroot;
        subsets[yroot].sz += subsets[xroot].sz;
    }
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].sz += subsets[yroot].sz;
    }
}