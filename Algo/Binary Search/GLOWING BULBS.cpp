// example for binary search

#include<bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define ll long long int
vi primes;

ll condition(ll mid){

    int sz = primes.size();

    int p = 1<<sz;

    ll ans=0;

    for(int i=1;i<p;i++){

        int j=0;

        ll temp=1;
        int sign=-1;

        for(;j<sz;j++){
            if((i>>j)&1)
            {
                temp*=primes[j];
                sign*=-1;
            }
        }

        ans += sign*(mid/temp);
    }

    return ans;
}
ll solve(ll k){

    ll res;

    ll lo = 1;
    ll hi = 1000000000000000000LL; //max possible value to store in LL 

    while(lo<=hi){

        int mid = (lo+hi)>>1;

        if(condition(mid)>=k){
            res = mid;
            hi = mid-1;
        }
        else 
        {
            lo = mid+1;
        }
    }

    return res;

}
int main(){

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;

        primes.clear();

        for(int i=0;i<40;i++){
            if(s[i]=='1') primes.push_back(i+1);
        }

        ll k;
        cin>>k;


        ll ans = solve(k);
        
        cout<<ans<<endl;
    }
}