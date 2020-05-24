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
        int n,k;
        cin>>n>>k;

        set<pi> edges;

        int arr[n];

        while(k--){

            for(int i=0;i<n;i++) cin>>arr[i];

            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){

                    int x=arr[i];
                    int y=arr[j];

                    if(edges.find(mp(y,x))!=edges.end())
                    {
                        edges.erase(mp(y,x));
                    }
                    else
                    {
                        edges.insert(mp(x,y));
                    }
                }
            }

        }

        int ans[n]={0};

        int vis[n+1]={0};

        for(auto e:edges){
            int i = e.F;
            int j = e.S;

            //cout<<i<<" "<<j<<endl;

            if(!vis[j] and !ans[i-1]){
                ans[i-1]=j;
                vis[j]=1;
            }
        }

        int count = 0;
        for(int i=0;i<n;i++){
            if(ans[i]==0) count++;
        }

        cout<<count<<endl;
        for(int i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
    
}