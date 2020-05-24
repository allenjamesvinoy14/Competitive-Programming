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

        int a[n+1];
        int count[n+1];

        rep(i,1,n+1){
            cin>>a[i];

            count[a[i]]++;
        } 

        vi prob;
        vi safe;
        vi places;

        for(int i=1;i<=n;i++){
            if(count[i]==0 and a[i]==0) prob.pb(i);
            else if(count[i]==0) safe.pb(i);
            else if(a[i]==0) places.pb(i); 
        }

        int pz = prob.size();
        int sz = safe.size();

        if(prob.size()==1)
        {
            a[prob[0]] = safe[0];
            a[places[0]] = prob[0];

            for(int i  = 1;i<safe.size();i++)
            {
                a[places[i]] = safe[i]+1;
            }
        }

        else if(prob.size()>1){
            
            for(int i=0;i<pz-1;i++){
                a[prob[i]] = prob[i+1];
            }

            a[prob[pz-1]] = prob[0];

            for(int i=0;i<sz;i++){
                a[places[i]] = safe[i];
            }
        }

        else{
            for(int i=0;i<sz;i++){
                a[places[i]] = safe[i];
            }
        }   

        for(int i = 1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    // }
    
}