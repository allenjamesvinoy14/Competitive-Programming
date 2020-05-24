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
        string s,c;

        cin>>s>>c;

        int freqs[26] = {0};
        int lastloc[26] = {0};
        
        for(int i=0;i<s.length();i++){
            char c=s[i];
            freqs[c-65]++;
            lastloc[c-65]=i; 
        }

        char mov,temp;

        int j;
        for(int i=0;i<s.length();i++){
            if(s[i]>c[i]){
                
                for(j=0;j<26;j++){
                    if(freqs[j]>0 and lastloc[j]>i)
                    {
                        temp = j+65;
                        mov = s[i];
                        s[i]=temp;
                        break;
                    }
                }
                if(j!=26)
                    break;
            }
        }

        if(s>=c)
            cout<<"---\n";
        else{

            s[lastloc[j]]=mov;
            cout<<s<<endl;
        }
    }
}