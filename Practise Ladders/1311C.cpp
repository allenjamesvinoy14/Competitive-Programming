#include <bits/stdc++.h>
using namespace std;
 
int main(){
int t;
cin>>t;
while (t--){
int q,w;
string s;
cin>>q>>w>>s;
map<char,int>m;
vector<int>v(q,0);
for(int x=0;x<w;x++){
    int y;
    cin>>y;
    v[y-1]++;
}
int ans=0;
for(int x=s.size()-1;x>-1;x--){
    ans+=v[x];
    m[s[x]]+=ans+1;
}
for(char x='a';x<='z';x++)cout<<m[x]<<" ";
cout<<endl;
 
}
return 0;}