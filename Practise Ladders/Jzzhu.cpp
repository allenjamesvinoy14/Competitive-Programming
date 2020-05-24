#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007 

int main(){
    int x,y,n;

    cin>>x>>y>>n;

    int arr[6] = {x,y,y-x,-x,-y,x-y};

    int ans = arr[(n-1)%6]%MOD;

    //cout<<ans<<endl;
    
    if(ans<0)
        ans = MOD+ans;
    //cout<<arr[n%6]%MOD<<endl;

    cout<<ans<<endl;
}