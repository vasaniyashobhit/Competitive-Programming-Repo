#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, vector<int> &vis, int node, int n, int m)
{
    vis[node] = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (vis[adj[node][i]] == 0)
        {
            dfs(adj, vis, adj[node][i], n, m);
        }
    }

    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<pair<int, int>> ans;
    int count = 0;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(adj, vis, i, n, m);
            if (i != 0)
            {
                count++;
                ans.push_back({0, i});
            }
        }
    }
    cout << count << endl;
    for (auto it : ans)
        cout << it.first + 1 << " " << it.second + 1 << endl;

    return 0;
}