#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vvl vector<vector<ll>>
#define pl pair<ll,ll>
#define vvi vector<vector<int>>
#define pi pair<int,int>
#define vi vector<pi>
#define vl vector<ll>
#define mpc map<char,int>
#define MOD 1000000007
#define M 1000000007
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<b;i++)

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
}

int fprime(int n) 
{ 
    if (n % 2 == 0) 
        return 2; 
    for (int i = 3; i * i <= n; i += 2) { 
        if (n % i == 0) 
            return i; 
    } 
  
    return n; 
} 
int32_t main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int a[n];
        rep(i,0,n) cin>>a[i];

        map<int,vi> col;

        for(int i=0;i<n;i++){
            int prime = fprime(a[i]);
            col[prime].push_back(mp(a[i],i));
        }

        int count = 1;

        vector<int> ans(n);

        for(auto i: col){
            for(auto j:i.S){
                ans[j.S] = count;
            }
            count++;
        }

        cout<<count-1<<endl;

        for(auto i: ans) cout<<i<<" ";
        cout<<endl;
    }
}