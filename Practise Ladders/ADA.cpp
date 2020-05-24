#include<bits/stdc++.h>
using namespace std;
#define ll long long int
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

int main(){

    int t;
    cin>>t;

    while(t--){
        int x,y;
        cin>>x>>y;

        int count = 0;

        if(x==1 and y==1) count = 25;
        else if(x==y) count=26;
        else count = 27;

        cout<<count<<endl;

        if(count==26)
        {
            cout<<1<<" "<<1<<endl;
        }
        if(count==27)
        {
            int sum=x+y;

            for(int i=2;i<=7;i++){
                if(i+i==sum)
                {
                    cout<<i<<" "<<i<<endl;
                    break;
                }
            }
            cout<<1<<" "<<1<<endl;
        }

        cout<<2<<" "<<2<<endl;
        cout<<1<<" "<<3<<endl;
        cout<<3<<" "<<1<<endl;
        cout<<2<<" "<<2<<endl;

        cout<<3<<" "<<3<<endl;
        cout<<1<<" "<<5<<endl;
        cout<<5<<" "<<1<<endl;
        cout<<3<<" "<<3<<endl;

        cout<<4<<" "<<4<<endl;
        cout<<1<<" "<<7<<endl;
        cout<<7<<" "<<1<<endl;
        cout<<4<<" "<<4<<endl;

        cout<<5<<" "<<5<<endl;
        cout<<2<<" "<<8<<endl;
        cout<<8<<" "<<2<<endl;
        cout<<5<<" "<<5<<endl;

        cout<<6<<" "<<6<<endl;
        cout<<4<<" "<<8<<endl;
        cout<<8<<" "<<4<<endl;
        cout<<6<<" "<<6<<endl;

        cout<<7<<" "<<7<<endl;
        cout<<6<<" "<<8<<endl;
        cout<<8<<" "<<6<<endl;
        cout<<7<<" "<<7<<endl;

        cout<<8<<" "<<8<<endl;
    }
    
}