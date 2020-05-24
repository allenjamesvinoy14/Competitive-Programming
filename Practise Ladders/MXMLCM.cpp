//question on prime factorisation

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

vector<int> pc(10005, 0);

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
int32_t main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        
        pc.clear();
        pc.resize(10005,0);

        int n,m;
        cin>>n>>m;

        int num;

        rep(i,0,n){
            cin>>num;
            factorise(num);
        } 

        int factor=1;
        int ans=1;

        for(int i=2;i<=m;i++){

            int dup = i;
            int tempfac = 1;

            for(int j=2;j<=sqrt(dup);j++){

                int cnt = 0;
                while(dup%j == 0){

                    dup /= j;
                    ++cnt;

                }

                if(cnt>pc[j]){
                    tempfac*=power(j,cnt-pc[j]); 
                }

            }

            if(dup>1){
                if(pc[dup] == 0) tempfac*=dup;
            }

            if(factor<tempfac){
                ans = i;
                factor = tempfac;
            }
        }

        cout<<ans<<endl;
    }
}