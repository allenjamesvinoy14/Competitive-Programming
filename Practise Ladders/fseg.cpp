#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    if(n==1 or n==2){
        cout<<n;
        return 0;
    }

    int arr[n];

    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr,arr+n);

    int maxlen = 2;

    int l = 0;
    int r = 2;

    for(int i=2;i<n;i++)
    {
        if(arr[i] == arr[i-1] + arr[i-2]){
            maxlen = max(r-l+1,maxlen);
            r++;
        }
        else
        {
            r++;
            l++;
            if(r>=n)
                break;
        }
    }

    cout<<maxlen<<endl;
}