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
        cin>>n;

        if(n==0){
            cout<<0<<" "<<0<<" "<<0<<endl; 
            return 0;
        }

        if(n==1){
            cout<<0<<" "<<0<<" "<<1<<endl;
            return 0;
        }


        vi f;

        int a=0;
        int b=1; 

        while(b<n){
            int temp = a;
            a=b;
            b+=temp;
        }

        cout<<0<<" "<<b-a<<" "<<a<<endl;
    // }
    
}   