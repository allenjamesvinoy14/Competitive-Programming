#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define vvi vector<vector<ll>>
#define MOD 1000000007
#define M 1000000007

int main()
{
    int n;
    cin>>n;

    while(n--){
        int n,s,k;

        cin>>n>>s>>k;

        int arr[k];

        bool check = false;
        for(int i=0;i<k;i++){
            cin>>arr[i];

            if(arr[i] == s)
                check = true;
        }    

        if(check == false){
            cout<<0<<endl;
            continue;
        }

        sort(arr,arr+k);

        int idx;
        
        int dist[k];

        for(int i=0;i<k;i++){
            dist[i] = abs(arr[i]-s);

            if(dist[i]==0)
                idx = i;
        }

        int distance = INT_MAX;

        for(int i=idx-1;i>=0;i--){
            if(dist[i]!=(idx-i)){
                distance = abs(arr[i+1]-1-s);
                break;
            }
        }
        for(int i=idx+1;i<k;i++){
            if(dist[i]!=(i-idx)){
                distance = min(distance,abs(arr[i-1]+1-s));
                break;
            }
        }

        cout<<arr[k]<<" "<<arr[0]<<endl;

        if((arr[k]+1)!=(n+1))
            distance = min(distance,arr[k]+1-s);
        
        if((arr[0]-1)!=0)
            distance = min(distance,s-(arr[0]-1));

        cout<<distance<<endl;
    }
}