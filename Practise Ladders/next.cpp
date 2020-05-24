#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int> 

void generate(int l,int r){
    int n = to_string(l).length();
    int m = to_string(r).length();

    vector<char> nums;
    while(n<m)
    {
        for(int i=0;i<n;i++) nums.push_back('4');

        for(auto i: nums)
            cout<<i;
        cout<<endl;

        int limit = 1<<n;

        for(int i=1;i<limit;i++){
            vector<char> temp;
            temp = nums;

            for(int j=0;j<n;j++){
                if(1<<j & i)
                    temp[n-j-1]='7';
            }

            for(auto i: temp)
                cout<<i;
        }
        cout<<endl;
        nums.clear();
        n++;
    }
}
int main(){
    int l,r;
    cin>>l>>r;

    generate(l,r);
}