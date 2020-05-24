#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    int n;

    cin>>n;

    map<int,ll> freqs;

    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;

        freqs[temp]++;
    }    

    int minele = freqs.begin()->first;
    int maxele = freqs.rbegin()->first;


    ll mincount = freqs.begin()->second;
    ll maxcount = freqs.rbegin()->second;

    ll prod = freqs.size()==1?(mincount*(mincount-1))/2:mincount*maxcount;

    cout<<maxele-minele<<" "<<prod<<endl;
}