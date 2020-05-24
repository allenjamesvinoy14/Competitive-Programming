#include<bits/stdc++.h>
using namespace std;

bool boundary_check(int n,int m,int x,int y)
{
    if(x>=0 and x<n and y>=0 and y<m)
        return true;
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;

    char chess[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>chess[i][j];
        }
    }

    int x[] = {1,-1,0,0};
    int y[] = {0,0,1,-1};

    int fx[] = {1,1,2};
    int fy[] = {-1,1,0};

    bool swtch = true;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(chess[i][j]=='.')
            {
                bool flag = false; 

                for(int k=0;k<4;k++){
                    int xk = i+x[k];
                    int yk = j+y[k];

                    if(boundary_check(n,m,xk,yk))
                    {
                        if(chess[xk][yk]=='B')
                        {
                            chess[i][j] = 'W';

                            for(int p = 0;p<3;p++){
                                int xf = i+fx[p];
                                int yf = j+fx[p];

                                if(boundary_check(n,m,xf,yf) and chess[xf][yf]!='-')
                                {
                                    chess[xf][yf] = 'W';
                                }
                            }

                            flag = true;
                            break;
                        }
                        if(chess[xk][yk]=='W')
                        {
                            chess[i][j] = 'B';

                            for(int p = 0;p<3;p++){
                                int xf = i+fx[p];
                                int yf = j+fx[p];

                                if(boundary_check(n,m,xf,yf) and chess[xf][yf]!='-')
                                {
                                    chess[xf][yf] = 'B';
                                }
                            }

                            flag = true;
                            break;
                        }
                    }
                }

                if(flag == false)
                {
                    if(swtch)
                    {
                        chess[i][j] = 'B';
                        swtch = false;
                    }
                    else
                    {
                        chess[i][j] = 'W';  
                        swtch = true;
                    }
                }        
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<chess[i][j];
        }
        cout<<"\n";
    }
}