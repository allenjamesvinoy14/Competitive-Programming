#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define vvl vector<vector<ll>>
#define pl pair<ll,ll>
#define vvi vector<vector<int>>
#define pi pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define mpc map<char,int>
#define MOD 1000000007
#define M 998244353 
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<b;i++)
#define all(t) t.begin(),t.end()
#define sz size()

int modInverse(int a,int m) { 
    int m0 = m; 
    int y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        int q = a / m; 
        int t = m; 
  
        m = a % m, a = t; 
        t = y; 
  
        y = x - q * y; 
        x = t; 
    } 

    if (x < 0) 
       x += m0; 
  
    return x; 
} 

void print_prob(map<int,int> &ans){

    int m = M;

    // ans[0] = ((ans[0]%M)*modInverse(ans[4],m)%M)%M;
    // ans[1] = ((ans[1]%M)*modInverse(ans[4],m)%M)%M;
    // ans[2] = ((ans[2]%M)*modInverse(ans[4],m)%M)%M;
    // ans[3] = ((ans[3]%M)*modInverse(ans[4],m)%M)%M;
 
    cout<<(ans[0])<<" "<<(ans[1])<<" "<<(ans[2])<<" "<<(ans[3])<<endl; 

}

map<int,int> initialise(char op){

    map<int,int> ans;

    if(op == '&'){
        ans[0] = 9;
        ans[1] = 1;
        ans[2] = 3;
        ans[3] = 3;
        ans[4] = 16;
    }
    else if(op == '|'){
        ans[0] = 1;
        ans[1] = 9;
        ans[2] = 3;
        ans[3] = 3;
        ans[4] = 16;
    }
    else{
        ans[0] = 4;
        ans[1] = 4;
        ans[2] = 4;
        ans[3] = 4;
        ans[4] = 16;
    }

    return ans;

}

map<int,int> one_missing(map<int,int> &a,char op){

    map<int,int> ans;

    if(op == '&'){
        ans[0] = ((a[0]*4)%M + a[1] + (a[2]*2)%M + (a[3]*2)%M)%M;
        ans[1] = a[1];
        ans[2] = (a[1] + (a[2]*2)%M)%M;
        ans[3] = (a[1] + (a[3]*2)%M)%M;
        ans[4] = (a[4]*4)%M;
    }
    else if(op == '|'){
        ans[0] = a[0];
        ans[1] = ((a[1]*4)%M + a[0] + (a[2]*2)%M + (a[3]*2)%M)%M;
        ans[2] = (a[0] + (a[2]*2)%M)%M;
        ans[3] = (a[0] + (a[3]*2)%M)%M;
        ans[4] = (a[4]*4)%M;
    }
    else{
        ans[0] = a[4]%M;
        ans[1] = a[4]%M;
        ans[2] = a[4]%M;
        ans[3] = a[4]%M;
        ans[4] = (a[4]*4)%M;
    }

    return ans;
}

map<int,int> both(map<int,int> &a,map<int,int> &b,char op){

    map<int,int> ans;

    if(op=='&'){
        ans[0] = ((a[0]*b[0])%M + (a[0]*b[1])%M + (a[0]*b[2])%M + (a[0]*b[3])%M + (b[0]*a[1])%M + (b[0]*a[2])%M + (b[0]*a[3])%M + (a[2]*b[3])%M + (a[3]*b[2])%M)%M;
        ans[1] = (a[1]*b[1])%M;
        ans[2] = ((a[2]*b[1])%M + (b[2]*a[1])%M + (a[2]*b[2])%M)%M;
        ans[3] = ((a[3]*b[1])%M + (b[3]*a[1])%M + (a[3]*b[3])%M)%M;
        ans[4] = (a[4]*b[4])%M;
    }
    else if(op=='|'){
        ans[0] = (a[0]*b[0])%M;
        ans[1] = ((a[1]*b[0])%M + (b[1]*a[0])%M + (a[1]*b[2])%M + (a[1]*b[3])%M + (b[1]*a[2])%M + (b[1]*a[3])%M + (a[2]*b[3])%M + (a[3]*b[2])%M + (a[1]*b[1])%M)%M;
        ans[2] = ((a[2]*b[0])%M + (b[2]*a[0])%M + (a[2]*b[2])%M)%M;
        ans[3] = ((a[3]*b[0])%M + (b[3]*a[0])%M + (a[3]*b[3])%M)%M;
        ans[4] = (a[4]*b[4])%M;
    }
    else{
        ans[0] = ((a[0]*b[0])%M + (a[1]*b[1])%M + (a[2]*b[2])%M + (a[3]*b[3])%M)%M;
        ans[1] = ((a[0]*b[1])%M + (a[1]*b[0])%M + (a[2]*b[3])%M + (a[3]*b[2])%M)%M;
        ans[2] = ((a[2]*b[0])%M + (a[0]*b[2])%M + (a[3]*b[1])%M + (a[1]*b[3])%M)%M;
        ans[3] = ((a[3]*b[0])%M + (a[0]*b[3])%M + (a[2]*b[1])%M + (a[1]*b[2])%M)%M;
        ans[4] = (a[4]*b[4])%M;
    }

    return ans;
}

int32_t main(){

    int t;
    cin>>t;

    while(t--){
        string s;
        
        cin>>s;
        int n = s.length();
        
        map<int,int> ans;
        
        if(s=="#"){
            ans[0] = 1;
            ans[1] = 1;
            ans[2] = 1;
            ans[3] = 1;
            ans[4] = 4;
            print_prob(ans);
            continue;
        }
        
        stack<pair<char,int>> p;
        stack<map<int,int>> probs;

        int i;
        for(i=0;i<n;i++){
            if(s[i]!='#'){  

                if((s[i]=='&' or s[i]=='|' or s[i]=='^') and (s[i-1]=='#' and s[i+1]=='#')){
                    map<int,int> a = initialise(s[i]);
                    probs.push(a);
                    p.pop();
                    i+=2;
                    continue;
                }

                if(s[i]==')'){

                    char op = p.top().F;
                    int idx = p.top().S;
                    p.pop();
                    p.pop();

                    if((s[idx-1]=='#' and s[idx+1]=='(') or (s[idx-1]==')' and s[idx+1]=='#')){
                        map<int,int> a = probs.top();
                        probs.pop();
                        map<int,int> updated = one_missing(a,op);
                        probs.push(updated);
                    }
                    else if(s[idx-1]==')' and s[idx+1]=='('){

                        map<int,int> a = probs.top();
                        probs.pop();
                        map<int,int> b = probs.top();
                        probs.pop();

                        map<int,int> updated = both(a,b,op);
                        probs.push(updated);
                    }

                }
                else{
                    p.push({s[i],i});
                }
            }
        }

        ans = probs.top();

        print_prob(ans);
           
    }
    
}