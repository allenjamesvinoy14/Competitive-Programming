#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define vvi vector<vector<ll>>
#define MOD 1000000007
#define M 1000000007

void generate2(int n){
    int count  = n/2;

    for(int i=0;i<count;i++)
        cout<<1;
    
    cout<<endl;
}
void generate3(int n){
    int count  = n/3;

    for(int i=0;i<count;i++)
        cout<<7;
    
    cout<<endl;
}
void generatea(int n){
    int count  = (n-2)/3;

    for(int i=0;i<count;i++)
        cout<<7;
    
    cout<<1<<endl;
}
void generateb(int n){

    //cout<<"check2"<<endl;
    int count  = (n-4)/3;

    for(int i=0;i<count;i++)
        cout<<7;
    
    cout<<4<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        if(n%2==0)
        {
            generate2(n);
        }
        else if(n%3==0)
        {
            generate3(n);
        }
        else{
            //cout<<"check1"<<endl;
            if((n-2)%3==0)
                generatea(n);
            else if((n-4)%3==0)
                generateb(n);
        }
    }
}