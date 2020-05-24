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
            int n,k;
            cin>>n>>k;

            int arr[n];

            rep(i,0,n){
                cin>>arr[i];
            }
    // }    

            sort(arr,arr+n);

            if(arr[0]>0)
            {
                if(k&1)
                    arr[0]=-arr[0];
            }
            else if(arr[n-1]<0)
            {
                rep(i,0,n)
                {   
                    if(k>0){
                        arr[i]=abs(arr[i]);
                        k--;
                    }
                }
                if(k&1)
                    arr[n-1]=-arr[n-1];
            }
            else{
                for(int i=0;i<n;i++){
                    if(k>0){
                        if(arr[i]>0)
                        {
                            if(k&1){
                                if(arr[i]>arr[i-1])
                                {
                                    arr[i-1]=-arr[i-1];
                                }
                                else
                                {
                                    arr[i]=-arr[i];
                                }
                            }   
                            break;
                        }   
                        arr[i]=abs(arr[i]); 
                        k--;
                    }
                }
            }

            ll sum=0;
            for(int i=0;i<n;i++) sum+=arr[i];
            cout<<sum<<endl;
}