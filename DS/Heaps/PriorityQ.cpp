#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<pair<int,int>> pq;

    pq.push(make_pair(1,2));
    pq.push(make_pair(3,1));
    pq.push(make_pair(4,10));
    pq.push(make_pair(4,6));
    pq.push(make_pair(2,2));

    for(int i=0;i<5;i++){
        pair<int,int> p;
        p = pq.top();
        cout<<p.first<<" "<<p.second;
        pq.pop();
        cout<<endl; 
    }
}

// by default c++ creates a max-heap    