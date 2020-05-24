#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define MX 1e19
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
#define all(t) t.begin(),t.end()
#define sz size()

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

int findmultiples(int x, int y, int l, int r) 
{ 
    int lcm = (x * y) / gcd(x, y); 
  
    int countl = (l - 1) / lcm; 
  
    int countr = r / lcm; 

    return countr - countl; 
} 
int findlast(int x, int y, int l, int r) 
{ 
    int lcm = (x * y) / gcd(x, y); 

    int countr = r / lcm; 

    return countr*lcm; 
} 
int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        int a,b,q;
        cin>>a>>b>>q;

        a = min(a,b);
        b = max(a,b);

        while(q--)
        {
            int l,r;
            cin>>l>>r;

            if(max(l,r)<b){
                cout<<0<<" ";
                continue;
            }

            if(b%a == 0){
                cout<<0<<" ";
                continue;
            }

            if(l>=a and r<b){
                cout<<0<<" ";
                continue;
            }

            int total = r-l+1;

            int val = findmultiples(a,b,l,r);

            int last = findlast(a,b,l,r);

            if(val!=0)
                total -= ((val-1)*b);

            if(val!=0)
                total -= min(b,r-last+1);

            int re = 0;
            if(l<b) re = b-l;

            cout<<total-re<<" ";
        }

        cout<<endl;
    } 
}