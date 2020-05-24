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
        int n,p;
        cin>>n>>p;

        int a[n];
        rep(i,0,n) cin>>a[i];

        bool ans = false;

        int idx,val;

        for(int i=n-1;i>=0;i--){
            if(p%a[i]!=0)
            {
                idx=i;
                val=p/a[i]+1;
                ans=true;
                break;
            }
        }

        if(!ans){
            int idx1=-1,idx2=-1;

            rep(i,0,n-1){
                if(a[i+1]%a[i]!=0)
                {
                    idx1=i;
                    idx2=i+1;        
                }
            }
            if(idx1!=-1){
                cout<<"YES ";
                rep(i,0,n){
                    if(i==idx1)
                    {
                        cout<<(p-a[i+1])/a[i]+1<<" ";
                    }
                    else if(i==idx2)
                        cout<<1<<" ";
                    else 
                        cout<<0<<" ";
                }
                cout<<endl;
            }
            continue;
        }

        if(ans)
        {
            cout<<"YES ";

            rep(i,0,n){

                if(i==idx)
                    cout<<val;
                else
                    cout<<0;
                cout<<" ";
            }

            cout<<"\n";
        }
        else
        {
            cout<<"NO\n";
        }
        
    }
}