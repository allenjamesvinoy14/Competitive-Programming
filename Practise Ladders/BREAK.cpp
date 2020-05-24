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

int main(){

    int t,s;
    cin>>t>>s;

    while(t--){
        int n;
        cin>>n;

        multiset<int> a,b;
        int temp;

        rep(i,0,n){
            cin>>temp;
            a.insert(temp);
        }
        rep(i,0,n){
            cin>>temp;
            b.insert(temp);
        }

        set<int> table;
        table.insert(*a.begin());
        table.insert(*b.begin());

        bool ans = true;

        for(int i=0;i<n;i++){
            int x1 = *a.begin();
            int x2 = *b.begin();

            if(a>=b){
                ans = false;
                break;
            }

            if(table.find(x1)==table.end())
            {
                ans = false;
                break;
            }

            table.insert(*a.begin());
            table.insert(*b.begin());
            
            a.erase(a.begin());
            b.erase(b.begin());
        }

        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
}