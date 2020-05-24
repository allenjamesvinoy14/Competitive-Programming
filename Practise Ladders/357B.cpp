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

    // int t;
    // cin>>t;

    // while(t--){
        int n,m;
        cin>>n>>m;

        int a[n+1] = {0};
        
        set<int> s;

        rep(i,0,3)
            s.insert(i+1);
        
        int x,y,z;
        cin>>x>>y>>z;

        a[x] = 1;
        a[y] = 2;
        a[z] = 3;
        m--;

        while(m--)
        {
            cin>>x>>y>>z;
            queue<int> q;

            if(a[x]!=0)
            {
                s.erase(a[x]);
                
            }
            if(a[y]!=0)
            {
                s.erase(a[y]);
            }
            if(a[z]!=0)
            {
                s.erase(a[z]);
            }            
        }
    // }    
}