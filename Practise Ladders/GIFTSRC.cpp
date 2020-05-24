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
        int n;
        cin>>n;

        string in;
        cin>>in;
        
        string f="";

        char c = in[0];
        f+=c;

        for(int i=1;i<n;i++){
            if(c=='U' or c=='D'){
                if(in[i]=='L' or in[i]=='R'){
                    c=in[i];
                    f+=c;
                }
            }
            else
            {
                if(in[i]=='U' or in[i]=='D'){
                    c=in[i];
                    f+=c;
                }
            }    
        }

        n = f.size();

        pi ans;
        ans.F=0;
        ans.S=0;

        for(int i=0;i<n;i++){
            if(f[i]=='L') ans.F-=1;
            else if(f[i]=='R') ans.F+=1;
            else if(f[i]=='U') ans.S+=1;
            else ans.S-=1;
        }
    }
    
}