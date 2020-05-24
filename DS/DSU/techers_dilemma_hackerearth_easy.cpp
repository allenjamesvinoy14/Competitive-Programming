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
int main()
{
    int i,j,n,m;
    cin>>n>>m;
    assert(1<=n && n<=100000);
    assert(1<=m && m<=100000);
    subsets.clear();
    subsets.resize(n);
    for(i=0;i<n;i++){
        subsets[i].parent=i;
        subsets[i].sz=1;
    }
    for(i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        assert(1<=x && x<=n);
        assert(1<=y && y<=n);
        uniona ( find(--x), find(--y));
    }
    ll int ans=1;
    for(i=0;i<n;i++){
        if(find(i)==i)
            ans = (ans*subsets[find(i)].sz)%mod;
    }
    cout<<ans<<endl;
    return 0;
}