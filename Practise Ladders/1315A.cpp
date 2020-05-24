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
        int a,b,x,y;
        cin>>a>>b>>x>>y;

        ll mv = INT_MIN;

        ll ma = a*b;

        ll temp = a*(b-y-1);
        if(temp<ma) mv = max(mv,temp);

        temp = a*(y);
        if(temp<ma) mv = max(mv,temp);

        temp = b*(a-x-1);
        if(temp<ma) mv = max(mv,temp);

        temp = b*(x);
        if(temp<ma) mv = max(mv,temp);

        cout<<mv<<endl;

    }
    
}