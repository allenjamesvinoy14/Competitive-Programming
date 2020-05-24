#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m;
    cin>>n>>m;
    
    string s[n];
    string t[m];
    
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<m;i++) cin>>t[i];
    
    int q;
    cin>>q;
    
    while(q--){
        int x;
        cin>>x;
        
        
        x--;
        
        int a = x%n;
        int b = x%m;
        
        cout<<s[a]<<t[b]<<endl;
    }
}