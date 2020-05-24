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
        int a,b;
        cin>>a>>b;

        if(a==b)
            cout<<0<<endl;
        else if(a<b)
        {
            if((b-a)&1)
                cout<<1<<endl;
            else
            {
                cout<<2<<endl;
            }
            
        }
        else
        {
            if((a-b)%2==0)
                cout<<1<<endl;
            else
            {
                cout<<2<<endl;
            }
            
        }
        
     }
    
}