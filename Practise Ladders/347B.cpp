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

        int a[n],b[n];
        rep(i,0,n){

            cin>>a[i];
            b[i] = a[i];
        }
        
        sort(a,a+n);

        int count = n;
        
        int val = 1;
        
        rep(i,0,n){

            if(a[i]!=b[i])
            {
                count--;
                if(b[b[i]]==a[i]) val = 2; 
            }
        }

        if(count == n)
            cout<<count<<endl;
        else cout<<count+val<<endl;
    // }
}