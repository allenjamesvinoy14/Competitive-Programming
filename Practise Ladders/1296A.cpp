#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define vvi vector<vector<ll>>
#define pi pair<ll,ll>
#define MOD 1000000007
#define M 1000000007

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;

        cin>>n;
        int c[2]={0};
        
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;

            if(temp&1)
                c[1]++;
            else
            {
                c[0]++;
            }
            
        }

        if(c[1]==0)
            cout<<"NO\n";
        else if(n%2==0 and c[0]==0)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
        }
        
    }
}