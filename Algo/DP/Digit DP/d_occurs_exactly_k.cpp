// How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x?

#include<bits/stdc++.h>
using namespace std;

int dp[12][12][2];
vector<int> n;
int a,b,k,d;

int digitdp(int pos,int cnt,int e){

    if(cnt > k) return 0;

    if(pos == n.size()){
        if(cnt == k) return 1;
        return 0;
    }

    int &ans = dp[pos][cnt][e];

    if(ans != -1) return ans;

    int lmt;

    // e==0 implies we are on the edge of all the numbers we have seen till now

    if(e==0){
        lmt = n[pos];
    }
    else{
        lmt = 9;
    }

    int res = 0;

    for(int dgt=0;dgt<=lmt;dgt++){
        int ne = e;
        int ncnt = cnt;

        if(e==0 and dgt<lmt) ne = 1;

        if(dgt == d) ncnt++;

        if(ncnt<=k) res+=digitdp(pos+1,ncnt,ne);
    }

    return ans = res;

}

int solve(int num){

    n.clear();

    while(num){
        n.push_back(num%10);
        num/=10;
    }

    reverse(n.begin(),n.end());

    memset(dp,-1,sizeof dp);

    int res = digitdp(0,0,0);

    return res;

}

int main(){
    cin>>a>>b>>d>>k;

    cout<<solve(b)-solve(a-1)<<endl;
}