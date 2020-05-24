#include<bits/stdc++.h>
using namespace std;
#define int long long int
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

vector<int> pc(50005, 0);

void factorise(int num){

    int limit = num;

    for(int i=2;i<=sqrt(num);i++){

        int cnt = 0;
        while(num%i == 0){

            num /= i;
            ++cnt;

        }

        pc[i] = max(cnt,pc[i]);

    }
    if(num>1){
        pc[num] = max(1LL,pc[num]); 
    }
}

int power(int a, int b) {
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
        
    int x = pow(a, b/2);
    
    if(b%2)
        return x * x * a;
    else
        return x * x;
}

int32_t main(){

    int t;
    cin>>t;

    while(t--){

        int x,k;
        cin>>x>>k;
        
        if(k>30){
            cout<<0<<endl;
            continue;
        }
        
        bool ans = true;
        
        int mn = power(2,k);


        if(x<mn) ans = false;
        
        pc.resize(50005, 0);
        factorise(x);

        int total = 0;

        for(auto i: pc){
            total+=i;
        }

        if(k>total) ans = false;

        if(ans) cout<<1<<endl;
        else cout<<0<<endl;
    }
    
}