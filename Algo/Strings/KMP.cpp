#include<bits/stdc++.h>
using namespace std;

void kmp_preprocess(string pattern,vector<int> &reset){
    int i=0,j=-1;
    reset[0]=-1;

    while(i<pattern.size()){
        while(j>=0 and pattern[i]!=pattern[j]){
            j = reset[j];
        }
        i++;
        j++;
        reset[i] = j;
    }
}

void kmp_search(string s,string pat){
    vector<int> reset;
    kmp_preprocess(pat,reset);

    int i=0,j=0;

    while(i<s.size()){
        while(j>=0 and s[i]!=pat[j]){
            j = reset[j];
        }
    }

    i++;
    j++;

    if(j==pat.size()){
        cout<<"Pattern is found at "<<i-j<<endl;
        j = reset[j];
    }
}
int main(){
    
}