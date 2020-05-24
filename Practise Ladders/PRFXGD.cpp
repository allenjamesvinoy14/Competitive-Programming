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

int32_t main(){

    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        int n = s.length();

        int x,k;

        cin>>k>>x;

        mpc freqs;

        int count = 0;

        for(int i=0;i<n;i++){
            freqs[s[i]]++;

            if(freqs[s[i]]>x){
                if(k>0){
                    freqs[s[i]]--;
                    k--;
                    count--;
                }
                else
                {
                    break;
                }
            }
            count++;
        }   
        cout<<count<<endl;

    }
    
}