#include<bits/stdc++.h>
using namespace std;

bool ispossible(string s,int n){

    //cout<<"check"<<endl;

    unordered_map<char,int> freqs;

    for(int i=0;i<n;i++){
        freqs[s[i]]++;
    }

    int countodd = 0;
    int counteven = 0;

    for(auto i: freqs){
        if(i.second&1)
            countodd++;
        else
            counteven++;
    }
    
    if(n&1){
        if(countodd==1)
            return true;
    }
    else{
        if(countodd==0)
            return true;
    }

    return false;
}
int main(){

    string s;
    cin>>s;

    int n = s.length();

    if(ispossible(s,n))
    {
        cout<<"First"<<endl;
    }

    else
    {
        if(n&1)
            cout<<"First"<<endl;
        else
            cout<<"Second"<<endl;
    }   
}