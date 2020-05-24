#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back

int idxi[8001];
vi pre;
vi in;
vi post;
vvi adj;

void fill(int n){
    for(int i=0;i<n;i++) idxi[in[i]] = i;
}

void solve(int pl,int pr,int l,int r)
{
    if(pl>=pr)
        return;

    int root = pre[pl];
    int idx = idxi[root];

    int nleft = idx-l;
    int nright = r-idx;

    if(nleft>0){
        adj[root].pb(pre[pl+1]);
        solve(pl+1,pl+nleft,l,idx-1);
    }
    if(nright>0){
        adj[root].pb(pre[pr-nright+1]);
        solve(pr-nright+1,pr,idx+1,r);
    }
}

// void solve(int pre_l,int pre_r,int in_l,int in_r){
// 	if(pre_l>=pre_r)return;
// 	int root=pre[pre_l];
// 	int idx=idxi[root];
// 	int n_left=idx-in_l,n_right=in_r-idx;

// 	if(n_left>0){
// 		adj[root].pb(pre[pre_l+1]);	
// 		solve(pre_l+1,pre_l+n_left,in_l,idx-1);
// 	}
// 	if(n_right>0){
// 		adj[root].pb(pre[pre_r-n_right+1]);
// 		solve(pre_r-n_right+1,pre_r,idx+1,in_r);
// 	}

// }

vi post_new;
void postorder(int p){
	for(int i=0;i<adj[p].size();i++){
		postorder(adj[p][i]);
	}
	post_new.pb(p);
}
int main(){

    int n;
    cin>>n;

    pre.resize(n);
    post.resize(n);
    in.resize(n);

    adj.resize(n+1,vi(0));

    for(int i=0;i<n;i++) cin>>pre[i];
    for(int i=0;i<n;i++) cin>>post[i];
    for(int i=0;i<n;i++) cin>>in[i];

    fill(n);

    solve(0,n-1,0,n-1);

    postorder(pre[0]);
	int flag=1;
	for(int i=0;i<n;i++)if(post_new[i]!=post[i])flag=0;
	if(flag)cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}