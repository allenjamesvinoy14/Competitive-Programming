#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vvl vector<vector<ll>>
#define pl pair<ll,ll>
#define vvi vector<vector<int>>
#define pi pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define mpc map<char,int>
#define MOD 1000000007
#define M 1000000007
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<b;i++)

#define gc getchar_unlocked
#define pc putchar_unlocked

inline void lprint(long int a)
{
    int i=0;
    char S[20];
    while(a>0)
    {
        S[i++]=a%10+'0';
        a=a/10;
    }
    --i;
    while(i>=0)
    pc(S[i--]);
    pc(' ');
}

inline unsigned long long uscan()
{
    unsigned long long n=0,c=gc();
    while(c<'0'||c>'9')
    c=gc();
    while(c<='9'&&c>='0'){
    n=n*10+c-'0';
    c=gc();}
    return n;
}

inline long int lscan()                 
{
    long int n=0,c=gc();
    while(c<'0'||c>'9')
    c=gc();
    while(c<='9'&&c>='0'){
    n=n*10+c-'0';
    c=gc();}
    return n;
}


inline  int sscan()                     
{
    register  int n=0,c=gc();
    while(c<'0'||c>'9')
    c=gc();
    while(c<='9'&&c>='0')
        {
    n=n*10+c-'0';
    c=gc();
        }
    return n;
}

vector<int> *ltree;
vector<int> *utree;
vector<int> p;
vector<int> l;
vector<int> u;

void build_tree(vi *tree, vi &p, int cur , int l , int r )
{

    if(l==r)
    {
        tree[cur].push_back( p[ l ] );
        return ;
    }

    int left = cur<<1, right = left|1, mid = (l+r)/2;

    build_tree(tree, p, left , l , mid );
    build_tree(tree, p, right , mid+1 , r );

    merge( tree[left].begin(),tree[left].end(),tree[right].begin(),tree[right].end(),back_inserter(tree[cur]));

}
int lquery(vi *tree, int cur, int l, int r, int x, int y, int k) {
    
	int left = cur<<1, right = left|1, mid = (l+r)/2;

    if(r<x||l>y)
    {
        return 0;
    }

    if( x<=l && r<=y ){
        auto i = upper_bound(tree[cur].begin(),tree[cur].end(),k);

        if(*i==k) i++;

        return tree[cur].end()-i;
    }

    return lquery(tree,left,l,mid,x,y,k)+lquery(tree,right,mid+1,r,x,y,k);
}
int uquery(vi *tree, int cur, int l, int r, int x, int y, int k) {
	int left = cur<<1, right = left|1, mid = (l+r)/2;

    if(r<x||l>y)
    {
        return 0;
    }

    if( x<=l && r<=y ){
        auto i = lower_bound(tree[cur].begin(),tree[cur].end(),k);

        return i-tree[cur].begin();
    }

    return uquery(tree,left,l,mid,x,y,k)+uquery(tree,right,mid+1,r,x,y,k);
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    t=sscan();

    while(t--){
        int n,q;
        n=sscan();
        q=sscan();

        p.clear();
        p.resize(n);

        rep(i,0,n){
            int temp;
            temp=sscan();
            p[i]=temp;
        }

        l.clear(); //
        l.resize(n-1); //

        u.clear(); //
        u.resize(n-1); //

        for(int i=0;i<n-1;i++){
            l[i]=min(p[i],p[i+1]);
            u[i]=max(p[i],p[i+1]);
        }
        
        ltree = new vi[5*n]; //
        utree = new vi[5*n]; //

        n--;

        build_tree(ltree,l,1,0,n-1);
        build_tree(utree,u,1,0,n-1);

        while(q--){

            int a,b,y;
            a=sscan();
            b=sscan();
            y=sscan();

            int total = b-a;
            
            a--;
            b-=2;

            int lq = lquery(ltree,1,0,n-1,a,b,y);
            int rq = uquery(utree,1,0,n-1,a,b,y);

            cout<<total-(lq+rq)<<endl;
        }
    }    
}