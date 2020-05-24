#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,sx,sy,ex,ey;
    string s;

    cin>>n>>sx>>sy>>ex>>ey>>s;

    int i;

    int hd = ex-sx;
    int vd = ey-sy;

    char h='\0';
    char v='\0';

    if(hd<0)
        h = 'W';
    if(hd>0)
        h = 'E';
    if(vd<0)
        v = 'S';
    if(vd>0)
        v = 'N';

    cout<<hd<<" "<<vd<<" "<<h<<" "<<v<<endl;

    for(i=0;i<n;i++){
        if(s[i] == h)
        {
            if(h=='W')
                hd+=1;
            if(h=='E')
                hd+=-1;
        }
        if(s[i] == v)
            vd+=(v=='S')?1:-1;

        if(hd==0 and vd==0)
            break;
    }

    if(i>=n)
        cout<<-1<<endl;
    else
        cout<<i+1<<endl;
}