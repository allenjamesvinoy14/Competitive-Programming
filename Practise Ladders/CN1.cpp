#include<bits/stdc++.h>
using namespace std;

int div(int n){
    int limit = sqrt(n);
    //cout<<limit<<endl;

    int count = 2;

    for(int i=2;i<=limit;i++){
        if(i==limit and i*i==n){
            count++;
        }
        else if(n%i==0)
            count+=2;
    }

    return count;
}
bool isp(int n){
    int limit = sqrt(n);

    for(int i=2;i<=limit;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

int main() {
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        if(n==1)
        {
            cout<<"NO\n";
            continue;
        }

        int d = div(n);

        //cout<<d<<endl;

        if(isp(d))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}