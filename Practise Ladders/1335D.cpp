#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define MX 1e19
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
#define all(t) t.begin(),t.end()
#define sz size()

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--){
        
        vector<string> s;

        for(int i=0;i<9;i++){
            string str;
            cin>>str;
            s.pb(str);
        }

        for(int i=0;i<9;i++){
            string temp = s[i];
            
            int val = temp[0]-'0';

            if(val<9) val+=1;
            else val = 1;

            temp[0] = val+'0';
            cout<<temp<<endl;
        }
    }
    
}