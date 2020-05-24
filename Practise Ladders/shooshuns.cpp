#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,k;
    cin>>n>>k;

    int arr[n];


    for(int i=0;i<n;i++) cin>>arr[i];

    int pos = -1;

    int val = arr[n-1];

    for(int i=n-2;i>=0;i--){
        if(arr[i]!=val)
        {
            pos=i;
            break;
        }
    }

    if(pos>=k-1)
        cout<<-1<<endl;
    else
        cout<<pos+1<<endl;
}