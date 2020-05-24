#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
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

int Logn(ll n,int r) 
{ 
    int count = 0;

    while(n){
        n/=r;
        count++;
    }

    return count-1;
} 
bool isPower(int x, ll y) 
{ 
    if (x == 1) 
        return (y == 1); 
  
    ll pow = 1; 
    while (pow < y) 
        pow *= x; 
  
    return (pow == y); 
} 

int main(){

    int t;
    cin>>t;

    while(t--){

        int n,k;
        cin>>n>>k;


        set<double> a;

        int dup = n;

        rep(i,0,n){
            double temp;
            cin>>temp;

            if(temp==0) dup--;

            else a.insert(temp);
        }

        n=dup;

        if(n==1)
        {
            if(*a.begin()==1)
            {
                cout<<"YES\n";
                continue;
            }
        }

        if(n==0)
        {
            cout<<"YES\n";
            continue;
        }
        

        bool ans = true;


        if(a.size()!=n)
        {
            ans = false;
        }
        else
        {
            bool vis[100001] = {0};

            for(auto i:a){
                cout<<i<<endl;

                if(i==0)
                    continue;
                if(!isPower(k,i))
                {
                    //cout<<"check"<<endl;
                    while(i>0){
                        int j = Logn(i,k);
                        cout<<i<<" "<<j<<endl;
                        if(vis[j])
                        {
                            ans = false;
                            break;
                        }
                        vis[j]=1;
                        i-=pow(k,j);
                    }
                }
                else
                {
                    vis[Logn(i,k)]=1;
                }
                
            }
        }

        if(ans) cout<<"YES\n";
        else cout<<"NO\n";

    }
    
}