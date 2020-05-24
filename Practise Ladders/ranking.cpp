#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int> 

bool compare(pi a, pi b){
    if(a.first > b.first)
        return true;
    else if(a.first == b.first and a.second < b.second)
        return true;
    else
        return false;
}

int main(){
    int n,k;

    cin>>n>>k;

	pi arr[n];

	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;

		arr[i] = make_pair(x,y);
	}

	sort(arr,arr+n,compare);

    pi ans = arr[k-1];
    
    int s,e = n-1;

    for(int i=0;i<n;i++){
        if(arr[i] == ans){
            s = i;
            break;
        }
    }

    for(int i=1;i<n;i++){
        if(arr[i-1]==ans and arr[i]!= ans)
        {
            e = i-1;
            break;
        }
    }
    
    cout<<e-s+1<<endl;
}