#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int q;
    cin>>q;
    
    while(q--){
        int arr[3];
        
        for(int i=0;i<3;i++){
            cin>>arr[i];
        }
        
        sort(arr,arr+3);
        
        if(arr[0] == arr[1] and arr[1] == arr[2])
            cout<<0<<endl;
        else
        {
            if(arr[0] == arr[1]){
                arr[2]--;
                if(arr[2] != arr[1])
                {
                    arr[1]++;
                    arr[0]++;
                }
            }
            else if(arr[1] == arr[2]){
                arr[1]--;
                arr[2]--;
                if(arr[1]!= arr[0])
                {
                    arr[0]++;
                }
            }
            else
            {
                arr[0]++;
                arr[2]--;
            }
            
            cout<<arr[1]-arr[0] + arr[2]-arr[0] + arr[2]-arr[1]<<endl;
        }
    }
}