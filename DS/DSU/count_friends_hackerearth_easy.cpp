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

int par[100005];
int ans[100005];

int func(int x){
  if(x!=par[x]){
    par[x] = func(par[x]);
  }
  return par[x];
}

int main(){
  int n,m,u,v;

  cin>>n>>m;

  for(int i=0;i<=n;i++){
    par[i]=i;
  }    

  while(m--){
    int a,b;

    cin>>u>>v;

    a=func(u);
    b=func(v);

    if(par[a] == par[b]){
      continue;
    }

    par[a]=par[b];
  }

  for(int i=1;i<=n;i++){
    ans[func(i)]++;
  }

  for(int i=1;i<=n;i++){
    cout<<ans[func(i)]-1<<" ";
  }

  cout<<endl;
  return 0;

}
