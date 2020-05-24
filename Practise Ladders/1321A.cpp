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
        int n;
        cin>>n;

        int a[n];

        int k,l;

        k=l=0;

        rep(i,0,n){
            cin>>a[i];
        }
        rep(i,0,n){

            int x;
            cin>>x;

            if(!x and a[i]) l++;
            if(x and !a[i]) k++;
        }

        if(l==0) cout<<-1<<endl;
        else cout<<k/l+1<<endl;
    //}
}