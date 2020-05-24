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
int divtest(int n){
    int count = 0;

    for(int i=1;i<=n;i++){
        if(n%i==0)
            count++;
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
    // int t;
    // cin>>t;

    int n=1;
    while(n<1000000){
        if(n==1)
        {
            cout<<"NO\n";
            n++;
            continue;
        }

        int d = div(n);
        int d2 = divtest(n);

        if(d!=d2)
            cout<<n<<" "<<d<<" "<<d2<<endl;
        
        n++;
    }
    return 0;
}