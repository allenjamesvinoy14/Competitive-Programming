#include<bits/stdc++.h>
using namespace std;

class kadane_result{

    public:
        int sum,up,down;

        kadane_result(int sum,int up,int down){
            this->sum = sum;
            this->up = up;
            this->down = down;
        }
};


int a[100][100];

kadane_result kadane_algo(int *arr,int n){

    int cursum = 0;
    int maxsum = 0;

    int l = -1;
    int r = -1;
    int cl = 0;

    for(int i = 0;i<n;i++){

        cursum += arr[i];

        if(cursum<0) {
            cursum = 0;
            cl = i+1;
        }

        if(cursum>maxsum){
            maxsum = cursum;
            l = cl;
            r = i;
        }
    }

    return kadane_result(maxsum,l,r);
    
}
int main(){

    int n,m; // n - row m - col

    cin>>n>>m;

    int maxsum = 0;
    int msup;
    int msdown;
    int msleft;
    int msright;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin>>a[i][j];
    }

    int temp[n];


    for(int i=0;i<m;i++){

        for(int j=0;j<n;j++){
            temp[j] = 0;
        }

        for(int j = i;j<m;j++){

            for(int k=0;k<n;k++){
                temp[k] += a[k][j];
            }

            kadane_result res = kadane_algo(temp,n);

            if(res.sum>maxsum){
                maxsum = res.sum;
                msup = res.up;
                msdown = res.down;
                msleft = i;
                msright = j;
            }
        }
    }

    cout<<endl;
    cout<<"maxsum is: "<<maxsum<<endl;
    cout<<"index row range is: "<<msup<<" - "<<msdown<<endl;
    cout<<"index col range is: "<<msleft<<" - "<<msright<<endl;
}