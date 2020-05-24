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

    // int t;
    // cin>>t;

    // while(t--){
        int n;
        cin>>n;

        queue<int> pos,neg,rest;

        rep(i,0,n){
            int temp;
            cin>>temp;


            if(temp>0) pos.push(temp);

            else if(temp<0) neg.push(temp);

            else rest.push(temp);


        }

        cout<<1<<" "<<neg.front()<<endl;
        neg.pop();

        if(pos.size()==0){
            cout<<2<<" ";
            cout<<neg.front()<<" ";
            neg.pop();
            cout<<neg.front()<<" ";
            neg.pop();
        }
        else
        {
            cout<<1<<" ";
            cout<<pos.front()<<" ";
            pos.pop();
        }
        cout<<endl;

        cout<<rest.size()+pos.size()+neg.size()<<" ";
        
        cout<<rest.front()<<" ";
        rest.pop();

        rep(i,0,neg.size()){
            cout<<neg.front()<<" ";
            neg.pop();
        }
        rep(i,0,pos.size()){
            cout<<pos.front()<<" ";
            pos.pop();
        }
        cout<<endl;
    // }
    
}