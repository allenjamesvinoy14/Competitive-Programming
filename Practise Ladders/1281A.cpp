#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define vvi vector<vector<ll>>
#define pi pair<ll,ll>
#define MOD 1000000007
#define M 1000000007
#define F first
#define S second
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        string su="";

        int n=s.length();

        for(int i=n-1;i>=n-5;i--)
        {
            //cout<<"check\n";
            su=s[i]+su;
            //cout<<su<<endl;
            if(i==n-2 and su=="po")
            {
                cout<<"FILIPINO\n";
                break;
            }    
            if(i==n-4 and (su=="desu" or su=="masu"))
            {
                cout<<"JAPANESE\n";
                break;
            }
            if(i==n-5 and su=="mnida")
            {
                cout<<"KOREAN\n";
                break;
            }
        }
    }   
}