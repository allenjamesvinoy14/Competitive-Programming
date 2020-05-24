#include<bits/stdc++.h>
using namespace std;
const int prime = 3;

int hash_generate(string temp,int m){

    int hash_val = 0;

    for(int i=0;i<m;i++){
        hash_val+=(temp[i]*pow(prime,i));
    }
    return hash_val;
}
bool equal(string s,string pat,int m){
    for(int i=0;i<m;i++){
        if(s[i]!=pat[i]) return false;
    }
    return true;
}
int main(){

    string s;
    string pat;

    cin>>s;

    cin>>pat;

    int n = s.length();
    int m = pat.length();

    if(n<m){
        cout<<"Error: Pattern Matching not possible as string length is less than pattern length!";
        return 0;
    }

    int pat_hash = hash_generate(pat,m);
    
    int roll_hash = hash_generate(s.substr(0,m),m);

    if(roll_hash == pat_hash){
        if(equal(s.substr(0,m),pat,m)){
            cout<<0<<endl;
            return 0;
        }
    }

    for(int i = m;i<n;i++){
        roll_hash -= s[i-m];
        roll_hash /= prime;
        roll_hash += s[i]*pow(prime,m-1);

        if(roll_hash == pat_hash){
            if(equal(s.substr(i-m+1,m),pat,m)){
                cout<<i-m+1<<endl;
                return 0;
            }
        }
    }

    cout<<"No matches found!"<<endl;
}