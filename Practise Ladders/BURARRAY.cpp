#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

map<ll, ll> par;

//getPar is nothing but find function of a Disjoint Sets
//here map is used for implementation purposes since the input size is large
ll getPar(ll v){
	if (!par.count(v))
		par[v] = v;
	return par[v]==v? v: par[v]=getPar(par[v]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int te;	cin >> te;
	while (te--){
		par.clear();
		ll sm = 0;
		ll n; int q; cin >> n >> q;
		while (q--){
			int type; cin >> type;
			if (type == 1){
				ll x; cin >> x; x += sm;
				par[x] = x-1;
			}
			else{
				ll l, r; cin >> l >> r; l += sm, r += sm;
				ll p = getPar(r);
				if (p < l)
					cout << "0\n";
				else {
					cout << p << "\n";
					sm = (sm + p)%n;
				}
			}
		}
	}
	return 0;
}