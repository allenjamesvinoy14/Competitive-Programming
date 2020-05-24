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

    int t;
    cin>>t;

    while(t--){
        int n;

        int a[3];
        rep(i,0,3) cin>>a[i];

        sort(a,a+3);

        cin>>n;

        n-=(a[2]-a[0]);
        n-=(a[2]-a[1]);

        if(n<0 || n%3!=0){
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n"<<endl;
        }
        
    }
    
}