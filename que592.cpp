#include<bits/stdc++.h>
using namespace std;

int log = 20;

void dfs(int node, int parent, vector<vector<pair<int,int>>> &adj, vector<vector<pair<int,int>>> &dp, vector<int> &dep)
{
	dep[node] = dep[parent]+1;
	for(int i=0;i<adj[node].size();i++)
	{
		if(adj[node][i].first==parent) continue;
		dp[adj[node][i]][0].first = node;
		dp[adj[node][i]][0].second = dp[node][i].second;
		
		dfs(adj[node][i],node,adj,dp,dep);
	}

	return;
}

void calclca(vector<vector<pair<int,int>>> &dp)
{
	for(int i=0;i<log;i++)
	{
		for(int j=1;j<log;j++)
		{
			dp[i][j].first = dp[dp[i][j-1].first][j-1].first;
			dp[i][j].second = min(dp[dp[i][j-1].first][j-1].second,dp[i][]j-1].second); 
		}
	}

	return;
}

void findlca(int u, int v, vector<vector<pair<int,int>>> &dp, vector<int> &dep)
{
	int minans = 1e9;
	int x = dep[u];
	int y = dep[v];
	if(x>y) swap(x,y);
	int diff = y-x;
	for(int i=0;i<log;i++)
	{
		if((dep>>i)&1)
		{
			minans = min(minans,dp[y][i].second);
			y = dp[y][i].first;
		}
	}
	
	for(int i=0;i<log;i++)
	{
		if(x==y) break;
		if(dp[x][i].first != dp[y][i].first)
		{
			minans = min(minans,dp[x][i].second);
			minans = min(minans,dp[y][i].second);
			x = dp[x][i];
			y = dp[y][i];
		}
		
	}	
	return minans;
}

solve()
{
	int n,m; cin>>n>>m;
	vector<vector<pair<int,int>>> adj(n);
	for(int i=0;i<m;i++)
	{
		int u,v,w; cin>>u>>v>>w;
		u--;v--;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}

	vector<int> dep(n,-1);
	dep[0] = 1;
	vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,-1));

	dfs(0,-1,adj,dp);
	calclca();
	
	int q; cin>>q;
	
	while(q--)
	{
		int a,b; cin>>a>>b;
		a--,b--;
		int ans = findlca(a,b,dp)
		cout<<ans<<endl;
	}

	return;
}

int main()
{
        int t=1;
	while(t--) solve();

	return 0;
}