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
#define all(t) t.begin(),t.end()
#define sz size()
#define pvi pair<int,vi>

int ans[500005][5];

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    scanf("%d",&t);

    while(t--){
        
        int n;
        scanf("%d",&n);

        int limit = (n>>1 > 0)?n>>1:1;

        bool flag = true;
        
        int size[limit+1] = {0};

        for(int i=1;i<=n;i++){
            
            if(i%2==0){
                
                int idx = i;
                idx = idx>>1;
                idx--;
                
                ans[idx][size[idx]] = i;
                size[idx]++;
                
            }
            else{
                if(i==1 or i==3 or i==5 or i==7){
                    ans[0][size[0]] = i;
                    size[0]++;
                    continue;
                }
                else{

                    int idx = (flag)?i-1:i+1;

                    idx = idx>>2;
                    idx--;
                    
                    ans[idx][size[idx]] = i;
                    size[idx]++;
                    
                    flag = !flag;

                }
            }
            
        }

        printf("%d\n",limit);
        
        for(int i=0;i<limit;i++){
            printf("%d ",size[i]);
            for(int j=0;j<size[i];j++) printf("%d ",ans[i][j]);
            printf("\n");
        }
    }
    
}