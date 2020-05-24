#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;

    cin>>n;

    int arr[2] = {0};
    int sum=0;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        sum+=temp;
        arr[temp==200?1:0]++;
    } 

    sum/=100;

    if(arr[1]&1 and arr[0]==0){
        cout<<"NO\n";
        return 0;
    }
    
    if(sum&1)
        cout<<"NO\n";
    else
        cout<<"YES\n";
}