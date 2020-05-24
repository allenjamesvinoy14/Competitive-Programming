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

        int arr[n];
        rep(i,0,n) cin>>arr[i];

        int s=0;

        while(m--){

            int v,x,y,q;

            int t;

            cin>>t;

            if(t==1)
            {
                cin>>v>>x;

                arr[v-1]=x-s;
            }
            else if(t==2)
            {
                cin>>y;

                s+=y;

            }   
            else
            {
                cin>>q;

                cout<<arr[q-1]+s<<endl;
            }

        }

    // }
    
}