#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;

    cin>>s;

    vector<set<int>> p(26);

    int n = s.length();

    for(int i=0;i<n;i++){
        p[s[i]-'a'].insert(i);
    }

    // for(auto i: p)
    // {
    //     for(auto j:i)
    //         cout<<j<<" ";

    //     cout<<endl;
    // }

    int q;
    cin>>q;

    while(q--){

        int t;
        cin>>t;

        if(t==1){
            int ps;
            char c;

            cin>>ps>>c;

            ps--;

            p[s[ps]-'a'].erase(ps);

            s[ps] = c;

            p[s[ps]-'a'].insert(ps);
        }
        else
        {
            int l,r;
            cin>>l>>r;

            l--;
            r--;

            int cnt = 0;

            for(int c=0;c<26;c++){

                auto it = p[c].lower_bound(l);

                if(it!=p[c].end() and *it<=r) cnt++;
            }   

            cout<<cnt<<endl;
        }
    }
}