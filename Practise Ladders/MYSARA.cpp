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

vi bits(31);

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        
        bits.clear();

        int a[n];
        rep(i,0,n) cin>>a[i];

        int ans = 1;
        
        for(int i=0;i<31;i++){
            bits[i] = ((a[0]>>i)&1);
        }
        
        for(int i=1;i<n;i++){
            
            for(int j=0;j<31;j++){
                int bit = ((a[i]>>j)&1);
                
                if(bit and bits[j]) ans = (ans*2)%M;
                else if(bit) bits[j]=1;
                else if(bits[j]) ans = ans = ans*0;
            }
            
        }
        
        cout<<ans%M<<endl;
        
    }
    
}
