#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(int node, int p, vector<vector<int>> &adj, vector<int> &parent, map<pair<int, int>, int> &mp, vector<int> &round)
{
    //cout<<node<<"-"<<p<<" ";
    parent[node] = p;

    if(node==0){
        round[node] = 0;
    }
    else if (p == 0)
    {
        round[node] = 1;
    }
    else
    {
        if (mp[{node, p}] < mp[{p, parent[p]}])
        {
            round[node] = round[p] + 1;
        }
        else
        {
            round[node] = round[p];
        }
    }

    for (auto i : adj[node])
    {
        if (i == p)
            continue;
        else
        {
            dfs(i, node, adj, parent, mp, round);
        }
    }

    return;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);

        mp[{u, v}] = i;
        mp[{v, u}] = i;
    }

    vector<int> parent(n);
    vector<int> round(n, 0);
    parent[0] = -1;
    int m = 0;
    dfs(0, -1, adj, parent, mp, round);

    // for(auto it:round) cout<<it<<" ";
    // cout<<endl;

    for (int i = 0; i < n; i++)
    {
        m = max(m, round[i]);
    }
    cout << m << endl;

    return;
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}