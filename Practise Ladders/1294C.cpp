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
        int org=n;

        int l = sqrt(n);

        set<int> ans;
        //bool ans = true;

        for(int i=2;i<=l;i++){

            if(ans.size()==2) break;

            if(n%i==0)
            {
                n/=i;
                ans.insert(i);
            }
        }
        
        if(ans.find(n)==ans.end() and ans.size()==2)
        {
            cout<<"YES\n";
            for(auto i:ans)
                cout<<i<<" ";
            cout<<n<<endl;
        }
        else
        {
            cout<<"NO\n";
        }   
    }
}