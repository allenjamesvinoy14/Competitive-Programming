#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int> 

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);

    long long int count = 0;

    for(int i=1;i<=n;i++){
        //cout<<arr[i-1]<<endl;
        count+=abs(i-arr[i-1]);
    }

    cout<<count<<endl;
}