#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define vvi vector<vector<ll>>
#define MOD 1000000007
#define M 1000000007

void mat_mul(ll a[2][2], ll b[2][2])
{
    ll f=(a[0][0]*b[0][0]+a[0][1]*b[1][0])%MOD;
    ll s=(a[0][0]*b[0][1]+a[0][1]*b[1][1])%MOD;
    ll t=(a[1][0]*b[0][0]+a[1][1]*b[1][0])%MOD;
    ll ft=(a[1][0]*b[0][1]+a[1][1]*b[1][1])%MOD;
    
    a[0][0]=f;
    a[0][1]=s;
    a[1][0]=t;
    a[1][1]=ft;
}

void expo(ll a[2][2],ll n){
    
    ll res[2][2];
    res[0][0]=1;
    res[0][1]=0;
    res[1][0]=0;
    res[1][1]=1;

    while (n > 0) {
        if (n & 1)
            mat_mul(res,a);

        mat_mul(a,a);
        n >>= 1;
    }
    
    a[0][0]=res[0][0];
    a[0][1]=res[0][1];
    a[1][0]=res[1][0];
    a[1][1]=res[1][1];

}
