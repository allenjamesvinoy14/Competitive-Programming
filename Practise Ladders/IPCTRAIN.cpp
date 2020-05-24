#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define MX 1<<17
#define pi pair<ll,ll>

int main(){

    vector<pi> pd[MX];

    int t;
    cin>>t;
    while(t--){
        int N,D;

        cin>>N>>D;

        for(ll i = 0;i<MX;i++)
            pd[i].clear();

        for(ll i = 0;i<N;i++){
            int a,b,c;

            cin>>a>>b>>c;

            pd[a].push_back(make_pair(c,b));
        }

        //cout<<"check 1"<<endl;

        priority_queue<pi> heap;

        for(ll i = 1;i<=D;i++){
            for(auto j : pd[i])
            {
                heap.push(j);
            }

            if(heap.size()!=0){
                pi f = heap.top();

                heap.pop();

                f.second = f.second-1;

                if(f.second!=0)
                    heap.push(f);
            }
        }        

        //cout<<"check 2"<<endl;

        ll s = heap.size();

        //cout<<s<<endl;

        ll count = 0;

        for(int i=0;i<s;i++){

            pi t = heap.top();

            heap.pop();

            //cout<<t.first<<" "<<t.second<<endl;
            count = count + (t.first*t.second);
        }

        //cout<<"check 3"<<endl;

        cout<<count<<endl;
    }
}