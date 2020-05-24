#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define vvi vector<vector<ll>>
#define pi pair<ll,ll>
#define MOD 1000000007
#define M 1000000007

int main(){
    int n,a,b;
    cin>>n>>a>>b;

    if(b==0)
    {    cout<<1;
        return 0;
    }

    a = n-a;

    if(a>b)
        cout<<b+1<<endl;
    else
    {
        cout<<a<<endl;
    }
}