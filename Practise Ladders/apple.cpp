#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007 

int main(){
    int n,k;
    cin>>n>>k;

    unordered_map<char,int> freqs;

    for(int i=0;i<n;i++){
        char c;
        cin>>c;

        freqs[c]++;
    }

    for(auto i:freqs)
        cout<<i.first<<" "<<i.second<<endl;
}
