//finding the missing element in an AP using binary search

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    int s,d;

    if((a[2]-a[0])/2==a[1]-a[0]){
        s = a[0];
        d = a[1] - a[0];
    }
    else
    {
        //figure the missing one and print it and return    
    }

    int l,r;

    l=0;
    r=n-1;

    while(l<r){
        int mid = (l+r)/2;

        if(a[mid+1]-a[mid-1]!=2*d){

            if(a[mid+1]-a[mid]!=d)
                cout<<a[mid]+d<<endl;
            else cout<<a[mid]-d<<endl;

            break;
        }
        else if(s+mid*d == a[mid])
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
        
    }
}