#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct node
{
	int src,dest;
	ll wght;
};

ll dis[105][105];
void floydWarshell(vector<node> g, int n)
{
	for(int i=0;i<g.size();++i)
	{
		dis[g[i].src][g[i].dest]=g[i].wght;
		dis[g[i].dest][g[i].src]=g[i].wght;
	}
	for(int k=0;k<n;++k)
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				if(dis[i][k]+dis[k][j]<dis[i][j])
					dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}
}

int main(){

    int n;
    cin>>n; // no of vertices


    for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				dis[i][j]=1000000000000000LL;
		
    for(int i=0;i<n;++i)
			dis[i][i]=0;
}