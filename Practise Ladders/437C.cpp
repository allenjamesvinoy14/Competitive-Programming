#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define MAX_RANGE 10000007
#define BOOST ios_base::sync_with_stdio(0) 
#define NITRO cin.tie(NULL)
int parent[200007];
int size[200007];
int nexti[200007];
bool sortBySec(const pair<int,int>&a, const pair<int,int>&b)
{
	return (a.second<b.second);
}
int main()
{
	BOOST;
	NITRO;
	clock_t t1,t2;
	t1 = clock();
	/*
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	*/ 
	//Main Code
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>>cost;
	vector<int>wet(n+1);
	for(int i=1;i<=n;i++)
	{
		int w;
		cin>>w;
		wet[i]=w;
		cost.push_back(make_pair(i,w));
	}
	sort(cost.begin(),cost.end(),sortBySec);
	vector<vector<int>>Graph(n+1);
	bool visited[n+1] = {false};
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		Graph[a].push_back(b); //bidirectional graph
		Graph[b].push_back(a);
	}
	int ans = 0;
	for(int j=cost.size()-1;j>=0;j--)
	{
		if(visited[cost[j].first]==false)
		{
			for(int l=0;l<Graph[cost[j].first].size();l++)
			{
				if(visited[Graph[cost[j].first][l]]==false)
				{
					ans += wet[Graph[cost[j].first][l]];
				}
			}
			visited[cost[j].first]=true;
		}
	}
	cout<<ans<<"\n";
	t2 = clock();
	float diff = (float)t2 - (float)t1;
	float execution_time = diff/CLOCKS_PER_SEC;
	//cout<<"\n"<<execution_time;
	//system("pause");
}