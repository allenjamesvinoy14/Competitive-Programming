#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vvl vector<set<ll>>
#define pl pair<ll,ll>
#define vvi vector<set<int>>
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

vvi adj;

int main(){

    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;

        bool ans =false; 

        set<int> val;

        adj = vvi(n);

        vi un;

        rep(i,0,n){
            int k;
            cin>>k;

            int temp;

            bool cond = true;

            while(k--){
                cin>>temp;
                adj[i].insert(temp);

                if(val.find(temp)==val.end() and cond){
                    val.insert(temp);
                    cond = false;
                }
            }

            if(cond){
                un.pb(i);
            }
        }

        if(val.size()==n){
            cout<<"OPTIMAL"<<endl;
        }
        else
        {
            cout<<"IMPROVE"<<endl;
            for(int i=1;i<=n;i++){
                if(val.find(i)==val.end()){
                    for(auto j: un){
                        if(adj[j].find(i)==adj[j].end()){
                            cout<<j+1<<" "<<i<<endl;
                            ans = true;
                            break;
                        }
                    }
                    if(ans) break;
                } 
            }
        }
    }
    
}